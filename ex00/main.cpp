/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:02:28 by jgo               #+#    #+#             */
/*   Updated: 2023/09/16 15:00:38 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "BitcoinExchange.hpp"
#include "verbose.h"

static inline void _printBitcoinExchange(void) {
	std::cout << " ____         __                              ____                  __                               "
				 "           \n";
	std::cout << "/\\  _`\\    __/\\ \\__                __        /\\  _`\\               /\\ \\                      "
				 "                   \n";
	std::cout << "\\ \\ \\L\\ \\ /\\_\\ \\ ,_\\   ___    ___ /\\_\\    ___\\ \\ \\L\\_\\  __  _   ___\\ \\ \\___      "
				 "__      ___      __      __    \n";
	std::cout << " \\ \\  _ <'\\/\\ \\ \\ \\/  /'___\\ / __`\\/\\ \\ /' _ `\\ \\  _\\L /\\ \\/'\\ /'___\\ \\  _ `\\  "
				 "/'__`\\  /' _ `\\  /'_ `\\  /'__`\\  \n";
	std::cout << "  \\ \\ \\L\\ \\\\ \\ \\ \\ \\_/\\ \\__//\\ \\L\\ \\ \\ \\/\\ \\/\\ \\ \\ \\L\\ \\/>  <//\\ \\__/\\ "
				 "\\ \\ \\ \\/\\ \\L\\.\\_/\\ \\/\\ \\/\\ \\L\\ \\/\\  __/  \n";
	std::cout << "   \\ \\____/ \\ \\_\\ \\__\\ \\____\\ \\____/\\ \\_\\ \\_\\ \\_\\ \\____//\\_/\\_\\ \\____\\\\ "
				 "\\_\\ \\_\\ \\__/.\\_\\ \\_\\ \\_\\ \\____ \\ \\____\\ \n";
	std::cout << "    \\/___/   \\/_/\\/__/\\/____/\\/___/  \\/_/\\/_/\\/_/\\/___/ \\//\\/_/\\/____/ "
				 "\\/_/\\/_/\\/__/\\/_/\\/_/\\/_/\\/___L\\ \\/____/ \n";
	std::cout << "                                                                                                  "
				 "/\\____/       \n";
	std::cout << "                                                                                                  "
				 "\\_/__/        \n";
	PRT_VER;
}

static inline std::string _judgeDataPath() {
	const char* getCwd = getcwd(NULL, 0);

	if (getCwd == NULL)
		throw Error::error(std::strerror(errno), __func__, __FILE__, __LINE__);
	const std::string curPath = getCwd;
	delete getCwd;

	if (curPath.find("ex00") == std::string::npos)
		return "./ex00/data.csv";
	return "./data.csv";
}

int main(int argc, char** argv) {
	_printBitcoinExchange();
	try {
		if (argc != 2)
			throw Error::error(ARG_NUM_ERR, __func__, __FILE__, __LINE__);
		BitcoinExchange btc(_judgeDataPath());
		btc.exchange(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
