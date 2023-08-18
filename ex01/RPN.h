/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:40:48 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 18:24:52 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <cstdlib>
#include <iostream>
#include <stack>

#include "Error.hpp"
#include "color.h"
#include "verbose.h"

#define RPN_DFLT_CTOR GREEN "- RPN: Default constructor called" RESET
#define RPN_CTOR DARK_GREEN "- RPN: constructor called" RESET
#define RPN_CPY_CTOR CYAN "- RPN: Copy constructor called" RESET
#define RPN_CPY_ASGMT_OP_CALL DARK_CYAN "- RPN: Copy assignment operator called" RESET
#define RPN_DTOR ORANGE "- RPN: Destructor called" RESET
#define RPN_MEMBER_FUNC_CALL "- RPN member function called"

#endif
