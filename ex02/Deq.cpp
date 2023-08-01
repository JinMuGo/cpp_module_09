/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:23:10 by jgo               #+#    #+#             */
/*   Updated: 2023/08/01 12:45:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Deq.hpp"

Deq::Deq(const Deq& obj) : std::deque<int>(), AmyContainer(obj) {
	VERBOSE(DEQ_CPY_CTOR);
}

Deq::Deq(const int& ac, const char**& av) : std::deque<int>(), AmyContainer(ac, av) {
	VERBOSE(DEQ_CTOR);
}

Deq::~Deq() {
	VERBOSE(DEQ_DTOR);
}

Deq& Deq::operator=(const Deq& obj) {
	VERBOSE(DEQ_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		this->std::deque<int>::operator=(obj);
		this->AmyContainer::operator=(obj);
	}
	return (*this);
}

void Deq::FJmergeInsertionsort(const int& ac, const char**& av) {
	Parser::_ParseDeq(*this, ac, av);
}

std::ostream& operator<<(std::ostream& os, const Deq& obj) {
	return os << "Time to process a range of " << obj.getAc() - 1
			  << " elements with std::deque : " << obj.getElapsedTime() << "ms" << std::endl;
}
