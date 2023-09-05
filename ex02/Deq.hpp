/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:00 by jgo               #+#    #+#             */
/*   Updated: 2023/09/05 16:41:50 by jgo              ###   ########.fr       */
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

	template <typename srcCont, typename dstCont>
	void mergeInsertion(const srcCont& src, dstCont& dst, const std::vector<int>& jacobSthal);

   public:
	Deq();
	Deq(const Deq& obj);
	Deq& operator=(const Deq& obj);
	virtual ~Deq();
	virtual void FJmergeInsertionsort(const int& ac, const char**& av, const Parser& parser);
};

std::ostream& operator<<(std::ostream& os, const Deq& obj);

#endif
