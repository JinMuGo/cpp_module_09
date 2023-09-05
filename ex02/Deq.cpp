/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:23:10 by jgo               #+#    #+#             */
/*   Updated: 2023/09/05 18:26:47 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Deq.hpp"

Deq::Deq() : std::deque<int>(), AmyContainer() {
	VERBOSE(DEQ_DFLT_CTOR);
}

Deq::Deq(const Deq& obj) : std::deque<int>(), AmyContainer(obj) {
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
		this->_tmp = obj._tmp;
	}
	return (*this);
}

void Deq::FJmergeInsertionsort(const int& ac, const char**& av, const Parser& parser) {
	Parser::_ParseDeq(this->_tmp, ac, av);
	this->sortPair<deqPair, deqPairIter>(this->_tmp);
	this->initMainChain(this->_tmp, *this);
	this->mergeInsertion<deqPair, std::deque<int> >(this->_tmp, *this, parser.getJacobsthal());
}

template <typename srcCont, typename dstCont>
void Deq::mergeInsertion(const srcCont& src, dstCont& dst, const std::vector<int>& jacobSthal) {
	int cnt = 0;
	for (std::vector<int>::const_iterator cit = jacobSthal.begin() + 1; cit != jacobSthal.end(); ++cit) {
		for (int idx = *cit; idx > *(cit - 1); --idx, ++cnt) {
			if (idx > static_cast<int>(src.size()))
				idx = static_cast<int>(src.size());
			const int targetVal = src[idx - 1].second;
			const typename dstCont::iterator insertIt = std::upper_bound(
				dst.begin(), (dst.begin() + (idx + cnt) > dst.end()) ? dst.end() : dst.begin() + (idx + cnt),
				targetVal);
			dst.insert(insertIt, targetVal);
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Deq& obj) {
	return os << " elements with " << std::left << std::setw(11) << "std::deque"
			  << " : " << obj.getElapsedTime() << "ms";
}
