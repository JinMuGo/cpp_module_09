/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:24:20 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 23:00:36 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "verbose.h"

static inline void _printPmergeMe(void) {
	VERBOSE("    ____                                 __  ___   ");
	VERBOSE("   / __ \\____ ___  ___  _________ ____  /  |/  /__ ");
	VERBOSE("  / /_/ / __ `__ \\/ _ \\/ ___/ __ `/ _ \\/ /|_/ / _ \\");
	VERBOSE(" / ____/ / / / / /  __/ /  / /_/ /  __/ /  / /  __/");
	VERBOSE("/_/   /_/ /_/ /_/\\___/_/   \\__, /\\___/_/  /_/\\___/ ");
	VERBOSE("                          /____/                   ");
}

int main(const int ac, const char** av) {
	_printPmergeMe();
	try {
		PmergeMe pm(ac, av);

		pm.vecSort(ac, av);
		pm.deqSort(ac, av);
		pm.confirmSort();
		std::cout << &pm.getVec() << std::endl;
		std::cout << &pm.getDeq() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}
