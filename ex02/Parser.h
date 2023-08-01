/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:59 by jgo               #+#    #+#             */
/*   Updated: 2023/08/01 10:04:10 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

#include "Error.hpp"
#include "color.h"
#include "verbose.h"

#define PRS_DFLT_CTOR GREEN "- Parser: Default constructor called" RESET
#define PRS_CTOR DARK_GREEN "- Parser: constructor called" RESET
#define PRS_CPY_CTOR CYAN "- Parser: Copy constructor called" RESET
#define PRS_CPY_ASGMT_OP_CALL DARK_CYAN "- Parser: Copy assignment operator called" RESET
#define PRS_DTOR ORANGE "- Parser: Destructor called" RESET
#define PRS_MEMBER_FUNC_CALL "- Parser: member function called"

#endif
