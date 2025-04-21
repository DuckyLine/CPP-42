/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:24:33 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/17 13:06:14 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include "algorithm"
#include "iostream"
#include "cstdlib"
#include "iomanip"
#include "deque"
#include "list"
#include "time.h"

class PmergeMe {

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &src);

		PmergeMe &operator=(PmergeMe const &src);
		int	setList(char **argv);
		int	setDeque(char **argv);

};

#endif
