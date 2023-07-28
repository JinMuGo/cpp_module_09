/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:07:00 by jgo               #+#    #+#             */
/*   Updated: 2023/07/28 13:26:39 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date() {
	VERBOSE(DATE_DFLT_CTOR);
}
Date::Date(const Date& obj) {
	VERBOSE(DATE_CPY_CTOR);
	*this = obj;
}
Date::Date(const std::string& format) : _str(format) {
	VERBOSE(DATE_CTOR);
	std::istringstream dateStream(format);
	char dash1, dash2;

	dateStream >> this->_year >> dash1 >> this->_month >> dash2 >> this->_day;
	if (dateStream.eof() == false || this->isValidDate(dash1, dash2) == false)
		throw error(INVALID_DATE_FORMAT, __func__, __FILE__);
}
Date::~Date() {
	VERBOSE(DATE_DTOR);
}
Date& Date::operator=(const Date& obj) {
	VERBOSE(DATE_CPY_ASGMT_OP_CALL);
	if (this != &obj)
		return *this;
	return *this;
}

Error Date::error(const char* msg, const char* func, const char* file) {
	throw Error(msg, func, file);
}

bool Date::isValidDate(const char& dash1, const char& dash2) {
	if (dash1 == '-' && dash2 == '-' && this->_year >= 0 && this->_year <= 9999 && this->_month >= 1 &&
		this->_month <= 12 && this->_day >= 1 && this->_day <= 31) {
		return true;
	}
	return false;
}

int Date::getYear() const {
	return this->_year;
}
int Date::getMonth() const {
	return this->_month;
}
int Date::getDay() const {
	return this->_day;
}

bool Date::operator<(const Date& obj) const {
	if (_year != obj._year)
		return _year < obj._year;
	if (_month != obj._month)
		return _month < obj._month;
	return _day < obj._day;
}
bool Date::operator>(const Date& obj) const {
	if (_year != obj._year)
		return _year > obj._year;
	if (_month != obj._month)
		return _month > obj._month;
	return _day > obj._day;
}
bool Date::operator<=(const Date& obj) const {
	if (_year != obj._year)
		return _year <= obj._year;
	if (_month != obj._month)
		return _month <= obj._month;
	return _day <= obj._day;
}
bool Date::operator>=(const Date& obj) const {
	if (_year != obj._year)
		return _year >= obj._year;
	if (_month != obj._month)
		return _month >= obj._month;
	return _day >= obj._day;
}
bool Date::operator==(const Date& obj) const {
	if (_year != obj._year)
		return _year == obj._year;
	if (_month != obj._month)
		return _month == obj._month;
	return _day == obj._day;
}
bool Date::operator!=(const Date& obj) const {
	if (_year != obj._year)
		return _year != obj._year;
	if (_month != obj._month)
		return _month != obj._month;
	return _day != obj._day;
}

std::ostream& operator<<(std::ostream& os, const Date& obj) {
	return os << "Year: " << obj.getYear()  << " Month: " << obj.getMonth() << " Day: " << obj.getDay();
}
