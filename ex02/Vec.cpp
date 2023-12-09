/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:50 by jgo               #+#    #+#             */
/*   Updated: 2023/09/12 08:48:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec.hpp"

Vec::Vec(const int ac, const char**& av) : std::vector<int>(), AmyContainer() {
	this->reserve(ac - 1);
	VERBOSE(VEC_DFLT_CTOR);
	for (int i = 1; i < ac; ++i) {
		this->operator[](i - 1) = std::atoi(av[i]);	 // (*this)
	}
}

Vec::Vec(const Vec& obj) : std::vector<int>(obj), AmyContainer(obj) {
	VERBOSE(VEC_CPY_CTOR);
}

Vec::~Vec() {
	VERBOSE(VEC_DTOR);
}

Vec& Vec::operator=(const Vec& obj) {
	VERBOSE(VEC_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		this->std::vector<int>::operator=(obj);
		this->AmyContainer::operator=(obj);
	}
	return (*this);
}

void Vec::FJmergeInsertionsort() {
	merge_insertion_sort(this->begin(), this->end(), std::less<int>());
}

std::ostream& operator<<(std::ostream& os, const Vec& obj) {
	return os << " elements with " << std::left << std::setw(11) << "std::vector"
			  << " : " << obj.getElapsedTime() << "ms";
}
