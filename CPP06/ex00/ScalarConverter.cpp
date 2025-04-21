/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:00:54 by tle-goff          #+#    #+#             */
/*   Updated: 2025/03/31 10:28:24 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	convertInt(std::string param) {
	return (std::atoi(param.c_str()));
}

float convertFloat(std::string param) {
	return static_cast<float>(std::atof(param.c_str()));
}

double convertDouble(std::string param) {
	return std::atof(param.c_str());
}

void	printParam(int integer, float floats, double doubles) {
	if (integer <= 0 || integer >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(integer) << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << floats << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << doubles << std::endl;
}

void	checkParam(std::string param) {
	int	len = param.length();

	if (param == "nan")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
		return ;
	}
	if ((len >= 1 && (param[0] == '-' || param[0] == '+') && param[1] >= '0' && param[1] <= '9')
		|| (len >= 0 && param[0] >= '0' && param[0] <= '9'))
	{
		if (len > 0 && ((param[len - 1] >= '0' && param[len - 1] <= '9') || param[len - 1] == 'f'))
			printParam(convertInt(param), convertFloat(param), convertDouble(param));
		else
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	}
	else if (std::isprint(param[0]) && len == 1)
	{
		char	charactere = param[0];
		std::string newParam(1, charactere);
		printParam(static_cast<int>(charactere), static_cast<int>(charactere), static_cast<int>(charactere));
	}
	else
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return ;
	}
}

void ScalarConverter::convert(std::string param) {
	checkParam(param);
}

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter has created !" << std::endl;
}

// ScalarConverter::ScalarConverter(ScalarConverter const &src) {
// 	std::cout << "ScalarConverter has copy !" << std::endl;
// }

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter has delete !" << std::endl;
}
