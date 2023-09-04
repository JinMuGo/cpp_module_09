/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:24:36 by jgo               #+#    #+#             */
/*   Updated: 2023/09/03 17:45:17 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _vec(), _deq(), _list() {
	VERBOSE(PMM_DFLT_CTOR);
}

PmergeMe::PmergeMe(const PmergeMe& obj) : _vec(obj._vec), _deq(obj._deq), _list(obj._list) {
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
		this->_list = obj._list;
	}
	return (*this);
}

void PmergeMe::alreadySorted(const int& ac, const char**& av) {
	int i = 1;
	for (std::list<int>::const_iterator cit = _list.begin(); i < ac && cit != _list.end(); ++i, ++cit) {
		if (std::atoi(av[i]) != *cit)
			return;
	}
	throw Error::error(ALREADY_SORTED, __func__, __FILE__, __LINE__);
}

std::clock_t PmergeMe::getMsTime(void) {
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}

void PmergeMe::vecSort(const int& ac, const char**& av) {
	VERBOSE(PMM_MEMBER_FUNC_CALL);

	const std::clock_t start = getMsTime();
	this->_vec.FJmergeInsertionsort(ac, av);
	const std::clock_t end = getMsTime();
	this->_vec.setElapsedTime(end - start);
}

void PmergeMe::deqSort(const int& ac, const char**& av) {
	VERBOSE(PMM_MEMBER_FUNC_CALL);
	const std::clock_t start = getMsTime();
	this->_deq.FJmergeInsertionsort(ac, av);
	const std::clock_t end = getMsTime();
	this->_deq.setElapsedTime(end - start);
}

void PmergeMe::listSort(const int& ac, const char**& av) {
	VERBOSE(PMM_MEMBER_FUNC_CALL);
	const std::clock_t start = getMsTime();
	this->_list.FJmergeInsertionsort(ac, av);
	const std::clock_t end = getMsTime();
	this->_list.setElapsedTime(end - start);
}

void PmergeMe::confirmSort(void) const {
	// 세개의 container(list, vector, deque)의 값이 같은지 확인. 같다면 before:, after출력
	// 다르다면 error throw
}

const Vec& PmergeMe::getVec(void) const {
	return this->_vec;
}
const Deq& PmergeMe::getDeq(void) const {
	return this->_deq;
}

const List& PmergeMe::getList(void) const {
	return this->_list;
}
