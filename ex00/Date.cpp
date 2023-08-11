/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:07:00 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 17:16:28 by jgo              ###   ########.fr       */
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
	std::tm tm = {};
	tm.tm_year = this->_year - 1900;
	tm.tm_mon = this->_month - 1;
	tm.tm_mday = this->_day;
	const std::tm tmp = tm;
	if (std::mktime(&tm) == -1 || tm.tm_mday != tmp.tm_mday || dateStream.eof() == false || this->isValidDate(dash1, dash2) == false) {
		const std::string prompt = INVALID_DATE_FORMAT + format + "\"";
		throw Error::error(prompt.c_str(), __func__, __FILE__, __LINE__);
	}
}

Date::~Date() {
	VERBOSE(DATE_DTOR);
}

Date& Date::operator=(const Date& obj) {
	VERBOSE(DATE_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		this->_year = obj.getYear();
		this->_month = obj.getMonth();
		this->_day = obj.getDay();
	}
	return *this;
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
	return os << "Year: " << obj.getYear() << " Month: " << obj.getMonth() << " Day: " << obj.getDay();
}
