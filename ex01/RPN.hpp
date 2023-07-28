/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:41:01 by jgo               #+#    #+#             */
/*   Updated: 2023/07/28 18:41:08 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

class RPN {
   private:
   public:
	RPN();
	RPN(const RPN& obj);
	~RPN();
	RPN& operator=(const RPN& obj);
};

#endif
