/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:21:50 by jgo               #+#    #+#             */
/*   Updated: 2023/09/05 16:11:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

#include <list>
#include "Error.hpp"
#include "AmyContainer.hpp"

#define LIST_DFLT_CTOR GREEN "-- List: Default constructor called" RESET
#define LIST_CTOR DARK_GREEN "-- List: constructor called" RESET
#define LIST_CPY_CTOR CYAN "-- List: Copy constructor called" RESET
#define LIST_CPY_ASGMT_OP_CALL DARK_CYAN "-- List: Copy assignment operator called" RESET
#define LIST_DTOR ORANGE "-- List: Destructor called" RESET
#define LIST_MEMBER_FUNC_CALL "-- List member function called"

#endif
