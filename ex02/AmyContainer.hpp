/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AmyContainer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:25:37 by jgo               #+#    #+#             */
/*   Updated: 2023/08/01 12:42:25 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMYCONTAINER_HPP
#define AMYCONTAINER_HPP

#include "AmyContainer.h"

class AmyContainer {
   private:
	const int& _ac;
	const char**& _av;
	std::clock_t _elapsed_time;

	AmyContainer();

   public:
	AmyContainer(const AmyContainer& obj);
	AmyContainer(const int& ac, const char**& av);
	virtual ~AmyContainer();
	AmyContainer& operator=(const AmyContainer& obj);

	int getAc(void) const;
	const char**& getAv(void) const;
	std::clock_t getElapsedTime(void) const;
	void setElapsedTime(const std::clock_t time);
	virtual void FJmergeInsertionsort(const int& ac, const char**& av) = 0;
};

#endif
