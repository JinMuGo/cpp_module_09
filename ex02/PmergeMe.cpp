/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:24:36 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 18:22:43 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	VERBOSE(PMM_DFLT_CTOR);
}

PmergeMe::PmergeMe(const int& ac, const char**& av) : _ac(ac), _av(av) {
	VERBOSE(PPM_CTOR);
}

PmergeMe::PmergeMe(const PmergeMe& obj) {
	VERBOSE(PMM_CPY_CTOR);
	*this = obj;
}

PmergeMe::~PmergeMe() {
	VERBOSE(PMM_DTOR);
}
PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
	VERBOSE(PMM_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		this->_deq = obj._deq;
		this->_vec = obj._vec;
	}
	return (*this);
}

void PmergeMe::vecSort(const int& ac, const char**& av) {
	VERBOSE(PMM_MEMBER_FUNC_CALL);
}

void PmergeMe::deqSort(const int& ac, const char**& av) {
	VERBOSE(PMM_MEMBER_FUNC_CALL);
}

bool PmergeMe::confirmSort(void) const {
	// 두개의 container의 값이 같은지 확인. 같다면 true; 아니면 false;
}

const Vec& PmergeMe::getVec(void) const {
	return this->_vec;
}
const Deq& PmergeMe::getDeq(void) const {
	return this->_deq;
}
