/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:24:36 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 23:40:05 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const int& ac, const char**& av) : _ac(ac), _av(av), _vec(ac, av), _deq(ac, av) {
	VERBOSE(PMM_CTOR);
}

PmergeMe::PmergeMe(const PmergeMe& obj) : _ac(obj._ac), _av(obj._av), _vec(obj._vec), _deq(obj._deq) {
	VERBOSE(PMM_CPY_CTOR);
	*this = obj;
}

PmergeMe::~PmergeMe() {
	VERBOSE(PMM_DTOR);
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
	VERBOSE(PMM_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		const_cast<int&>(this->_ac) = obj._ac;
		const_cast<char**&>(this->_av) = const_cast<char**&>(obj._av);
		this->_deq = obj._deq;
		this->_vec = obj._vec;
	}
	return (*this);
}

void PmergeMe::vecSort(const int& ac, const char**& av) {
	VERBOSE(PMM_MEMBER_FUNC_CALL);
	const std::clock_t start = std::clock();
	this->_vec.FJmergeInsertionsort();
	const std::clock_t end = std::clock();
	this->_vec.setElapsedTime(end - start);
}

void PmergeMe::deqSort(const int& ac, const char**& av) {
	VERBOSE(PMM_MEMBER_FUNC_CALL);
	const std::clock_t start = std::clock(); 
	this->_deq.FJmergeInsertionsort();
	const std::clock_t end = std::clock();
	this->_deq.setElapsedTime(end - start);
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
