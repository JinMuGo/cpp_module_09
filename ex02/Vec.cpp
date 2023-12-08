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
		this->_pairVec = obj._pairVec;
	}
	return (*this);
}

void Vec::sortEachPair(vecPairIter begin, const vecPairIter mid, vecPairIter end) {
	vecPair left(begin, mid + 1);
	vecPair right(mid + 1, end + 1);

	vecPairIter leftIter = left.begin();
	vecPairIter rightIter = right.begin();

	while (leftIter != left.end() && rightIter != right.end()) {
		if (leftIter->first <= rightIter->first)
			*begin++ = *leftIter++;
		else
			*begin++ = *rightIter++;
	}
	while (leftIter != left.end())
		*begin++ = *leftIter++;

	while (rightIter != right.end())
		*begin++ = *rightIter++;
}

void Vec::sortPair(const vecPairIter begin, const vecPairIter end) {
	if (begin >= end)
		return;
	const vecPairIter mid = begin + (std::distance(begin, end) / 2);
	this->sortPair(begin, mid);
	this->sortPair(mid + 1, end);
	this->sortEachPair(begin, mid, end);
}

void Vec::initMainChain(vecPair& src, std::vector<int>& dst) {
	dst.push_back(src.begin()->second);
	for (vecPairCiter it = src.begin(); it != src.end(); ++it) {
		dst.push_back(it->first);
	}
}

void Vec::FJmergeInsertionsort(const int ac, const char**& av) {
	Parser::_makeVecPair(this->_pairVec, ac, av);
	this->sortPair(this->_pairVec.begin(), this->_pairVec.end() - 1);
	this->initMainChain(this->_pairVec, *this);
	this->binaryInsertion(this->_pairVec, *this, Parser::_makeJacobSthalVec(ac / 2));
	if (ac % 2 == 0) {
		int targetVal = std::atoi(av[ac - 1]);
		this->insert(std::upper_bound(this->begin(), this->end(), targetVal), targetVal);
	}
}

void Vec::binaryInsertion(const vecPair& src, std::vector<int>& dst, const std::vector<int>& jacobSthal) {
	if (jacobSthal.size() == 0)
		return;
	int size = src.size();
	int cnt = 0;
	for (vecCIter cit = jacobSthal.begin() + 1; cit != jacobSthal.end(); ++cit) {
		int idx = *cit;
		while (idx > *(cit - 1)) {
			if (size <= idx - 1) {
				--idx;
				continue;
			}
			const int targetVal = src[idx - 1].second;
			const vecIter boundIt = dst.begin() + idx + cnt > dst.end() ? dst.end() : dst.begin() + idx + cnt;
			const vecIter insertIt = std::upper_bound(dst.begin(), boundIt, targetVal);
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
