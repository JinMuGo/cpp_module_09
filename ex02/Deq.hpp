/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:00 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 18:23:38 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQ_HPP
#define DEQ_HPP

#include "Deq.h"

class Deq : public std::deque<int> {
   private:
		const int &_ac;
		const char **&_av;

   public:
	Deq();
	Deq(const Deq& obj);
	virtual ~Deq();
	Deq& operator=(const Deq& obj);
	void FJmergeInsertionsort();
};

#endif
