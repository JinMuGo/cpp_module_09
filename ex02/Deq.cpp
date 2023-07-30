/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:23:10 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 18:13:52 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Deq.hpp"

Deq::Deq() : std::deque<int>() {
	VERBOSE(DEQ_DFLT_CTOR);
}
Deq::Deq(const Deq& obj) : std::deque<int>() {
	VERBOSE(DEQ_CTOR);
}
Deq::~Deq() {
	VERBOSE(DEQ_DTOR);
}
Deq& Deq::operator=(const Deq& obj) {
	VERBOSE(DEQ_CPY_ASGMT_OP_CALL);
}

