/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:21:50 by jgo               #+#    #+#             */
/*   Updated: 2023/09/05 16:11:28 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQ_H
#define DEQ_H

#include <deque>
#include "AmyContainer.hpp"
#include "Error.hpp"

#define DEQ_DFLT_CTOR GREEN "-- Deq: Default constructor called" RESET
#define DEQ_CTOR DARK_GREEN "-- Deq: constructor called" RESET
#define DEQ_CPY_CTOR CYAN "-- Deq: Copy constructor called" RESET
#define DEQ_CPY_ASGMT_OP_CALL DARK_CYAN "-- Deq: Copy assignment operator called" RESET
#define DEQ_DTOR ORANGE "-- Deq: Destructor called" RESET
#define DEQ_MEMBER_FUNC_CALL "-- Deq member function called"

#endif
