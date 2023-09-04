/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:50 by jgo               #+#    #+#             */
/*   Updated: 2023/09/04 11:37:52 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec.hpp"

Vec::Vec() : std::vector<int>(), AmyContainer() {
	VERBOSE(VEC_DFLT_CTOR);
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
		this->_tmp = obj._tmp;
	}
	return (*this);
}

void Vec::FJmergeInsertionsort(const int& ac, const char**& av) {
	Parser::_ParseVec(this->_tmp, this->_last, ac, av);
	this->sortPair<vecPair, vecPairIter>(this->_tmp);
}

std::ostream& operator<<(std::ostream& os, const Vec& obj) {
	return os << " elements with " << std::left << std::setw(11) << "std::vector"
			  << " : " << obj.getElapsedTime() << "ms";
}
