/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:23:02 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/01 20:03:20 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span	array(10);

	try {
		Span array(5);

		array.addNumber(-5);
		array.addNumber(-10);

		// array.addNumber(42);
		try {
			std::cout << "short: " << array.shortestSpan() << std::endl;
			std::cout << "long: " << array.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "Exception attrapée : " << e.what() << std::endl;
		}

	} catch (const std::exception &e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}

	return (0);
}
