/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:23:10 by jgo               #+#    #+#             */
/*   Updated: 2023/09/04 11:44:27 by jgo              ###   ########.fr       */
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

void Deq::FJmergeInsertionsort(const int& ac, const char**& av) {
	Parser::_ParseDeq(this->_tmp, this->_last, ac, av);
	this->sortPair<deqPair, deqPairIter>(this->_tmp);
}

std::ostream& operator<<(std::ostream& os, const Deq& obj) {
	return os << " elements with " << std::left << std::setw(11) << "std::deque"
			  << " : " << obj.getElapsedTime() << "ms";
}
