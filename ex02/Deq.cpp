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

Deq::Deq(const int ac, const char**& av) : std::deque<int>(ac - 1), AmyContainer() {
	VERBOSE(DEQ_DFLT_CTOR);
	for (int i = 1; i < ac; ++i) {
		this->operator[](i - 1) = std::atoi(av[i]);	 // (*this)
	}
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
	}
	return (*this);
}

void Deq::FJmergeInsertionsort() {
	merge_insertion_sort(this->begin(), this->end(), std::less<int>());
}

std::ostream& operator<<(std::ostream& os, const Deq& obj) {
	return os << " elements with " << std::left << std::setw(11) << "std::deque"
			  << " : " << obj.getElapsedTime() << "ms";
}
