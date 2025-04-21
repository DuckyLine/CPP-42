/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:56 by tle-goff          #+#    #+#             */
/*   Updated: 2025/03/31 10:54:30 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

#include "iostream"

class Data {

	public:
		Data();
		Data(Data const &src);
		~Data();

		Data &	operator=(Data const &rSym);
		int	getSize() const;
	private:
		int	_size;

};

#endif
