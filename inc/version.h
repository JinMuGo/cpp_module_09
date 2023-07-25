/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   version.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:44:26 by jgo               #+#    #+#             */
/*   Updated: 2023/07/24 09:46:01 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERSION_H
#define VERSION_H

#include "color.h"

#ifndef PRT_VER
 #define PRT_VER std::cout << "cpp version: " YELLOW << __cplusplus << RESET "\n"
#endif

#endif