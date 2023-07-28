/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:02:31 by jgo               #+#    #+#             */
/*   Updated: 2023/07/28 12:45:53 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "BitcoinExchange.h"
#include "BitcoinExchangeDataBase.h"

class BitcoinExchange {
   private:
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

		static void parseData(const std::string &line, std::map<Date, double> *dataBase);
		static void checkCsvSuf(const std::string &arg);
	};

	DataBase _database;
	std::map<Date, float>* _input;
	BitcoinExchange();

   public:
	BitcoinExchange(const std::string& arg);
	BitcoinExchange(const BitcoinExchange& obj);
	BitcoinExchange& operator=(const BitcoinExchange& obj);
	~BitcoinExchange();
	static Error error(const char* msg, const char* func, const char* file);
	void exchange(const std::string& arg);
};

#endif
