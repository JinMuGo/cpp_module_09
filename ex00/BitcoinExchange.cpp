/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:02:48 by jgo               #+#    #+#             */
/*   Updated: 2023/07/28 18:34:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::kInputFormat = "date | value";

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

BitcoinExchange::DataBase BitcoinExchange::getDataBase() const {
	return this->_database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	VERBOSE(BTC_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		this->_database = obj.getDataBase();
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(const std::string& arg) : _database(DataBase(arg)) {
	VERBOSE(BTC_CTOR);
}

Error BitcoinExchange::error(const char* msg, const char* func, const char* file) {
	throw Error(msg, func, file);
}

void BitcoinExchange::checkInputLine(const char* endptr, const double& val) {
	if (*endptr)
		throw BitcoinExchange::error(INVALID_INPUT_LINE_FORMAT, __func__, __FILE__);
	if (val <= 0)
		throw BitcoinExchange::error(NOT_POSITIVE, __func__, __FILE__);
	if (val >= 1000)
		throw BitcoinExchange::error(TOO_LARGE, __func__, __FILE__);
}

void BitcoinExchange::exchange(const std::string& path) {
	std::ifstream inputFile(path.c_str(), std::ifstream::in | std::ifstream::binary);
	std::string format;

	if (inputFile.fail())
		throw BitcoinExchange::error(FILE_OPEN_ERR, __func__, __FILE__);
	std::getline(inputFile, format);
	if (format != this->kInputFormat)
		throw BitcoinExchange::error(INVALID_INPUT_FORMAT, __func__, __FILE__);
	for (std::string line; std::getline(inputFile, line);) {
		const std::size_t pivot = line.find('|');
		const std::string first = line.substr(0, pivot - 1);
		const std::string second = line.substr(pivot + 1);
		char* endptr;
		const double val = std::strtod(second.c_str(), &endptr);
		try {
			checkInputLine(endptr, val);
			const double& rate = this->_database.findRate(Date(first));
			std::cout << first << " => " << val << " = " << val * rate << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}
