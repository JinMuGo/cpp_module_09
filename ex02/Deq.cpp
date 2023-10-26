/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:23:10 by jgo               #+#    #+#             */
/*   Updated: 2023/09/14 18:29:43 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Deq.hpp"

Deq::Deq() : std::deque<int>(), AmyContainer() {
	VERBOSE(DEQ_DFLT_CTOR);
}

Deq::Deq(const Deq& obj) : std::deque<int>(obj), AmyContainer(obj) {
	VERBOSE(DEQ_CPY_CTOR);
}

Deq::~Deq() {
	VERBOSE(DEQ_DTOR);
}

Deq& Deq::operator=(const Deq& obj) {
	VERBOSE(DEQ_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		this->std::deque<int>::operator=(obj);
		this->AmyContainer::operator=(obj);
		this->_pairDeq = obj._pairDeq;
	}
	return (*this);
}

void Deq::initMainChain(deqPair& src, std::deque<int>& dst) {
	dst.push_back(src.begin()->second);
	for (deqPairCiter it = src.begin(); it != src.end(); ++it) {
		dst.push_back(it->first);
		if (it->second == -1)
			src.erase(it);
	}
}

void Deq::sortEachPair(deqPairIter begin, const deqPairIter mid, deqPairIter end) {
	deqPair left(begin, mid + 1);
	deqPair right(mid + 1, end + 1);

	deqPairIter leftIter = left.begin();
	deqPairIter rightIter = right.begin();

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

void Deq::sortPair(const deqPairIter begin, const deqPairIter end) {
	if (begin >= end)
		return;
	const deqPairIter mid = begin + (std::distance(begin, end) / 2);
	this->sortPair(begin, mid);
	this->sortPair(mid + 1, end);
	this->sortEachPair(begin, mid, end);
}

void Deq::FJmergeInsertionsort(const int ac, const char**& av) {
	Parser::_makeDeqPair(this->_pairDeq, ac, av);
	this->sortPair(this->_pairDeq.begin(), this->_pairDeq.end() - 1);
	this->initMainChain(this->_pairDeq, *this);
	this->binaryInsertion(this->_pairDeq, *this, Parser::_makeJacobSthalVec(ac / 2));
}

void Deq::binaryInsertion(const deqPair& src, std::deque<int>& dst, const std::vector<int>& jacobSthal) {
	if (jacobSthal.size() == 0)
		return;
	int cnt = 0;
	for (vecCIter cit = jacobSthal.begin() + 1; cit != jacobSthal.end(); ++cit) {
		int idx = *cit;
		while (idx > *(cit - 1)) {
			const int targetVal = src[idx - 1].second;
			const deqIter boundIt = dst.begin() + idx + cnt > dst.end() ? dst.end() : dst.begin() + idx + cnt;
			const deqIter insertIt = std::upper_bound(dst.begin(), boundIt, targetVal);
			dst.insert(insertIt, targetVal);
			--idx;
			++cnt;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Deq& obj) {
	return os << " elements with " << std::left << std::setw(11) << "std::deque"
			  << " : " << obj.getElapsedTime() << "ms";
}
