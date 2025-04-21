/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:12:37 by tle-goff          #+#    #+#             */
/*   Updated: 2025/03/31 11:32:45 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	identify(Base * p) {
	if (dynamic_cast<A *>(p))
		std::cout << "The pointer is a A type." << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "The pointer is a B type." << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "The pointer is a C type." << std::endl;
}

void	identify(Base & p) {
	try {
		A &	a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "The pointer is a A type." << std::endl;
	}
	catch(const std::exception& e) {}
	try {
		B &	b = dynamic_cast<B &>(p);
		(void) b;
		std::cout << "The pointer is a B type." << std::endl;
	}
	catch(const std::exception& e) {}
	try {
		C &	c = dynamic_cast<C &>(p);
		(void) c;
		std::cout << "The pointer is a C type." << std::endl;
	}
	catch(const std::exception& e) {}
}

Base *	generate() {
	Base *	ptr;
	ptr = NULL;
	srand(time(NULL));

	int n = rand() % 3;

	if (n == 2) {
		ptr = new A;
		std::cout << "New A created." << std::endl;
	}
	else if (n == 1) {
		ptr = new B;
		std::cout << "New B created." << std::endl;
	}
	else if (n == 0) {
		ptr = new C;
		std::cout << "New C created." << std::endl;
	}
	return ptr;
}

int	main() {
	Base *	ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;

	return 0;
}
