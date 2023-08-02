/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:00:56 by jgo               #+#    #+#             */
/*   Updated: 2023/08/02 11:08:13 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

const std::string Parser::kNum = "0123456789";
const std::string Parser::kOper = "-+";
const std::string Parser::kWhiteSpace = " \t\n\v\f\r";
const std::string Parser::kFull = Parser::kNum + Parser::kOper + Parser::kWhiteSpace;

Parser::Parser() {
	VERBOSE(PRS_DFLT_CTOR);
}

Parser::Parser(const Parser& obj) {
	VERBOSE(PRS_CPY_CTOR);
	*this = obj;
};

Parser::~Parser() {
	VERBOSE(PRS_DTOR);
}

Parser& Parser::operator=(const Parser& obj) {
	VERBOSE(PRS_CPY_ASGMT_OP_CALL);
	if (this != &obj)
		return (*this);
	return (*this);
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

void Parser::_checkAv(const int& ac, const char**& av) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	for (int i = 1; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j) {
			if (_containsAny(Parser::kFull, av[i][j]) == false)
				throw Error::error(INVALID_ARGS, __func__, __FILE__);
			// overflow check? 
		}
		if (std::atoi(av[i]) == 0)
			throw Error::error(INVALID_ARGS, __func__, __FILE__);
	}
}

void Parser::_ParseVec(std::vector<int>& vec, const int& ac, const char**& av) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	for (int i = 1; i < ac; ++i)
		vec.push_back(std::atoi(av[i]));
}

void Parser::_ParseDeq(std::deque<int>& deq, const int& ac, const char**& av) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	for (int i = 1; i < ac; ++i)
		deq.push_back(std::atoi(av[i]));
}

void Parser::_ParseList(std::list<int>& list, const int& ac, const char**& av) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	for (int i = 1; i < ac; ++i)
		list.push_back(std::atoi(av[i]));
}
