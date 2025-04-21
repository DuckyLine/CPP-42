/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:55:29 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/01 13:42:16 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

template<typename T>
class Array {

	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		~Array();

		Array &	operator=(Array const &ref);

		T	operator[](int n) const;
		T&	operator[](int n);

		int	size() const;

		class OutOfBoundException : public std::exception {

			public:
				virtual const char* what() const throw();

		};

	private:
		T*	_array;
		int	_size;

};

extern template class Array<int>;

#endif
