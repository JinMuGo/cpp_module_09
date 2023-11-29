#pragma once
#ifndef PREV_HPP
#define PREV_HPP

#include <iterator>

template <class Iterator>
Iterator prev(Iterator it, typename std::iterator_traits<Iterator>::difference_type n = 1) {
	std::advance(it, -n);
	return it;
}

#endif
