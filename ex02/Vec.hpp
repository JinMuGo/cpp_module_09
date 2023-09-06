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
	std::vector<std::pair<int, int> > _tmp;
	void mergeInsertion(const vecPair& src, std::vector<int>& dst, const std::vector<int>& jacobSthal);

   public:
	Vec();
	Vec(const Vec& obj);
	virtual ~Vec();
	Vec& operator=(const Vec& obj);
	virtual void FJmergeInsertionsort(const int& ac, const char**& av, const Parser& parser);
};

std::ostream& operator<<(std::ostream& os, const Vec& obj);

#endif
