/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:21:39 by jgo               #+#    #+#             */
/*   Updated: 2023/08/01 16:56:02 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_HPP
#define VEC_HPP

#include "Vec.h"

class Vec : public std::vector<int>, public AmyContainer {
   private:
	Vec();
	std::vector<std::pair<int, int> > _tmp;

   public:
	Vec(const int& ac, const char**& av);
	Vec(const Vec& obj);
	virtual ~Vec();
	Vec& operator=(const Vec& obj);
	virtual void FJmergeInsertionsort(const int& ac, const char**& av);
};

std::ostream& operator<<(std::ostream& os, const Vec& obj);

#endif
