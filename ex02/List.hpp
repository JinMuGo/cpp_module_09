/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:00 by jgo               #+#    #+#             */
/*   Updated: 2023/09/05 16:08:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "List.h"

class List : public std::list<int>, public AmyContainer {
   private:
   public:
	List(const int ac, const char**& av);
	List(const List& obj);
	virtual ~List();
	List& operator=(const List& obj);
	virtual void FJmergeInsertionsort(const int ac, const char**& av);
};

std::ostream& operator<<(std::ostream& os, const List& obj);

#endif
