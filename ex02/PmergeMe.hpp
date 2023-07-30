/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:24:38 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 18:22:28 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "PmergeMe.h"

class PmergeMe {
   private:
   	const int &_ac;
   	const char **&_av;
	Vec _vec;
	Deq _deq;

   public:
	PmergeMe();
	PmergeMe(const int &ac, const char **&av);
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& obj);

	void vecSort(const int& ac, const char **&av);
	void deqSort(const int& ac, const char **&av);
	bool confirmSort(void) const;
	const Vec& getVec(void) const;
	const Deq& getDeq(void) const;
};

#endif
