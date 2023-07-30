/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:00:56 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 17:39:17 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser() {
	VERBOSE(PRS_DFLT_CTOR);
}
Parser::Parser(const Parser& obj) {
	VERBOSE(PRS_CPY_CTOR);
}
Parser::~Parser() {
	VERBOSE(PRS_DTOR);
}
Parser& Parser::operator=(const Parser& obj) {
	VERBOSE(PRS_CPY_ASGMT_OP_CALL);
}

bool Parser::_containsNone(const std::string& str, const std::string& chars) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	for (std::string::const_iterator cit = str.begin(); cit != str.end(); ++cit) {
		if (chars.find(*cit) == std::string::npos)
			return false;
	}
	return true;
}

bool Parser::_containsAny(const std::string& str, const std::string& chars) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	for (std::string::const_iterator cit = str.begin(); cit != str.end(); ++cit) {
		if (chars.find(*cit) != std::string::npos)
			return true;
	}
	return false;
}

bool Parser::_containsNone(const std::string& str, const char& c) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	if (str.find(c) == std::string::npos)
		return true;
	return false;
}
bool Parser::_containsAny(const std::string& str, const char& c) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	if (str.find(c) != std::string::npos)
		return true;
	return false;
}

inline void Parser::_ParseVec(std::vector<int>& vec, char** av) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
}

inline void Parser::_ParseDeq(std::deque<int>& deq, char** av) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
}
