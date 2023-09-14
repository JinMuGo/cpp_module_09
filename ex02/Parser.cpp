/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:00:56 by jgo               #+#    #+#             */
/*   Updated: 2023/09/14 18:25:53 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

const std::string Parser::kNum = "0123456789";
const std::string Parser::kOper = "-+";
const std::string Parser::kFull = Parser::kNum + Parser::kOper;

Parser::Parser() : _ac(0), _av(NULL), _jacobsthal() {
	VERBOSE(PRS_DFLT_CTOR);
}

Parser::Parser(const int& ac, const char**& av) : _ac(ac), _av(av), _jacobsthal() {
	VERBOSE(PRS_CTOR);
	this->_checkAv(ac, av);
	this->_jacobsthal = this->makeJacobSthalVec(ac / 2);
}

Parser::Parser(const Parser& obj) : _ac(obj._ac), _av(obj._av) {
	VERBOSE(PRS_CPY_CTOR);
};

Parser::~Parser() {
	VERBOSE(PRS_DTOR);
}

Parser& Parser::operator=(const Parser& obj) {
	VERBOSE(PRS_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		const_cast<int&>(this->_ac) = obj._ac;
		const_cast<char**&>(this->_av) = const_cast<char**&>(obj._av);
		this->_jacobsthal = obj._jacobsthal;
	}
	return (*this);
}

int Parser::makeJacobSthalNum(const int& n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 3;
	return makeJacobSthalNum(n - 1) + 2 * makeJacobSthalNum(n - 2);
}

std::vector<int> Parser::makeJacobSthalVec(const int& n) {
	std::vector<int> rv;
	if (n <= 1)
		return rv;
	int jacobStahalNum;
	int idx = 0;

	while (true) {
		jacobStahalNum = Parser::makeJacobSthalNum(idx++);
		if (jacobStahalNum >= n) {
			rv.push_back(n);
			break;
		} else
			rv.push_back(jacobStahalNum);
	}
	return rv;
}

int Parser::getAc(void) const {
	return this->_ac;
}

std::vector<int> Parser::getJacobsthal(void) const {
	return this->_jacobsthal;
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

void Parser::_isValidArg(const char* arg, char* endptr) {
	const long int check = std::strtol(arg, &endptr, 10);

	for (int i = 0; arg[i]; ++i) {
		if (Parser::_containsAny(Parser::kFull, arg[i]) == false)
			throw Error::error(INVALID_ARGS, __func__, __FILE__, __LINE__);
	}
	if (*endptr == '+' || *endptr == '-')
		throw Error::error(INVALID_ARGS, __func__, __FILE__, __LINE__);
	if (std::strlen(arg) > 10 || check <= 0 || std::numeric_limits<int>::max() < check)
		throw Error::error(INVALID_RANGE, __func__, __FILE__, __LINE__);
}

void Parser::_checkAv(const int& ac, const char**& av) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	char* endptr = NULL;
	for (int i = 1; i < ac; ++i)
		Parser::_isValidArg(av[i], endptr);
}

void Parser::_ParseVec(std::vector<std::pair<int, int> >& vec, const int& ac, const char**& av) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	int i = 1;
	while (i < ac - 1) {
		const int lhs = std::atoi(av[i]);
		const int rhs = std::atoi(av[i + 1]);
		if (lhs > rhs)
			vec.push_back(std::make_pair(lhs, rhs));
		else
			vec.push_back(std::make_pair(rhs, lhs));
		i += 2;
	}
	if (i != ac)
		vec.push_back(std::make_pair(-1, std::atoi(av[i])));
}

void Parser::_ParseDeq(std::deque<std::pair<int, int> >& deq, const int& ac, const char**& av) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	int i = 1;
	while (i < ac - 1) {
		const int lhs = std::atoi(av[i]);
		const int rhs = std::atoi(av[i + 1]);
		if (lhs > rhs)
			deq.push_back(std::make_pair(lhs, rhs));
		else
			deq.push_back(std::make_pair(rhs, lhs));
		i += 2;
	}
	if (i != ac)
		deq.push_back(std::make_pair(-1, std::atoi(av[i])));
}

void Parser::_ParseList(std::list<int>& list, const int& ac, const char**& av) {
	VERBOSE(PRS_MEMBER_FUNC_CALL);
	for (int i = 1; i < ac; ++i)
		list.push_back(std::atoi(av[i]));
}

std::ostream& operator<<(std::ostream& os, const Parser& obj) {
	return os << "Time to process a range of " << obj.getAc() - 1;
}