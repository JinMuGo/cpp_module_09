/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:00 by jgo               #+#    #+#             */
/*   Updated: 2023/08/01 16:56:20 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQ_HPP
#define DEQ_HPP

#include "Deq.h"

class Deq : public std::deque<int>, public AmyContainer {
   private:
	Deq();
	std::deque<std::pair<int, int> > _tmp;

   public:
	Deq(const Deq& obj);
	Deq(const int& ac, const char**& av);
	virtual ~Deq();
	Deq& operator=(const Deq& obj);
	virtual void FJmergeInsertionsort(const int& ac, const char**& av);
};

std::ostream& operator<<(std::ostream& os, const Deq& obj);

#endif
