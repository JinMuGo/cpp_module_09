/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeDataBase.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:51:25 by jgo               #+#    #+#             */
/*   Updated: 2023/07/27 17:46:14 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::DataBase::kDate = "date";
const std::string BitcoinExchange::DataBase::kExchangeRate = "exchange_rate";

BitcoinExchange::DataBase::DataBase(void) : _data(NULL) {
	VERBOSE(DATA_DFLT_CTOR);
}
BitcoinExchange::DataBase::DataBase(const std::string& arg) : _data(loadDataBase(arg)) {
	VERBOSE(DATA_CTOR);
}

BitcoinExchange::DataBase::~DataBase() {
	VERBOSE(DATA_DTOR);
}
BitcoinExchange::DataBase::DataBase(const DataBase& obj) {
	VERBOSE(DATA_CPY_CTOR);
	*this = obj;
}
BitcoinExchange::DataBase& BitcoinExchange::DataBase::operator=(const DataBase& obj) {
	VERBOSE(DATE_CPY_ASGMT_OP_CALL);
	if (this == &obj)
		return *this;
	return *this;
}

// 파일의 맨처음에 포맷을 정의했다고 가정. 처음에 나온 포맷을 따라간다.
std::map<Date, double>* BitcoinExchange::DataBase::loadDataBase(const std::string& arg) {
	if (arg.substr(arg.length() - 4) != ".csv")
		throw BitcoinExchange::error(DATA_SUR_ERR, __func__, __FILE__);
	std::ifstream dataFile(arg, std::ifstream::in | std::ifstream::binary);

	if (dataFile.fail())
		throw BitcoinExchange::error(FILE_OPEN_ERR, __func__, __FILE__);
	std::map<Date, double>* dataBase = new std::map<Date, double>;
	std::string format;

	std::getline(dataFile, format);
	if (format.find(kDate) == std::string::npos || format.find(kExchangeRate) == std::string::npos)
		throw BitcoinExchange::error(INVALID_FORMAT, __func__, __FILE__);
	for (std::string line; std::getline(dataFile, line);) {
		std::cout << line << std::endl;
	}
	return dataBase;
}
