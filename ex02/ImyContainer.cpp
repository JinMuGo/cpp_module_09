/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ImyContainer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:28:27 by jgo               #+#    #+#             */
/*   Updated: 2023/08/01 10:08:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ImyContainer.hpp"

ImyContainer::ImyContainer(const int& ac, const char**& av) : _ac(ac), _av(av), _elapsed_time(0) {
	VERBOSE(MYCONT_CTOR);
}

ImyContainer::ImyContainer(const ImyContainer& obj) : _ac(obj._ac), _av(obj._av), _elapsed_time(obj._elapsed_time) {
	VERBOSE(MYCONT_CPY_CTOR);
}

ImyContainer::~ImyContainer() {
	VERBOSE(MYCONT_DTOR);
}

ImyContainer& ImyContainer::operator=(const ImyContainer& obj) {
	VERBOSE(MYCONT_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		const_cast<int&>(this->_ac) = obj.getAc();
		const_cast<char**&>(this->_av) = const_cast<char**&>(obj.getAv());
		const_cast<std::clock_t&>(this->_elapsed_time) = obj.getElapsedTime();
	}
	return (*this);
}

int ImyContainer::getAc(void) const {
	return this->_ac;
}

const char**& ImyContainer::getAv(void) const {
	return this->_av;
}

std::clock_t ImyContainer::getElapsedTime(void) const {
	return this->_elapsed_time;
}

void ImyContainer::setElapsedTime(const std::clock_t time) {
	this->_elapsed_time = time;
}