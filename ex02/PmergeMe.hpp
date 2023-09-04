/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:24:38 by jgo               #+#    #+#             */
/*   Updated: 2023/09/03 17:45:03 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "PmergeMe.h"

class PmergeMe {
   private:
	Vec _vec;
	Deq _deq;
	List _list;

   public:
	PmergeMe();
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& obj);

	void vecSort(const int& ac, const char**& av);
	void deqSort(const int& ac, const char**& av);
	void listSort(const int& ac, const char**& av);
	void alreadySorted(const int& ac, const char**& av);
	void confirmSort(void) const;
	const Vec& getVec(void) const;
	const Deq& getDeq(void) const;
	const List& getList(void) const;
	int getAc(void) const;
	const char** getAv(void) const;

	static std::clock_t getMsTime(void);
};

#endif
