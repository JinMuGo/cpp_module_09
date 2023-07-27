/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:13:17 by jgo               #+#    #+#             */
/*   Updated: 2023/07/27 17:54:42 by jgo              ###   ########.fr       */
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
Error::Error(const char* prompt, const char* func, const char* file)
	: _prompt(prompt),
	  _func(func),
	  _file(file),
	  _full(_file + ": " RED + "error: " RESET + _prompt + " in function: " + _func) {
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
	}
	return (*this);
}

const char* Error::what() const throw() {
	return _full.c_str();
}
