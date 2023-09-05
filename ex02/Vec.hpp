/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:21:39 by jgo               #+#    #+#             */
/*   Updated: 2023/09/05 17:37:48 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_HPP
#define VEC_HPP

#include "Vec.h"

class Vec : public std::vector<int>, public AmyContainer {
   private:
	std::vector<std::pair<int, int> > _tmp;

	typedef std::vector<std::pair<int, int> > vecPair;
	typedef std::vector<std::pair<int, int> >::iterator vecPairIter;

	template <typename srcCont, typename dstCont>
	void mergeInsertion(const srcCont& src, dstCont& dst, const std::vector<int>& jacobSthal);

   public:
	Vec();
	Vec(const Vec& obj);
	virtual ~Vec();
	Vec& operator=(const Vec& obj);
	virtual void FJmergeInsertionsort(const int& ac, const char**& av, const Parser& parser);
};

std::ostream& operator<<(std::ostream& os, const Vec& obj);

#endif
