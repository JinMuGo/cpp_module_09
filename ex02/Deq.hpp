/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:00 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 23:22:48 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQ_HPP
#define DEQ_HPP

#include "Deq.h"

class Deq : public std::deque<int>, public ImyContainer {
   private:
	Deq();

   public:
	Deq(const Deq& obj);
	Deq(const int& ac, const char**& av);
	virtual ~Deq();
	Deq& operator=(const Deq& obj);
	virtual void FJmergeInsertionsort();
};

std::ostream& operator<<(std::ostream& os, const Deq& obj);

#endif
