/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:50 by jgo               #+#    #+#             */
/*   Updated: 2023/09/06 19:52:37 by jgo              ###   ########.fr       */
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

void Vec::FJmergeInsertionsort(const int& ac, const char**& av, const Parser& parser) {
	Parser::_ParseVec(this->_tmp, ac, av);
	this->sortPair<vecPair, vecPairIter>(this->_tmp);
	this->initMainChain(this->_tmp, *this);
	this->mergeInsertion(this->_tmp, *this, parser.getJacobsthal());
}

void Vec::mergeInsertion(const vecPair& src, std::vector<int>& dst, const std::vector<int>& jacobSthal) {
	int cnt = 0;
	for (vecCIter cit = jacobSthal.begin() + 1; cit != jacobSthal.end(); ++cit) {
		int idx = *cit > static_cast<int>(src.size()) ? static_cast<int>(src.size()) : *cit;
		while (idx > *(cit - 1)) {
			const int targetVal = src[idx - 1].second;
			const vecIter boundIt = dst.begin() + idx + cnt > dst.end() ? dst.end() : dst.begin() + idx + cnt;
			const vecIter insertIt = std::upper_bound(dst.begin(), boundIt,targetVal);
			dst.insert(insertIt, targetVal);
			--idx;
			++cnt;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Vec& obj) {
	return os << " elements with " << std::left << std::setw(11) << "std::vector"
			  << " : " << obj.getElapsedTime() << "ms";
}
