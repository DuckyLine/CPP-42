/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:49:03 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/23 12:31:32 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "iostream"

template< typename T >
void	print_arg(T& c)
{
	std::cout << c << std::endl;
}

int main( void ) {
	char test[7] = {'c', 'o', 'u', 'c', 'o', 'u', '\0'};

	::iter( test, 6, print_arg );
	return (0);
}
