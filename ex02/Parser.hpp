/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:00:01 by jgo               #+#    #+#             */
/*   Updated: 2023/09/05 17:23:01 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Parser.h"

class Parser {
   private:
	typedef enum e_args { NONE, NUM, WHITESPACE } t_args;

	static const std::string kNum;
	static const std::string kOper;
	static const std::string kWhiteSpace;
	static const std::string kFull;

	Parser(const Parser& obj);
	Parser& operator=(const Parser& obj);
	Parser();
	const int _ac;
	const char** _av;
	std::vector<int> _jacobsthal;

	std::vector<int> makeJacobSthalVec(const int& n);
	static int makeJacobSthalNum(const int& n);

   public:
	Parser(const int& ac, const char**& av);
	~Parser();
	int getAc(void) const;
	std::vector<int> getJacobsthal(void) const;
	static void _checkAv(const int& ac, const char**& av);
	static bool _containsNone(const std::string& str, const std::string& chars);
	static bool _containsAny(const std::string& str, const std::string& chars);
	static bool _containsNone(const std::string& str, const char& c);
	static bool _containsAny(const std::string& str, const char& c);
	static void _ParseVec(std::vector<std::pair<int, int> >& vec, const int& ac, const char**& av);
	static void _ParseDeq(std::deque<std::pair<int, int> >& deq, const int& ac, const char**& av);
	static void _ParseList(std::list<int>& list, const int& ac, const char**& av);
};

std::ostream& operator<<(std::ostream& os, const Parser& obj);
#endif
