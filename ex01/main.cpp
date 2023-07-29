/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:39:42 by jgo               #+#    #+#             */
/*   Updated: 2023/07/29 19:55:46 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RPN.hpp"

static inline void _printRPN(void) {
	VERBOSE(" ██████╗   ██████╗   ███╗   ██╗");
	VERBOSE(" ██╔══██╗  ██╔══██╗  ████╗  ██║");
	VERBOSE(" ██████╔╝  ██████╔╝  ██╔██╗ ██║");
	VERBOSE(" ██╔══██╗  ██╔═══╝   ██║╚██╗██║");
	VERBOSE(" ██║  ██║  ██║       ██║ ╚████║");
	VERBOSE(" ╚═╝  ╚═╝  ╚═╝       ╚═╝  ╚═══╝");
}

int main(int ac, char** av) {
	_printRPN();
	try {
		if (ac != 2)
			throw RPN::error(ARG_NUM_ERR, __func__, __FILE__);
		RPN rpn(av[1]);
		std::cout << rpn.process() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return EXIT_SUCCESS;
}
