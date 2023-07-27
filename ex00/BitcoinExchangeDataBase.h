/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeDataBase.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:02:35 by jgo               #+#    #+#             */
/*   Updated: 2023/07/27 17:20:16 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGEDATABASE_H
#define BITCOINEXCHANGEDATABASE_H

#include "color.h"
#include "verbose.h"

#define DATA_DFLT_CTOR GREEN "- DataBase: Default constructor called" RESET
#define DATA_CTOR DARK_GREEN "- DataBase: constructor called" RESET
#define DATA_CTR LIGHT_CYAN "- DataBase: constructor called" RESET
#define DATA_CPY_CTOR CYAN "- DataBase: Copy constructor called" RESET
#define DATA_CPY_ASGMT_OP_CALL DARK_CYAN "- DataBase: Copy assignment operator called" RESET
#define DATA_DTOR ORANGE "- DataBase: Destructor called" RESET
#define DATA_MEMBER_FUNC_CALL "- DataBase member function called"

#endif
