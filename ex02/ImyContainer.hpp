/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ImyContainer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:25:37 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 23:32:20 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMYCONTAINER_HPP
#define IMYCONTAINER_HPP

#include "ImyContainer.h"

class ImyContainer {
   private:
	const int& _ac;
	const char**& _av;
	std::clock_t _elapsed_time;

	ImyContainer();

   public:
	ImyContainer(const ImyContainer& obj);
	ImyContainer(const int& ac, const char**& av);
	virtual ~ImyContainer();
	ImyContainer& operator=(const ImyContainer& obj);

	const int getAc(void) const;
	const char**& getAv(void) const;
	std::clock_t getElapsedTime(void) const;
	void setElapsedTime(const std::clock_t time);
	virtual void FJmergeInsertionsort() = 0;
};

#endif
