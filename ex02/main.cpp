/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:24:20 by jgo               #+#    #+#             */
/*   Updated: 2023/08/02 11:06:34 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "PmergeMe.hpp"
#include "verbose.h"

static inline void _printPmergeMe(void) {
	VERBOSE("    ____                                 __  ___   ");
	VERBOSE("   / __ \\____ ___  ___  _________ ____  /  |/  /__ ");
	VERBOSE("  / /_/ / __ `__ \\/ _ \\/ ___/ __ `/ _ \\/ /|_/ / _ \\");
	VERBOSE(" / ____/ / / / / /  __/ /  / /_/ /  __/ /  / /  __/");
	VERBOSE("/_/   /_/ /_/ /_/\\___/_/   \\__, /\\___/_/  /_/\\___/ ");
	VERBOSE("                          /____/                   ");
	PRT_VER;
}

static inline void _printUnSortArgv(const int& ac, const char**& av) {
	std::cout << std::left << std::setw(10) << "Before: ";
	for (int i = 1; i < ac; ++i) {
		std::cout << av[i] << " ";
	}
	std::cout << std::endl;
}

static inline void _printSortArgv(const std::list<int>& list) {
	std::cout << std::left << std::setw(10) << "After: ";
	for (std::list<int>::const_iterator cit = list.begin(); cit != list.end(); ++cit)
		std::cout << *cit << " ";
	std::cout << std::endl;
}

int main(const int ac, const char** av) {
	_printPmergeMe();

	try {
		if (ac == 1)
			throw Error::error(AT_LEAST_ARGS, __func__, __FILE__);
		Parser::_checkAv(ac, av);
		PmergeMe pm(ac, av);

		pm.listSort(ac, av);
		if (pm.alreadySorted(ac, av))
			throw Error::error(ALREADY_SORTED, __func__, __FILE__);
		pm.vecSort(ac, av);
		pm.deqSort(ac, av);
		pm.confirmSort();
		_printUnSortArgv(ac, av);
		_printSortArgv(pm.getList());
		std::cout << pm.getVec() << std::endl;
		std::cout << pm.getDeq() << std::endl;
		std::cout << pm.getList() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
