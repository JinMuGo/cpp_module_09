#pragma once
#ifndef FJ_HPP
#define FJ_HPP

#include "group_iterator.hpp"

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
	VERBOSE_VAR(size);
	if (size < 2)
		return;
	const bool has_stray = (size % 2 != 0);

	// Group elements by pairs
	const GroupIterator end = has_stray ? ::prev(last) : last;
	VERBOSE_CONTAINER(typename GroupIterator::iterator_type, first.base(), end.base());
	for (GroupIterator it = first; it != end; it += 2) {
		VERBOSE_TWO_VARS(it[0], it[1]);
		if (compare(it[1], it[0]))
			::iter_swap(it, ::next(it));
	}

	VERBOSE("after swap");
	VERBOSE_CONTAINER(typename GroupIterator::iterator_type, first.base(), end.base());
	VERBOSE_VAR(*end);
	merge_insertion_sort_impl(make_group_iterator(first, 2), make_group_iterator(end, 2), compare);

	VERBOSE_VAR(size);
	VERBOSE("and first to end:");
	VERBOSE_CONTAINER(typename GroupIterator::iterator_type, first.base(), end.base());

	std::list<GroupIterator> chain;
	chain.push_back(first);
	chain.push_back(::next(first));

	VERBOSE_CONTAINER2(typename std::list<GroupIterator>::iterator, chain.begin(), chain.end());

	// Upper bounds for the insertion of pend elemtns
	std::vector<typename std::list<GroupIterator>::iterator> pend;
	pend.reserve((size + 1) / 2 - 1);
	for (GroupIterator it = first + 2; it != end; it += 2) {
		typename std::list<GroupIterator>::iterator tmp = chain.insert(chain.end(), ::next(it));
		pend.push_back(tmp);
	}

	VERBOSE_VAR(pend.size());

	if (has_stray)
		pend.push_back(chain.end());

	// Binary insertion into the main chain
	GroupIterator cur_it = first + 2;
	typename std::vector<typename std::list<GroupIterator>::iterator>::iterator cur_pend = pend.begin();

	for (int k = 0;; ++k) {
		typename std::list<GroupIterator>::difference_type dist = jacobsthal_diff[k];

		VERBOSE_TWO_VARS(dist, ::distance(cur_pend, pend.end()));
		if (dist > static_cast<typename std::list<GroupIterator>::difference_type>(::distance(cur_pend, pend.end())))
			break;

		// 재귀가 2씩 증가 하기 때문에 dist에 2를 곱해준다.이미 이전 recursive에서 정렬되었기 때문에.
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

	while (cur_pend != pend.end()) {
		typename std::list<GroupIterator>::iterator insertion_pos =
			std::upper_bound(chain.begin(), *cur_pend, *cur_it, myLess<Compare, GroupIterator>(compare));
		chain.insert(insertion_pos, cur_it);
		cur_it += 2;
		++cur_pend;
	}

	std::vector<typename std::iterator_traits<GroupIterator>::value_type> cache;
	cache.reserve(size);
	for (typename std::list<GroupIterator>::iterator it = chain.begin(); it != chain.end(); ++it) {
		typename GroupIterator::iterator_type begin = it->base();
		typename GroupIterator::iterator_type end = begin + it->size();
		cache.insert(cache.end(), begin, end);
	}

	VERBOSE_CONTAINER(typename std::vector<typename std::iterator_traits<GroupIterator>::value_type>::iterator,
					  cache.begin(), cache.end());
	typename GroupIterator::iterator_type dest = first.base();
	for (typename std::vector<typename std::iterator_traits<GroupIterator>::value_type>::iterator it = cache.begin();
		 it != cache.end(); ++dest, ++it) {
		*dest = *it;
	}

	VERBOSE_CONTAINER(typename GroupIterator::iterator_type, first.base(), end.base());
}

template <typename Iterator, typename Compare>
void merge_insertion_sort(Iterator first, Iterator last, Compare compare) {
	merge_insertion_sort_impl(make_group_iterator(first, 1), make_group_iterator(last, 1), compare);
}

#endif
