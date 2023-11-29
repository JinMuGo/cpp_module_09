#pragma once
#ifndef NEXT_HPP
#define NEXT_HPP

#include <iterator>

template <class Iterator>
Iterator next(Iterator it, typename std::iterator_traits<Iterator>::difference_type n = 1) {
	std::advance(it, n);
	return it;
}

#endif
