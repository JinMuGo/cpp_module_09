#ifndef VERBOSE_H
#define VERBOSE_H

#include "color.h"

#ifndef CHK_VER
#define CHK_VER(ver) (ver == 199711 ? "C++98" : "Not C++98")
#endif

#ifndef PRT_VER
#define PRT_VER std::cout << "cpp version: " YELLOW << CHK_VER(__cplusplus) << RESET "\n\n"
#endif

#ifndef V
#define V 0
#endif

#ifndef VERBOSE
#define VERBOSE(STR) \
	if (V)           \
		std::cout << STR << std::endl;
#endif

#ifndef VERBOSE_VAR
#define VERBOSE_VAR(VAR) \
	if (V)               \
		std::cout << #VAR << ": " << VAR << std::endl;
#endif

#ifndef VERBOSE_TWO_VARS
#define VERBOSE_TWO_VARS(VAR1, VAR2) \
	if (V)                           \
		std::cout << #VAR1 << ": " << VAR1 << " " << #VAR2 << ": " << VAR2 << std::endl;
#endif

#ifndef VERBOSE_CONTAINER
#define VERBOSE_CONTAINER(IT_TYPE, BEGIN, END)      \
	if (V) {                                        \
		for (IT_TYPE it = BEGIN; it != END; ++it) { \
			std::cout << *it << " ";                \
		}                                           \
		std::cout << std::endl;                     \
	}
#endif

#ifndef VERBOSE_CONTAINER2
#define VERBOSE_CONTAINER2(IT_TYPE, BEGIN, END)     \
	if (V) {                                        \
		for (IT_TYPE it = BEGIN; it != END; ++it) { \
			std::cout << **it << " ";               \
		}                                           \
		std::cout << std::endl;                     \
	}
#endif

#endif
