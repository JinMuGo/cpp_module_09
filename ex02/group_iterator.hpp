#pragma once
#ifndef GROUP_ITERATOR_HPP
#define GROUP_ITERATOR_HPP

#include "group_iterator.h"

template <typename Iterator>
class group_iterator {
   private:
	Iterator _it;
	std::size_t _size;

   public:
	typedef std::random_access_iterator_tag iterator_category;
	typedef Iterator iterator_type;
	typedef typename std::iterator_traits<Iterator>::value_type value_type;
	typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
	typedef typename std::iterator_traits<Iterator>::pointer pointer;
	typedef typename std::iterator_traits<Iterator>::reference reference;

	group_iterator(){};
	group_iterator(Iterator it, std::size_t size) : _it(it), _size(size){};

	// Member access
	iterator_type base() const { return _it; }
	std::size_t size() const { return _size; }

	// Element access
	reference operator*() const { return *::next(_it, _size - 1); }

	pointer operator->() const { return &(operator*()); }

	// Increment and decrement operators

	group_iterator& operator++() {
		std::advance(_it, _size);
		return *this;
	}

	group_iterator operator++(int) {
		group_iterator tmp(*this);
		operator++();
		return tmp;
	}

	group_iterator& operator--() {
		std::advance(_it, -_size);
		return *this;
	}

	group_iterator operator--(int) {
		group_iterator tmp(*this);
		operator--();
		return tmp;
	}

	group_iterator& operator+=(difference_type n) {
		_it += _size * n;
		return *this;
	}

	group_iterator& operator-=(difference_type n) {
		_it -= _size * n;
		return *this;
	}

	// Element access operators

	reference operator[](difference_type pos) const { return _it[pos * _size + _size - 1]; }

	~group_iterator(){};
};
// Comparison operators

template <typename Iterator1, typename Iterator2>
bool operator==(const group_iterator<Iterator1>& lhs, const group_iterator<Iterator2>& rhs) {
	return lhs.base() == rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator!=(const group_iterator<Iterator1>& lhs, const group_iterator<Iterator2>& rhs) {
	return lhs.base() != rhs.base();
}

// Relational operators

template <typename Iterator1, typename Iterator2>
bool operator<(const group_iterator<Iterator1>& lhs, const group_iterator<Iterator2>& rhs) {
	return lhs.base() < rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator<=(const group_iterator<Iterator1>& lhs, const group_iterator<Iterator2>& rhs) {
	return lhs.base() <= rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator>(const group_iterator<Iterator1>& lhs, const group_iterator<Iterator2>& rhs) {
	return lhs.base() > rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator>=(const group_iterator<Iterator1>& lhs, const group_iterator<Iterator2>& rhs) {
	return lhs.base() >= rhs.base();
}

// arithmetic operators

template <typename Iterator>
group_iterator<Iterator> operator+(group_iterator<Iterator> it, std::size_t size) {
	it += size;
	return it;
}

template <typename Iterator>
group_iterator<Iterator> operator+(std::size_t size, group_iterator<Iterator> it) {
	it += size;
	return it;
}

template <typename Iterator>
group_iterator<Iterator> operator-(group_iterator<Iterator> it, std::size_t size) {
	it -= size;
	return it;
}

template <typename Iterator>
typename group_iterator<Iterator>::difference_type operator-(const group_iterator<Iterator>& lhs,
															 const group_iterator<Iterator>& rhs) {
	return (lhs.base() - rhs.base()) / lhs.size();
}

// iter_swap
template <typename Iterator>
void iter_swap(group_iterator<Iterator> lhs, group_iterator<Iterator> rhs) {
	std::swap_ranges(lhs.base(), ::next(lhs.base(), lhs.size()), rhs.base());
}

// convenience functions

template <typename Iterator>
group_iterator<Iterator> make_group_iterator(Iterator it, std::size_t size) {
	return group_iterator<Iterator>(it, size);
}

template <typename Iterator>
group_iterator<Iterator> make_group_iterator(group_iterator<Iterator> it, std::size_t size) {
	size *= it.size();
	return group_iterator<Iterator>(it.base(), size);
}

#endif
