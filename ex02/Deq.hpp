/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:00 by jgo               #+#    #+#             */
/*   Updated: 2023/09/06 19:41:47 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQ_HPP
#define DEQ_HPP

#include "Deq.h"

class Deq : public std::deque<int>, public AmyContainer {
   private:
	std::deque<std::pair<int, int> > _tmp;
	void mergeInsertion(const deqPair& src, std::deque<int>& dst, const std::vector<int>& jacobSthal);

   public:
	Deq();
	Deq(const Deq& obj);
	Deq& operator=(const Deq& obj);
	virtual ~Deq();
	virtual void FJmergeInsertionsort(const int& ac, const char**& av, const Parser& parser);
};

std::ostream& operator<<(std::ostream& os, const Deq& obj);

#endif
