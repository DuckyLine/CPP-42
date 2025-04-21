/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:36:20 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/15 11:27:40 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	BitCoinExchange	BitCoin;

	if (argc == 2)
		BitCoin.readFile(argv[1]);
	else
		std::cout << "Erreur\nPlease use ./btc <Name Of File>" << std::endl;

	return (0);
}
