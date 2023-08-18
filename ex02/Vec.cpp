/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:50 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 17:59:18 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec.hpp"

Vec::Vec(const Vec& obj) : std::vector<int>(obj), AmyContainer(obj) {
	VERBOSE(VEC_CPY_CTOR);
}

Vec::Vec(const int& ac, const char**& av) : std::vector<int>(), AmyContainer(ac, av) {
	VERBOSE(VEC_CTOR);
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

void Vec::FJmergeInsertionsort(const int& ac, const char**& av) {
	Parser::_ParseVec(*this, ac, av);
}

std::ostream& operator<<(std::ostream& os, const Vec& obj) {
	return os << "Time to process a range of " << obj.getAc() - 1 << " elements with " << std::left << std::setw(11)
			  << "std::vector"
			  << " : " << obj.getElapsedTime() << "ms";
}
