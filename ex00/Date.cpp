/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:07:00 by jgo               #+#    #+#             */
/*   Updated: 2023/07/27 15:08:01 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date() {
	VERBOSE(DATE_DFLT_CTOR);
}
Date::Date(const Date& obj) {
	VERBOSE(DATE_CPY_CTOR);
}
Date::~Date() {
	VERBOSE(DATE_DTOR);
}
Date& Date::operator=(const Date& obj) {
	VERBOSE(DATE_CPY_ASGMT_OP_CALL);
}
