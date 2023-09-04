/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AmyContainer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:28:27 by jgo               #+#    #+#             */
/*   Updated: 2023/09/03 20:22:13 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AmyContainer.hpp"

AmyContainer::AmyContainer(void) : _last(0), _elapsed_time(0) {
	VERBOSE(MYCONT_DFLT_CTOR);
}

AmyContainer::AmyContainer(const AmyContainer& obj) : _last(0), _elapsed_time(obj.getElapsedTime()) {
	VERBOSE(MYCONT_CPY_CTOR);
}

AmyContainer::~AmyContainer() {
	VERBOSE(MYCONT_DTOR);
}

AmyContainer& AmyContainer::operator=(const AmyContainer& obj) {
	VERBOSE(MYCONT_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		this->_last = obj._last;
		const_cast<std::clock_t&>(this->_elapsed_time) = obj.getElapsedTime();
	}
	return (*this);
}

int AmyContainer::getLast(void) const {
	return this->_last;
}
void AmyContainer::setLast(const int last) {
	this->_last = last;
}

std::clock_t AmyContainer::getElapsedTime(void) const {
	return this->_elapsed_time;
}

void AmyContainer::setElapsedTime(const std::clock_t time) {
	this->_elapsed_time = time;
}