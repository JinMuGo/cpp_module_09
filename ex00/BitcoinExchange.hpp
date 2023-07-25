/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:02:31 by jgo               #+#    #+#             */
/*   Updated: 2023/07/24 12:04:44 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "BitcoinExchange.h"

class BitcoinExchange {
   private:
	/* data */
   public:
	BitcoinExchange(/* args */);
	BitcoinExchange(const BitcoinExchange& obj);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& obj);
};

#endif
