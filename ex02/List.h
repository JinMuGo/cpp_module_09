/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:21:50 by jgo               #+#    #+#             */
/*   Updated: 2023/08/01 17:19:59 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <list>
#include "AmyContainer.hpp"
#include "Error.hpp"
#include "Parser.hpp"

#include "color.h"
#include "verbose.h"

#define LIST_DFLT_CTOR GREEN "-- List: Default constructor called" RESET
#define LIST_CTOR DARK_GREEN "-- List: constructor called" RESET
#define LIST_CPY_CTOR CYAN "-- List: Copy constructor called" RESET
#define LIST_CPY_ASGMT_OP_CALL DARK_CYAN "-- List: Copy assignment operator called" RESET
#define LIST_DTOR ORANGE "-- List: Destructor called" RESET
#define LIST_MEMBER_FUNC_CALL "-- List member function called"

#endif
