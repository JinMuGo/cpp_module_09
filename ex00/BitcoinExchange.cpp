/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:02:48 by jgo               #+#    #+#             */
/*   Updated: 2023/07/26 11:05:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	VERBOSE(BTC_DFLT_CTOR);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	VERBOSE(BTC_CPY_CTOR);
}
BitcoinExchange::~BitcoinExchange() {
	VERBOSE(BTC_DTOR);
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	VERBOSE(BTC_CPY_ASGMT_OP_CALL);
}
