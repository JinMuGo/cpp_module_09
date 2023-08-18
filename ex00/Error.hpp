/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:11:41 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 16:56:27 by jgo              ###   ########.fr       */
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
	Error();

   public:
	Error(const Error& obj);
	Error(const char* prompt, const char* func, const char* file, const int line);
	virtual ~Error() throw();
	Error& operator=(const Error& obj);
	static std::string intToString(const int& num);
	const char* what() const throw();
	static const Error error(const char* msg, const char* func, const char* file, const int line);
};

#endif
