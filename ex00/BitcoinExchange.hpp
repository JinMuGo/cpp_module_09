/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:02:31 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 16:37:08 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "BitcoinExchange.h"
#include "BitcoinExchangeDataBase.h"

class BitcoinExchange {
   public:
	class DataBase {
	   private:
		const std::map<Date, double>* _data;
		static const std::string kFormat;

	   public:
		DataBase();
		DataBase(const std::string& arg);
		~DataBase();
		DataBase(const DataBase& obj);
		DataBase& operator=(const DataBase& obj);
		std::map<Date, double>* loadDataBase(const std::string& arg);

		static void parseData(const std::string& line, std::map<Date, double>* dataBase);
		static void checkCsvSuf(const std::string& arg);
		const std::map<Date, double>* getData(void) const;

		const double& findRate(const Date& date) const;
	};

	BitcoinExchange(const std::string& arg);
	BitcoinExchange(const BitcoinExchange& obj);
	BitcoinExchange& operator=(const BitcoinExchange& obj);
	~BitcoinExchange();
	void exchange(const std::string& path);
	DataBase getDataBase(void) const;

	static void checkInputLine(const char* endptr, const double& val);

   private:
	DataBase _database;
	static const std::string kInputFormat;
	BitcoinExchange();
};

#endif
