/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:58:21 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/17 13:12:56 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	PmergeMe	obj;

	if (argc > 1) {
		obj.setDeque(argv);
		obj.setList(argv);
	}
	return (0);
}
