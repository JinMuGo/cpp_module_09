/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:22:50 by jgo               #+#    #+#             */
/*   Updated: 2023/07/30 18:25:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec.hpp"

Vec::Vec(): std::vector<int>() {
	VERBOSE(VEC_DFLT_CTOR);
}
Vec::Vec(const Vec& obj): std::vector<int>() {
	VERBOSE(VEC_DFLT_CTOR);
}
Vec::~Vec() {
	VERBOSE(VEC_DTOR);
}
Vec& Vec::operator=(const Vec& obj) {
	VERBOSE(VEC_CPY_ASGMT_OP_CALL);
}

std::ostream& operator<<(std::ostream& os, const Vec& obj) {
	return os << "Time to process a range of " <<
}
