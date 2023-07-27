/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:03:38 by jgo               #+#    #+#             */
/*   Updated: 2023/07/27 15:04:18 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_H
#define DATE_H

#include "color.h"
#include "verbose.h"

#define DATE_CTOR DARK_GREEN "- Date: constructor called" RESET
#define DATE_DFLT_CTOR GREEN "- Date: Default constructor called" RESET
#define DATE_CTR LIGHT_CYAN "- Date: constructor called" RESET
#define DATE_CPY_CTOR CYAN "- Date: Copy constructor called" RESET
#define DATE_CPY_ASGMT_OP_CALL DARK_CYAN "- Date: Copy assignment operator called" RESET
#define DATE_DTOR ORANGE "- Date: Destructor called" RESET
#define DATE_MEMBER_FUNC_CALL "- Date member function called"

#endif
