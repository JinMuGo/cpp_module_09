/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:00 by jgo               #+#    #+#             */
/*   Updated: 2023/09/03 20:21:09 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQ_HPP
#define DEQ_HPP

#include "Deq.h"

class Deq : public std::deque<int>, public AmyContainer {
   private:
	std::deque<std::pair<int, int> > _tmp;

	typedef std::deque<std::pair<int, int> > deqPair;
	typedef std::deque<std::pair<int, int> >::iterator deqPairIter;

   public:
	Deq();
	Deq(const Deq& obj);
	virtual ~Deq();
	Deq& operator=(const Deq& obj);
	virtual void FJmergeInsertionsort(const int& ac, const char**& av);
};

std::ostream& operator<<(std::ostream& os, const Deq& obj);

#endif
