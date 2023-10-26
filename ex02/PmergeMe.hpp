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
	const int _ac;
	const char**& _av;
	Vec _vec;
	Deq _deq;
	List _list;

   public:
	PmergeMe(const int ac, const char**& av);
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& obj);

	void vecSort();
	void deqSort();
	void listSort();
	void checkAlreadySorted();
	void confirmSort() const;
	const Vec& getVec(void) const;
	const Deq& getDeq(void) const;
	const List& getList(void) const;

	static std::clock_t getMsTime(void);
};

#endif
