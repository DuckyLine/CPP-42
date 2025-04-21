/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:18:16 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/15 11:39:39 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "cstdlib"
#include "map"
#include "iomanip"
#include "sstream"

class BitCoinExchange {

	public:
		BitCoinExchange();
		~BitCoinExchange();
		BitCoinExchange(BitCoinExchange const &src);

		BitCoinExchange	&operator=(BitCoinExchange const &src);
		int	readFile(const char *name);

};

#endif
