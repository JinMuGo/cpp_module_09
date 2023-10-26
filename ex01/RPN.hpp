/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:41:01 by jgo               #+#    #+#             */
/*   Updated: 2023/08/11 17:02:10 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include "RPN.h"

namespace Args {

	typedef enum e_args { NONE, NUM, OPER, WHITESPACE } t_args;

	const std::string num = "0123456789";
	const std::string oper = "+-*/";
	const std::string whiteSpace = " \t\n\v\f\r";
	const std::string full = num + oper + whiteSpace;

}  // namespace Args

class RPN {
   private:
	std::stack<int> _stack;
	const std::string _arg;
	RPN();

   public:
	RPN(const std::string& arg);
	RPN(const RPN& obj);
	~RPN();
	RPN& operator=(const RPN& obj);

	static bool containsNone(const std::string& str, const std::string& chars);
	static bool containsAny(const std::string& str, const std::string& chars);
	static bool containsNone(const std::string& str, const char& c);
	static bool containsAny(const std::string& str, const char& c);
	static Args::t_args judgeArgType(const char& c);

	const int& popStack(void);
	void processOper(const char& oper);
	int process(void);
};

#endif
