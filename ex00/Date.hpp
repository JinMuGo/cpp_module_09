/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:04:30 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 16:37:16 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP

#include "Date.h"

class Date {
   private:
	const std::string _str;
	int _year;
	int _month;
	int _day;

	Date();
   public:
	Date(const std::string& format);
	Date(const Date& obj);
	~Date();
	Date& operator=(const Date& obj);

	bool isValidDate(const char &dash1, const char &dash2);
	bool operator<(const Date& obj) const;
	bool operator>(const Date& obj) const;
	bool operator<=(const Date& obj) const;
	bool operator>=(const Date& obj) const;
	bool operator==(const Date& obj) const;
	bool operator!=(const Date& obj) const;

	int getYear() const;
	int getMonth() const;
	int getDay() const;
};

std::ostream& operator<<(std::ostream &os, const Date& obj);

#endif
