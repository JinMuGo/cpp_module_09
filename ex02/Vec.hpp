/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:21:39 by jgo               #+#    #+#             */
/*   Updated: 2023/09/06 19:42:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_HPP
#define VEC_HPP

#include "Vec.h"

class Vec : public std::vector<int>, public AmyContainer {
   private:
	std::vector<std::pair<int, int> > _pairVec;
	void binaryInsertion(const vecPair& pend, std::vector<int>& main, const std::vector<int>& jacobSthal);
	void sortPair(const vecPairIter begin, const vecPairIter end);
	void sortEachPair(vecPairIter begin, const vecPairIter mid, vecPairIter end);
	void initMainChain(vecPair& src, std::vector<int>& dst);

   public:
	Vec();
	Vec(const Vec& obj);
	virtual ~Vec();
	Vec& operator=(const Vec& obj);
	virtual void FJmergeInsertionsort(const int ac, const char**& av);
};

std::ostream& operator<<(std::ostream& os, const Vec& obj);

#endif
