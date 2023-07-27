/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:02:48 by jgo               #+#    #+#             */
/*   Updated: 2023/07/27 17:46:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	VERBOSE(BTC_DFLT_CTOR);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	VERBOSE(BTC_CPY_CTOR);
	*this = obj;
}

BitcoinExchange::~BitcoinExchange() {
	VERBOSE(BTC_DTOR);
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	VERBOSE(BTC_CPY_ASGMT_OP_CALL);
	if (this == &obj)
		return (*this);
	return (*this);
}

BitcoinExchange::BitcoinExchange(const std::string& arg) : _database(DataBase(arg)) {
	VERBOSE(BTC_CTOR);
}

Error BitcoinExchange::error(const char* msg, const char *func, const char *file) {
	throw Error(msg, func, file);
}

void BitcoinExchange::exchange(const std::string& arg) {}

