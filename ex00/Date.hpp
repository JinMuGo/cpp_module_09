/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:04:30 by jgo               #+#    #+#             */
/*   Updated: 2023/07/27 16:17:10 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP

#include "Date.h"

class Date {
   private:
   public:
	Date();
	Date(const Date& obj);
	~Date();
	Date& operator=(const Date& obj);
};

#endif

