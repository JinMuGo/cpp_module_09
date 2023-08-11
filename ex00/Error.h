/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:12:11 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 17:15:56 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <sstream>
#include "color.h"
#include "verbose.h"

#define ERR_CTOR DARK_GREEN "- Error: constructor called" RESET
#define ERR_DFLT_CTOR GREEN "- Error: Default constructor called" RESET
#define ERR_CPY_CTOR CYAN "- Error: Copy constructor called" RESET
#define ERR_CPY_ASGMT_OP_CALL DARK_CYAN "- Error: Copy assignment operator called" RESET
#define ERR_DTOR ORANGE "- Error: Destructor called" RESET
#define ERR_MEMBER_FUNC_CALL "- Error member function called"

#define ARG_NUM_ERR "The number of arguments must be 2."
#define DATA_SUR_ERR "The data file surfix must be .csv"
#define FILE_OPEN_ERR "File open error"
#define INVALID_DATA_FORMAT "Invalid data format"
#define INVALID_DATA_LINE_FORMAT "Invalid data line format"

#define INVALID_DATE_FORMAT "Invalid Date format: \""

#define INVALID_INPUT_FORMAT "Invalid Input format"
#define INVALID_INPUT_LINE_FORMAT "Invalid Input line format"

#define NOT_POSITIVE "not a positive number."
#define TOO_LARGE "too large number the value is must be 0 and 1000"

#endif
