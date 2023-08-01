/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:00:01 by jgo               #+#    #+#             */
/*   Updated: 2023/08/01 17:14:13 by jgo              ###   ########.fr       */
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
	~Parser();
	Parser& operator=(const Parser& obj);
	Parser();

   public:
	static bool _containsNone(const std::string& str, const std::string& chars);
	static bool _containsAny(const std::string& str, const std::string& chars);
	static bool _containsNone(const std::string& str, const char& c);
	static bool _containsAny(const std::string& str, const char& c);
	static void _ParseVec(std::vector<int>& vec, const int& ac, const char**& av);
	static void _ParseDeq(std::deque<int>& deq, const int& ac, const char**& av);
	static void _ParseList(std::list<int>& list, const int& ac, const char**& av);
};

#endif
