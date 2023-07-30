/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ImyContainer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:25:32 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 23:05:20 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMYCONTAINER_H
#define IMYCONTAINER_H

#include <iostream>
#include "color.h"
#include "verbose.h"

#define MYCONT_DFLT_CTOR GREEN "- myContainer: Default constructor called" RESET
#define MYCONT_CTOR DARK_GREEN "- myContainer: constructor called" RESET
#define MYCONT_CPY_CTOR CYAN "- myContainer: Copy constructor called" RESET
#define MYCONT_CPY_ASGMT_OP_CALL DARK_CYAN "- myContainer: Copy assignment operator called" RESET
#define MYCONT_DTOR ORANGE "- myContainer: Destructor called" RESET
#define MYCONT_MEMBER_FUNC_CALL "- myContainer: member function called"

#endif