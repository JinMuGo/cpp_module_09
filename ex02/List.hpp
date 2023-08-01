/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:00 by jgo               #+#    #+#             */
/*   Updated: 2023/08/01 17:27:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "List.h"

class List : public std::list<int>, public AmyContainer {
   private:
	List();

   public:
	List(const List& obj);
	List(const int& ac, const char**& av);
	virtual ~List();
	List& operator=(const List& obj);
	virtual void FJmergeInsertionsort(const int& ac, const char**& av);
};

std::ostream& operator<<(std::ostream& os, const List& obj);

#endif
