/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:00:01 by jgo               #+#    #+#             */
/*   Updated: 2023/09/14 18:24:56 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Parser.h"

class Parser {
   private:
	static const std::string kNum;
	static const std::string kOper;
	static const std::string kFull;

	Parser(const Parser& obj);
	Parser& operator=(const Parser& obj);
	Parser();
	const int _ac;
	const char** _av;

   public:
	Parser(const int& ac, const char**& av);
	~Parser();
	int getAc(void) const;
	static std::vector<int> _makeJacobSthalVec(const int n);
	static int _makeJacobSthalNum(const int n);
	static void _isValidArg(const char* arg, char* endptr);
	static void _checkAv(const int& ac, const char**& av);
	static bool _containsNone(const std::string& str, const std::string& chars);
	static bool _containsAny(const std::string& str, const std::string& chars);
	static bool _containsNone(const std::string& str, const char& c);
	static bool _containsAny(const std::string& str, const char& c);
	static void _makeVecPair(std::vector<std::pair<int, int> >& vec, const int& ac, const char**& av);
	static void _makeDeqPair(std::deque<std::pair<int, int> >& deq, const int& ac, const char**& av);
};

std::ostream& operator<<(std::ostream& os, const Parser& obj);
#endif
