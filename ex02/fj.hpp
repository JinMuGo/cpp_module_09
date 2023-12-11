#pragma once
#ifndef FJ_HPP
#define FJ_HPP

#include "GroupIterator.hpp"

// unsigned long	4	unsigned long int	0 ~ 4,294,967,295
const static std::size_t jacobsthal_diff[] = {
	2u,		   2u,		  6u,		 10u,		 22u,		 42u,		 86u,		  170u,
	342u,	   682u,	  1366u,	 2730u,		 5462u,		 10922u,	 21846u,	  43690u,
	87382u,	   174762u,	  349526u,	 699050u,	 1398102u,	 2796202u,	 5592406u,	  11184810u,
	22369622u, 44739242u, 89478486u, 178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u};

template <typename Compare, typename GroupIterator>
struct myLess {
	Compare _compare;
	myLess(Compare& compare) : _compare(compare) {}

	bool operator()(const int& lhs, const GroupIterator& rhs) const { return (_compare(lhs, *rhs)); }

	bool operator()(const GroupIterator& lhs, const GroupIterator& rhs) const { return (_compare(*lhs, *rhs)); }
};

// Merge-insertion sort
template <typename GroupIterator, typename Compare>
void merge_insertion_sort_impl(GroupIterator first, GroupIterator last, Compare compare) {
	typename std::iterator_traits<GroupIterator>::difference_type size = last - first;
	if (size < 2)
		return;
	const bool has_stray = (size % 2 != 0);

	// Group elements by pairs
	const GroupIterator end = has_stray ? ::prev(last) : last;
	for (GroupIterator it = first; it != end; it += 2) {
		if (compare(it[1], it[0]))
			::iter_swap(it, ::next(it));
	}

	merge_insertion_sort_impl(make_group_iterator(first, 2), make_group_iterator(end, 2), compare);

	std::list<GroupIterator> chain;
	chain.push_back(first);
	chain.push_back(::next(first));

	// Upper bounds for the insertion of pend elemtns
	std::vector<typename std::list<GroupIterator>::iterator> pend;
	pend.reserve((size + 1) / 2 - 1);
	for (GroupIterator it = first + 2; it != end; it += 2) {
		typename std::list<GroupIterator>::iterator tmp = chain.insert(chain.end(), ::next(it));
		pend.push_back(tmp);
	}

	if (has_stray)
		pend.push_back(chain.end());

	// Binary insertion into the main chain
	GroupIterator cur_it = first + 2;
	typename std::vector<typename std::list<GroupIterator>::iterator>::iterator cur_pend = pend.begin();

	for (int k = 0;; ++k) {
		typename std::list<GroupIterator>::difference_type dist = jacobsthal_diff[k];

		if (dist > static_cast<typename std::list<GroupIterator>::difference_type>(::distance(cur_pend, pend.end())))
			break;

		// pend와 main chain의 끝으로 이동하기 위해 cur_it을 dist * 2만큼 이동 (왜냐하면 cur_it는 main chain의 jacob stahal diff의 시작 점이기 때문)
		// pend는 이전에 main chain에 삽입된 groupIterator들의 위치를 가리키고 있기 때문에 dist만큼 이동하면 된다.
		// next를 하는 이유는 do while문을 사용하여 먼저 한번 수행하기 위해서이다.
		GroupIterator it = ::next(cur_it, dist * 2);
		typename std::vector<typename std::list<GroupIterator>::iterator>::iterator pe = ::next(cur_pend, dist);

		do {
			--pe;
			it -= 2;

			typename std::list<GroupIterator>::iterator insertion_pos =
				std::upper_bound(chain.begin(), *pe, *it, myLess<Compare, GroupIterator>(compare));
			chain.insert(insertion_pos, it);
		} while (pe != cur_pend);

		std::advance(cur_it, dist * 2);
		std::advance(cur_pend, dist);
	}

	// 이전 jacobsthal diff에서 pend에 남은 요소들을 binary insertion로 넣는 과정.
	while (cur_pend != pend.end()) {
		typename std::list<GroupIterator>::iterator insertion_pos =
			std::upper_bound(chain.begin(), *cur_pend, *cur_it, myLess<Compare, GroupIterator>(compare));
		chain.insert(insertion_pos, cur_it);
		cur_it += 2;
		++cur_pend;
	}

	// 이번 recursion에서의 main chain을 cache에 저장 하는 과정. (이전 recursion에서는 현재 size / 2만큼의 요소가 있었고, 이번 recursion에서는 size만큼의 요소가 있기 때문에 size만큼의 cache를 만들어야 한다.)
	std::vector<typename std::iterator_traits<GroupIterator>::value_type> cache;
	cache.reserve(size);
	for (typename std::list<GroupIterator>::iterator it = chain.begin(); it != chain.end(); ++it) {
		typename GroupIterator::iterator_type begin = it->base();
		typename GroupIterator::iterator_type end = begin + it->size();
		cache.insert(cache.end(), begin, end);
	}

	typename GroupIterator::iterator_type dest = first.base();
	for (typename std::vector<typename std::iterator_traits<GroupIterator>::value_type>::iterator it = cache.begin();
		 it != cache.end(); ++dest, ++it) {
		*dest = *it;
	}
}

template <typename Iterator, typename Compare>
void merge_insertion_sort(Iterator first, Iterator last, Compare compare) {
	merge_insertion_sort_impl(make_group_iterator(first, 1), make_group_iterator(last, 1), compare);
}

#endif
