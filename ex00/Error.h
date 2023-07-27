/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:12:11 by jgo               #+#    #+#             */
/*   Updated: 2023/07/27 17:22:22 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include "color.h"
#include "verbose.h"

#define ERR_CTOR DARK_GREEN "- Error: constructor called" RESET
#define ERR_DFLT_CTOR GREEN "- Error: Default constructor called" RESET
#define ERR_CTR LIGHT_CYAN "- Error: constructor called" RESET
#define ERR_CPY_CTOR CYAN "- Error: Copy constructor called" RESET
#define ERR_CPY_ASGMT_OP_CALL DARK_CYAN "- Error: Copy assignment operator called" RESET
#define ERR_DTOR ORANGE "- Error: Destructor called" RESET
#define ERR_MEMBER_FUNC_CALL "- Error member function called"

#define ARG_NUM_ERR "The number of arguments must be 2."
#define DATA_SUR_ERR "The data file surfix must be .csv"
#define FILE_OPEN_ERR "File open error"
#define INVALID_FORMAT "Invalid format"


#endif
