/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AmyContainer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:25:37 by jgo               #+#    #+#             */
/*   Updated: 2023/09/04 12:26:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMYCONTAINER_HPP
#define AMYCONTAINER_HPP

#include "AmyContainer.h"

class AmyContainer {
   protected:
	int _last;
	std::clock_t _elapsed_time;

	typedef enum type { A, B } chain_type;

	template <typename Container, typename Iter>
	void sortPair(Container& cont) {
		for (Iter it = cont.begin(); it != cont.end(); ++it) {
			Iter idx = it;
			for (Iter jt = it + 1; jt != cont.end(); ++jt) {
				if (jt->first < idx->first)
					idx = jt;
			}
			std::iter_swap(it, idx);
		}
	}

   public:
	AmyContainer();
	AmyContainer(const AmyContainer& obj);
	virtual ~AmyContainer();
	AmyContainer& operator=(const AmyContainer& obj);

	std::clock_t getElapsedTime(void) const;
	int getLast(void) const;
	void setLast(const int last);
	void setElapsedTime(const std::clock_t time);
	virtual void FJmergeInsertionsort(const int& ac, const char**& av) = 0;
};

#endif
