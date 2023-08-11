/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:13:17 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 17:04:32 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

Error::Error() {
	VERBOSE(ERR_DFLT_CTOR);
}
Error::Error(const Error& obj) {
	VERBOSE(ERR_CPY_CTOR);
	*this = obj;
}
Error::Error(const char* prompt, const char* func, const char* file, const int line)
	: _prompt(prompt),
	  _func(func),
	  _file(file),
	  _full(_file + ":" + intToString(line) + ": " + RED + "error: " RESET + _prompt + " in function: " GREEN + _func +
			RESET) {
	VERBOSE(ERR_CTOR);
}
Error::~Error() throw() {
	VERBOSE(ERR_DTOR);
}
Error& Error::operator=(const Error& obj) {
	VERBOSE(ERR_CPY_ASGMT_OP_CALL);
	if (this != &obj) {
		*const_cast<std::string*>(&this->_file) = obj._file;
		*const_cast<std::string*>(&this->_func) = obj._func;
		*const_cast<std::string*>(&this->_prompt) = obj._prompt;
		*const_cast<std::string*>(&this->_full) = obj._full;
	}
	return (*this);
}

const char* Error::what() const throw() {
	return _full.c_str();
}

const Error Error::error(const char* msg, const char* func, const char* file, const int line) {
	return Error(msg, func, file, line);
}

std::string Error::intToString(const int& num) {
	std::ostringstream os;
	os << num;
	return os.str();
}
