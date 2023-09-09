/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:12:11 by jgo               #+#    #+#             */
/*   Updated: 2023/09/09 19:22:22 by jgo              ###   ########.fr       */
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

#define INVALID_ARGS "Invalid arguments"
#define INVALID_RANGE "Invalid Range of arguments"
#define AT_LEAST_ARGS "you need to at least one arguments in this program"
#define ALREADY_SORTED "this arguments sequence is already sorted"
#define TOO_MANY_ARGS "too many arguments try lower number of args"
#define INVALID_SORT "Invalid Sort"

#endif
