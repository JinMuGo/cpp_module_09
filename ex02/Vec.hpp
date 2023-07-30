/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:21:39 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 18:23:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_HPP
#define VEC_HPP

#include "Vec.h"

class Vec : public std::vector<int> {
   private:
	const int &_ac;
	const char **&_av;

   public:
	Vec();
	Vec(const Vec& obj);
	virtual ~Vec();
	Vec& operator=(const Vec& obj);
	void FJmergeInsertionsort();
};

std::ostream& operator<<(std::ostream& os, const Vec& obj);

#endif
