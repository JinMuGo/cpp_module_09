/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:02:35 by jgo               #+#    #+#             */
/*   Updated: 2023/07/28 18:33:14 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "color.h"
#include "verbose.h"

#include "Date.hpp"
#include "Error.hpp"

#define BTC_DFLT_CTOR GREEN "- BitcoinExchange: Default constructor called" RESET
#define BTC_CTOR DARK_GREEN "- BitcoinExchange: constructor called" RESET
#define BTC_CTR LIGHT_CYAN "- BitcoinExchange: constructor called" RESET
#define BTC_CPY_CTOR CYAN "- BitcoinExchange: Copy constructor called" RESET
#define BTC_CPY_ASGMT_OP_CALL DARK_CYAN "- BitcoinExchange: Copy assignment operator called" RESET
#define BTC_DTOR ORANGE "- BitcoinExchange: Destructor called" RESET
#define BTC_MEMBER_FUNC_CALL "- BitcoinExchange member function called"

#endif
