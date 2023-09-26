/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:24:38 by jgo               #+#    #+#             */
/*   Updated: 2023/09/14 18:28:10 by jgo              ###   ########.fr       */
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
	PmergeMe(const int ac, const char**& av);
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& obj);

	void vecSort(const int& ac, const char**& av);
	void deqSort(const int& ac, const char**& av);
	void listSort(const int& ac, const char**& av);
	void alreadySorted(const int& ac, const char**& av);
	void confirmSort(const int& ac) const;
	const Vec& getVec(void) const;
	const Deq& getDeq(void) const;
	const List& getList(void) const;

	static std::clock_t getMsTime(void);
};

#endif
