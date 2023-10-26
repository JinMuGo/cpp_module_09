/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:24:36 by jgo               #+#    #+#             */
/*   Updated: 2023/09/14 18:29:09 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const int ac, const char**& av) : _ac(ac), _av(av), _vec(), _deq(), _list(ac, av) {
	VERBOSE(PMM_DFLT_CTOR);
}

PmergeMe::PmergeMe(const PmergeMe& obj) : _ac(obj._ac), _av(obj._av), _vec(obj._vec), _deq(obj._deq), _list(obj._list) {
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

const Vec& PmergeMe::getVec(void) const {
	return this->_vec;
}
const Deq& PmergeMe::getDeq(void) const {
	return this->_deq;
}
const List& PmergeMe::getList(void) const {
	return this->_list;
}

void PmergeMe::alreadySorted() {
	int i = 1;
	for (std::list<int>::const_iterator cit = _list.begin(); i < _ac && cit != _list.end(); ++i, ++cit) {
		if (std::atoi(_av[i]) != *cit)
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

void PmergeMe::vecSort() {
	VERBOSE(PMM_MEMBER_FUNC_CALL);
	const std::clock_t start = getMsTime();
	this->_vec.FJmergeInsertionsort(_ac, _av);
	const std::clock_t end = getMsTime();
	this->_vec.setElapsedTime(end - start);
}

void PmergeMe::deqSort() {
	VERBOSE(PMM_MEMBER_FUNC_CALL);
	const std::clock_t start = getMsTime();
	this->_deq.FJmergeInsertionsort(_ac, _av);
	const std::clock_t end = getMsTime();
	this->_deq.setElapsedTime(end - start);
}

void PmergeMe::listSort() {
	VERBOSE(PMM_MEMBER_FUNC_CALL);
	const std::clock_t start = getMsTime();
	this->_list.FJmergeInsertionsort(_ac, _av);
	const std::clock_t end = getMsTime();
	this->_list.setElapsedTime(end - start);
}

void PmergeMe::confirmSort() const {
	int i = 0;
	for (std::list<int>::const_iterator cit = _list.begin(); i < _ac && cit != _list.end(); ++i, ++cit) {
		if (_deq[i] != *cit || _vec[i] != *cit) {
			std::cout << "index: " << i << " list: " << *cit << " deque: " << _deq[i] << " vector: " << _vec[i]
					  << std::endl;
			throw Error::error(INVALID_SORT, __func__, __FILE__, __LINE__);
		}
	}
}
