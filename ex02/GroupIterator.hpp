#pragma once
#ifndef GROUP_ITERATOR_HPP
#define GROUP_ITERATOR_HPP

#include "GroupIterator.h"

template <typename Iterator>
class GroupIterator {
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

	// OCF
	GroupIterator(Iterator it, std::size_t size) : _it(it), _size(size){};

	GroupIterator(const GroupIterator& obj) : _it(obj._it), _size(obj._size){};

	GroupIterator operator=(const GroupIterator& obj) {
		if (this == &obj)
			return *this;
		_it = obj._it;
		_size = obj._size;
		return *this;
	};

	~GroupIterator(){};

	// Member access
	iterator_type base() const { return _it; }
	std::size_t size() const { return _size; }

	// Element access
	reference operator*() const { return *::next(_it, _size - 1); }

	pointer operator->() const { return &(operator*()); }

	// Increment and decrement operators

	GroupIterator& operator++() {
		std::advance(_it, _size);
		return *this;
	}

	GroupIterator operator++(int) {
		GroupIterator tmp(*this);
		operator++();
		return tmp;
	}

	GroupIterator& operator--() {
		std::advance(_it, -_size);
		return *this;
	}

	GroupIterator operator--(int) {
		GroupIterator tmp(*this);
		operator--();
		return tmp;
	}

	GroupIterator& operator+=(difference_type n) {
		_it += _size * n;
		return *this;
	}

	GroupIterator& operator-=(difference_type n) {
		_it -= _size * n;
		return *this;
	}

	// Element access operators

	reference operator[](difference_type pos) const { return _it[pos * _size + _size - 1]; }
};
// Comparison operators

template <typename Iterator1, typename Iterator2>
bool operator==(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base() == rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator!=(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base() != rhs.base();
}

// Relational operators

template <typename Iterator1, typename Iterator2>
bool operator<(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base() < rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator<=(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base() <= rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator>(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base() > rhs.base();
}

template <typename Iterator1, typename Iterator2>
bool operator>=(const GroupIterator<Iterator1>& lhs, const GroupIterator<Iterator2>& rhs) {
	return lhs.base() >= rhs.base();
}

// arithmetic operators

template <typename Iterator>
GroupIterator<Iterator> operator+(GroupIterator<Iterator> it, std::size_t size) {
	it += size;
	return it;
}

template <typename Iterator>
GroupIterator<Iterator> operator+(std::size_t size, GroupIterator<Iterator> it) {
	it += size;
	return it;
}

template <typename Iterator>
GroupIterator<Iterator> operator-(GroupIterator<Iterator> it, std::size_t size) {
	it -= size;
	return it;
}

template <typename Iterator>
typename GroupIterator<Iterator>::difference_type operator-(const GroupIterator<Iterator>& lhs,
															const GroupIterator<Iterator>& rhs) {
	return (lhs.base() - rhs.base()) / lhs.size();
}

// iter_swap
template <typename Iterator>
void iter_swap(GroupIterator<Iterator> lhs, GroupIterator<Iterator> rhs) {
	std::swap_ranges(lhs.base(), ::next(lhs.base(), lhs.size()), rhs.base());
}

// convenience functions

template <typename Iterator>
GroupIterator<Iterator> make_group_iterator(Iterator it, std::size_t size) {
	return GroupIterator<Iterator>(it, size);
}

template <typename Iterator>
GroupIterator<Iterator> make_group_iterator(GroupIterator<Iterator> it, std::size_t size) {
	size *= it.size();
	return GroupIterator<Iterator>(it.base(), size);
}

#endif
