/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:00:01 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 23:27:48 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Parser.h"

class Parser {
   private:
	typedef enum e_args { NONE, NUM, WHITESPACE } t_args;

	static const std::string num;
	static const std::string whiteSpace;
	static const std::string full;

	Parser(const Parser& obj);
	~Parser();
	Parser& operator=(const Parser& obj);
	Parser();
   public:
	static inline bool _containsNone(const std::string& str, const std::string& chars);
	static inline bool _containsAny(const std::string& str, const std::string& chars);
	static inline bool _containsNone(const std::string& str, const char& c);
	static inline bool _containsAny(const std::string& str, const char& c);
	static inline void _ParseVec(std::vector<int> &vec, const char **&av);
	static inline void _ParseDeq(std::deque<int> &deq, const char **&av);
};

const std::string Parser::num = "0123456789";
const std::string Parser::whiteSpace = " \t\n\v\f\r";
const std::string Parser::full = Parser::num + Parser::whiteSpace;

#endif
