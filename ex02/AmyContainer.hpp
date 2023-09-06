/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AmyContainer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:25:37 by jgo               #+#    #+#             */
/*   Updated: 2023/09/06 19:42:00 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMYCONTAINER_HPP
#define AMYCONTAINER_HPP

#include "AmyContainer.h"

class AmyContainer {
   protected:
	std::clock_t _elapsed_time;

	typedef std::deque<std::pair<int, int> > deqPair;
	typedef std::deque<std::pair<int, int> >::iterator deqPairIter;
	typedef std::deque<int>::iterator deqIter;
	typedef std::deque<int>::const_iterator deqCIter;

	typedef std::vector<std::pair<int, int> > vecPair;
	typedef std::vector<std::pair<int, int> >::iterator vecPairIter;
	typedef std::vector<int>::iterator vecIter;
	typedef std::vector<int>::const_iterator vecCIter;

	template <typename Container, typename Iter>
	void sortPair(Container& cont) {
		for (Iter it = cont.begin(); it != cont.end(); ++it) {
			Iter idx = it;
			if (idx->first == -1)
				continue;
			for (Iter jt = it + 1; jt != cont.end(); ++jt) {
				if (jt->first == -1)
					continue;
				if (jt->first < idx->first)
					idx = jt;
			}
			std::iter_swap(it, idx);
		}
	}

	template <typename srcCont, typename dstCont>
	void initMainChain(const srcCont& src, dstCont& dst) {
		// maybe error handling
		for (std::size_t i = 0; i < src.size(); ++i)
		{
			if (src[i].first == -1)
				continue;
			dst.push_back(src[i].first);
		}
		dst.insert(dst.begin(), src[0].second);	 // b1 < a1
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
	virtual void FJmergeInsertionsort(const int& ac, const char**& av, const Parser& parser) = 0;
};

#endif
