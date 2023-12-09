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
   public:
	Deq(const int ac, const char**& av);
	Deq(const Deq& obj);
	Deq& operator=(const Deq& obj);
	virtual ~Deq();
	virtual void FJmergeInsertionsort();
};

std::ostream& operator<<(std::ostream& os, const Deq& obj);

#endif
