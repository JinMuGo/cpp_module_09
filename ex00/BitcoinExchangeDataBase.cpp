/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeDataBase.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:51:25 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 16:56:26 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::DataBase::kFormat = "date,exchange_rate";

BitcoinExchange::DataBase::DataBase(void) : _data(NULL) {
	VERBOSE(DATA_DFLT_CTOR);
}
BitcoinExchange::DataBase::DataBase(const std::string& arg) : _data(loadDataBase(arg)) {
	VERBOSE(DATA_CTOR);
}

BitcoinExchange::DataBase::~DataBase() {
	VERBOSE(DATA_DTOR);
	if (this->_data)
		delete _data;
}
BitcoinExchange::DataBase::DataBase(const DataBase& obj) {
	VERBOSE(DATA_CPY_CTOR);
	*this = obj;
}
BitcoinExchange::DataBase& BitcoinExchange::DataBase::operator=(const DataBase& obj) {
	VERBOSE(DATE_CPY_ASGMT_OP_CALL);
	if (this == &obj) {
		if (this->_data)
			delete this->_data;
		this->_data = new std::map<Date, double>(*obj.getData());
	}
	return *this;
}

const std::map<Date, double>* BitcoinExchange::DataBase::getData(void) const {
	return this->_data;
}

void BitcoinExchange::DataBase::checkCsvSuf(const std::string& arg) {
	if (arg.substr(arg.length() - 4) != ".csv")
		throw Error::error(DATA_SUR_ERR, __func__, __FILE__, __LINE__);
}

void BitcoinExchange::DataBase::parseData(const std::string& line, std::map<Date, double>* dataBase) {
	const std::size_t pivot = line.find(',');
	if (pivot != line.rfind(','))
		throw Error::error(INVALID_DATA_LINE_FORMAT, __func__, __FILE__, __LINE__);
	const std::string first = line.substr(0, pivot);
	const std::string second = line.substr(pivot + 1);
	char* endptr;
	const double rate = strtod(second.c_str(), &endptr);
	if (*endptr)
		throw Error::error(INVALID_DATA_LINE_FORMAT, __func__, __FILE__, __LINE__);
	dataBase->insert(std::make_pair(Date(first), rate));
}

std::map<Date, double>* BitcoinExchange::DataBase::loadDataBase(const std::string& arg) {
	checkCsvSuf(arg);
	std::ifstream dataFile(arg.c_str(), std::ifstream::in | std::ifstream::binary);

	if (dataFile.fail())
		throw Error::error(FILE_OPEN_ERR, __func__, __FILE__, __LINE__);
	std::string format;
	std::getline(dataFile, format);
	if (format != this->kFormat)
		throw Error::error(INVALID_DATA_FORMAT, __func__, __FILE__, __LINE__);
	std::map<Date, double>* dataBase = new std::map<Date, double>;
	for (std::string line; std::getline(dataFile, line);) {
		parseData(line, dataBase);
	}
	return dataBase;
}

const double& BitcoinExchange::DataBase::findRate(const Date& date) const {
	if (_data->size() == 0)
		throw Error::error(DATABASE_EMPTY, __func__, __FILE__, __LINE__);
	if (_data->find(date) != _data->end())
		return _data->at(date);
	if (_data->begin()->first > date)
		throw Error::error(TOO_LOW_DATE, __func__, __FILE__, __LINE__);
	return (*(--_data->lower_bound(date))).second;
}
