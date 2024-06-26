/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:24:21 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 17:27:22 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <sys/time.h>
#include <ctime>
#include <iostream>
#include "Deq.hpp"
#include "Error.hpp"
#include "List.hpp"
#include "Vec.hpp"

#include "color.h"
#include "verbose.h"

#define PMM_DFLT_CTOR GREEN "- PmergeMe: Default constructor called" RESET
#define PMM_CTOR DARK_GREEN "- PmergeMe: constructor called" RESET
#define PMM_CPY_CTOR CYAN "- PmergeMe: Copy constructor called" RESET
#define PMM_CPY_ASGMT_OP_CALL DARK_CYAN "- PmergeMe: Copy assignment operator called" RESET
#define PMM_DTOR ORANGE "- PmergeMe: Destructor called" RESET
#define PMM_MEMBER_FUNC_CALL "- PmergeMe member function called"

#endif
