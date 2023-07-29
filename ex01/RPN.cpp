/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:40:56 by jgo               #+#    #+#             */
/*   Updated: 2023/07/29 19:52:52 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _arg(NULL) {
	VERBOSE(RPN_DFLT_CTOR);
}

RPN::RPN(const RPN& obj): _stack(obj._stack), _arg(obj._arg) {
	VERBOSE(RPN_CPY_CTOR);

}

RPN::RPN(const std::string& arg) : _arg(arg) {
	VERBOSE(RPN_CTOR);
}
RPN::~RPN() {
	VERBOSE(RPN_DTOR);
}

RPN& RPN::operator=(const RPN& obj) {
	VERBOSE(RPN_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		*const_cast<std::string*>(&this->_arg) = obj._arg;
		this->_stack = obj._stack;
	}
	return (*this);
}

const Error RPN::error(const char* msg, const char* func, const char* file) {
	return Error(msg, func, file);
}

bool RPN::containsNone(const std::string& str, const std::string& chars) {
	for (std::string::const_iterator cit = str.begin(); cit != str.end(); ++cit) {
		if (chars.find(*cit) == std::string::npos)
			return false;
	}
	return true;
}

bool RPN::containsNone(const std::string& str, const char& c) {
	if (str.find(c) == std::string::npos)
		return true;
	return false;
}
bool RPN::containsAny(const std::string& str, const char& c) {
	if (str.find(c) != std::string::npos)
		return true;
	return false;
}

Args::t_args RPN::judgeArgType(const char& c) {
	if (containsAny(Args::num, c))
		return Args::NUM;
	if (containsAny(Args::oper, c))
		return Args::OPER;
	if (containsAny(Args::whiteSpace, c))
		return Args::WHITESPACE;
	return Args::NONE;
}

const int& RPN::popStack(void) {
	if (_stack.empty())
		throw error(STACK_EMPTY, __func__, __FILE__);
	const int& elem = _stack.top();
	_stack.pop();
	return elem;
}

void RPN::processOper(const char& oper) {
	const int& second = popStack();
	const int& first = popStack();

	switch (oper) {
		case '+':
			_stack.push(first + second);
			break;
		case '-':
			_stack.push(first - second);
			break;
		case '*':
			_stack.push(first * second);
			break;
		case '/':
			if (second == 0)
				throw error(ZERO_DIVIDE, __func__, __FILE__);
			_stack.push(first / second);
			break;
		default:
			break;
	}
}

int RPN::process(void) {
	if (containsNone(this->_arg, Args::full) == false)
		throw error(INVALID_ARGS, __func__, __FILE__);
	for (std::string::const_iterator cit = _arg.begin(); cit != _arg.end(); ++cit) {
		switch (judgeArgType(*cit)) {
			case Args::NUM:
				_stack.push((*cit) - '0');
				break;
			case Args::OPER:
				processOper(*cit);
				break;
			default:
				continue;
		}
	}
	const int res = popStack();
	if (_stack.empty() == false)
		throw error(INVALID_ARGS, __func__, __FILE__);
	return res;
}
