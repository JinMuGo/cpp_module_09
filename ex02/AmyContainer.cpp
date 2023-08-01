/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ImyContainer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:28:27 by jgo               #+#    #+#             */
/*   Updated: 2023/08/01 12:40:11 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AmyContainer.hpp"

AmyContainer::AmyContainer(const int& ac, const char**& av) : _ac(ac), _av(av), _elapsed_time(0) {
	VERBOSE(MYCONT_CTOR);
}

AmyContainer::AmyContainer(const AmyContainer& obj) : _ac(obj._ac), _av(obj._av), _elapsed_time(obj._elapsed_time) {
	VERBOSE(MYCONT_CPY_CTOR);
}

AmyContainer::~AmyContainer() {
	VERBOSE(MYCONT_DTOR);
}

AmyContainer& AmyContainer::operator=(const AmyContainer& obj) {
	VERBOSE(MYCONT_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		const_cast<int&>(this->_ac) = obj.getAc();
		const_cast<char**&>(this->_av) = const_cast<char**&>(obj.getAv());
		const_cast<std::clock_t&>(this->_elapsed_time) = obj.getElapsedTime();
	}
	return (*this);
}

int AmyContainer::getAc(void) const {
	return this->_ac;
}

const char**& AmyContainer::getAv(void) const {
	return this->_av;
}

std::clock_t AmyContainer::getElapsedTime(void) const {
	return this->_elapsed_time;
}

void AmyContainer::setElapsedTime(const std::clock_t time) {
	this->_elapsed_time = time;
}
