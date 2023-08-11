/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:23:10 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 17:59:18 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

List::List(const List& obj) : std::list<int>(), AmyContainer(obj) {
	VERBOSE(LIST_CPY_CTOR);
}

List::List(const int& ac, const char**& av) : std::list<int>(), AmyContainer(ac, av) {
	VERBOSE(LIST_CTOR);
}

List::~List() {
	VERBOSE(LIST_DTOR);
}

List& List::operator=(const List& obj) {
	VERBOSE(LIST_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		this->std::list<int>::operator=(obj);
		this->AmyContainer::operator=(obj);
	}
	return (*this);
}

void List::FJmergeInsertionsort(const int& ac, const char**& av) {
	Parser::_ParseList(*this, ac, av);
	this->sort();
}

std::ostream& operator<<(std::ostream& os, const List& obj) {
	return os << "Time to process a range of " << obj.getAc() - 1
			  << " elements with " << std::left << std::setw(11) << "std::list" << " : " << obj.getElapsedTime() << "ms";
}
