/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:53:39 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/15 11:19:38 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include "iostream"
#include "string"
#include "stack"
#include "list"

template<class T>
class MutantStack : public std::stack<T> {

	public:
		MutantStack();
		MutantStack(MutantStack const &src);
		~MutantStack();

		MutantStack<T>	&operator=(MutantStack<T> const &src);
		typedef	typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin();
		iterator	end();

	private:

};

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src) {}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &src) {
    if (this != &src) {
        std::stack<T>::operator=(src);
    }
    return *this;
}

template<typename T>
typename	MutantStack<T>::iterator MutantStack<T>::begin() {
	return (std::stack<T>::c.begin());
}

template<typename T>
typename	MutantStack<T>::iterator MutantStack<T>::end() {
	return (std::stack<T>::c.end());
}

#endif
