/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:21:32 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 23:10:24 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <vector>
#include "ImyContainer.hpp"
#include "Parser.hpp"

#include "Error.hpp"
#include "color.h"
#include "verbose.h"

#define VEC_DFLT_CTOR GREEN "-- Vec: Default constructor called" RESET
#define VEC_CTOR DARK_GREEN "-- Vec: constructor called" RESET
#define VEC_CPY_CTOR CYAN "-- Vec: Copy constructor called" RESET
#define VEC_CPY_ASGMT_OP_CALL DARK_CYAN "-- Vec: Copy assignment operator called" RESET
#define VEC_DTOR ORANGE "-- Vec: Destructor called" RESET
#define VEC_MEMBER_FUNC_CALL "-- Vec member function called"

#endif
