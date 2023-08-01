/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:50 by jgo               #+#    #+#             */
/*   Updated: 2023/08/01 10:24:51 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec.hpp"

Vec::Vec(const Vec& obj) : std::vector<int>(obj), ImyContainer(obj) {
	VERBOSE(VEC_CPY_CTOR);
}

Vec::Vec(const int& ac, const char**& av) : std::vector<int>(), ImyContainer(ac, av) {
	VERBOSE(VEC_CTOR);
}

Vec::~Vec() {
	VERBOSE(VEC_DTOR);
}

Vec& Vec::operator=(const Vec& obj) {
	VERBOSE(VEC_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		this->std::vector<int>::operator=(obj);
		this->ImyContainer::operator=(obj);
	}
	return (*this);
}

void Vec::FJmergeInsertionsort() {
	Parser::_ParseVec(*this, this->getAc(), this->getAv());
	
}

std::ostream& operator<<(std::ostream& os, const Vec& obj) {
	return os << "Time to process a range of " << obj.getAc() - 1
			  << " elements with std::vector : " << obj.getElapsedTime() << "ms" << std::endl;
}
