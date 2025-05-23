/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:55:29 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/23 12:28:56 by tle-goff         ###   ########.fr       */
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

template<typename T>
Array<T>::Array(void) : _array(new T[0]), _size(0) {
	std::cout << "Array has created !" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int i) : _array(new T[i]), _size(i) {
	std::cout << "Array has created !" << std::endl;
}

template<typename T>
Array<T>::~Array(void) {
	std::cout << "Array has delete !" << std::endl;
	delete [] this->_array;
}

template<typename T>
Array<T>::Array(Array const &src) {
	std::cout << "Array has copy !" << std::endl;

	this->_size = src._size;
	this->_array = new T[src._size];
	for (int i = 0; i < src._size; i++) {
		this->_array[i] = src._array[i];
	}
}

template<typename T>
Array<T> &	Array<T>::operator=(Array<T> const &rSym) {
	if (this != &rSym) {
		delete [] this->_array;
		this->_array = new T[rSym._size];
		this->_size = rSym._size;
		for (int i = 0; i < rSym._size; i++)
			this->_array[i] = rSym._array[i];
	}
	return *this;
}

template<typename T>
T	Array<T>::operator[](int n) const {
	T	instance;
	if (n > this->_size - 1 || n < 0)
		throw Array<T>::OutOfBoundException();
	instance = this->_array[n];
	return (instance);
}

template<typename T>
T	&Array<T>::operator[](int n) {
	if (n > this->_size - 1 || n < 0)
		throw Array<T>::OutOfBoundException();
	return (this->_array[n]);
}

template<typename T>
int	Array<T>::size(void) const {
	return (this->_size);
}

template<typename T>
const char *Array<T>::OutOfBoundException::what() const throw() {
	return ("Value is out of bound !");
}

template class Array<int>;

#endif
