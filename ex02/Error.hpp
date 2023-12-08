/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:11:41 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 17:04:49 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
#define ERROR_HPP

#include "Error.h"

class Error : public std::exception {
   private:
	const std::string _prompt;
	const std::string _func;
	const std::string _file;
	const std::string _full;
	int _status;
	Error();

   public:
	Error(const Error& obj);
	Error(const char* prompt, const char* func, const char* file, const int line);
	Error(const char* prompt, const char* func, const char* file, const int line, const int status);
	virtual ~Error() throw();
	Error& operator=(const Error& obj);
	static std::string intToString(const int& num);
	static const Error error(const char* msg, const char* func, const char* file, const int line);
	static const Error error(const char* msg, const char* func, const char* file, const int line, const int status);
	const char* what() const throw();
	int getStatus() const;
};

#endif
