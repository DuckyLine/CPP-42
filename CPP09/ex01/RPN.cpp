/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:11:19 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/16 15:24:43 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
	std::cout << "RPN has create !" << std::endl;
}

RPN::~RPN() {
	std::cout << "RPN has delete !" << std::endl;
}

RPN::RPN(RPN const &src) {
	*this = src;
}

RPN &RPN::operator=(RPN const &src) {
	if (this != &src) {
	}
	return (*this);
}

void	calcul(std::vector<std::pair<std::string, char> > operations) {
	int	result = 0;
	bool	target = false;

	for (std::vector<std::pair<std::string, char> >::iterator it = operations.begin(); it != operations.end(); ++it) {
		int	i = 0;
		while (it->first[i]) {
			if (it->first[i] == ' ' || i == 0) {
				if (target == false)
					result = std::atoi(&it->first[i]);
				else if (it->second == '-')
					result = result - std::atoi(&it->first[i]);
				else if (it->second == '+')
					result = result + std::atoi(&it->first[i]);
				else if (it->second == '*')
					result = result * std::atoi(&it->first[i]);
				else if (it->second == '/')
					result = result / std::atoi(&it->first[i]);
			}
			target = true;
			i++;
		}
	}
	std::cout << result << std::endl;
}

int	RPN::decomp(char *line) {
	bool										target = true;
	std::vector<std::pair<std::string, char> >	operations;
	int											tmp = 0;
	int											i = 0;

	while (line[i]) {
		if (line[i] == '*' || line[i] == '-' || line[i] == '/' || line[i] == '+') {
			if (target == false)
				return (std::cout << "0\n", 1);
			std::string sub(line + tmp, i - tmp - 1);
			operations.push_back(std::make_pair(sub, line[i]));
			tmp = i + 2;
			target = false;
		}
		else if (line[i] >= '0' && line[i] <= '9')
			target = true;
		else if (line[i] != ' ')
			return (std::cout << "Error\n", 1);
		i++;
	}
	calcul(operations);
	return (0);
}
