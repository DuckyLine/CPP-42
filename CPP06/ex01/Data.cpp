/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:51:30 by tle-goff          #+#    #+#             */
/*   Updated: 2025/03/31 11:00:14 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): _size(10) {
	std::cout << "Data has created !" << std::endl;
}

Data::Data(Data const &src) {
	std::cout << "Data has copy !" << std::endl;
	*this = src;
}

Data::~Data() {
	std::cout << "Data has delete !" << std::endl;
}

Data &	Data::operator=(Data const &rSym) {
	if (this != &rSym) {
		this->_size = rSym._size;
	}
	return (*this);
}

int	Data::getSize() const {
	return (this->_size);
}
