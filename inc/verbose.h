/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:44:26 by jgo               #+#    #+#             */
/*   Updated: 2023/07/26 11:05:04 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERSION_H
#define VERSION_H

#include "color.h"

#ifndef PRT_VER
#define PRT_VER std::cout << "cpp version: " YELLOW << __cplusplus << RESET "\n"
#endif

#ifndef V
#define V 0
#endif

#ifndef VERBOSE
#define VERBOSE(STR) \
	if (V)           \
		std::cout << STR << std::endl;
#endif
#endif