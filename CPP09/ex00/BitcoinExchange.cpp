/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:20:21 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/15 11:32:47 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitCoinExchange::BitCoinExchange() {
	std::cout << "BitCoin has create !" << std::endl;
}

BitCoinExchange::~BitCoinExchange() {
	std::cout << "BitCoin has delete !" << std::endl;
}

BitCoinExchange::BitCoinExchange(BitCoinExchange const &src) {
	*this = src;
}

BitCoinExchange& BitCoinExchange::operator=(BitCoinExchange const &src) {
	if (this != &src) {

	}
	return *this;
}

// Check first line
int	checkFirstLine(std::string line, std::string str) {
	if (line != str)
		return (1);
	return (0);
}

// Check parameters for data.csv
int	checkLine(std::string line) {
	int	count = 0;
	int	state = 0;
	int	step = 1;
	int	last = 0;
	int	i = 0;

	while (line[i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9')
			state = 1;
		if ((line[i] < '0' || line[i] > '9') && line[i] != '-' && line[i] != '.' && line[i] != ',')
			return (1);
		if (line[i] == '-')
		{
			if (count < 2 && state == 1) {
				count++;
				i++;
				continue;
			}
			else
				return (1);
			state = 0;
		}
		if (count == 2 && line[i] == ',' && step == 1) {
			step++;
			i++;
			continue;
		}
		else if (line[i] == ',')
			return (1);
		if (step == 2 && line[i] == '.' && last == 0) {
			last++;
			i++;
			continue;
		}
		else if (line[i] == '.')
			return (1);
		i++;
	}
	if (line[i - 1] < '0' || line[i - 1] > '9')
		return (1);
	return (0);
}

// Count other char
int	countT(std::string line, int i) {
	int j = 0;
	while (line[j + i] >= '0' && line[j + i] <= '9')
		j++;
	return (j);
}

// Check format data.csv
int	checkFormat(std::string line, std::map<std::string, float> &Map) {
	int	month = -1;
	int	year = -1;
	int	day = -1;
	float	n = -1.0;
	int	i = 0;

	year = std::atoi(line.c_str());
	i += countT(line, i) + 1;
	month = std::atoi(&line.c_str()[i]);
	i += countT(line, i) + 1;
	day = std::atoi(&line.c_str()[i]);
	i += countT(line, i) + 1;
	n = std::atof(&line.c_str()[i]);
	if (n < 0.0 || year < 0 || month < 0 || month > 12 || day < 0 || day > 31)
		return (1);

	std::ostringstream oss;
	oss << year << "-"
		<< std::setw(2) << std::setfill('0') << month << "-"
		<< std::setw(2) << std::setfill('0') << day;
	std::string dateKey = oss.str();

	Map[dateKey] = n;
	return (0);
}

// Check is data is valid for parameter
bool isValidDate(const std::string& date) {
	if (date.size() != 10) return false;
	if (!std::isdigit(date[0]) || !std::isdigit(date[1]) || !std::isdigit(date[2]) || !std::isdigit(date[3]) ||
		date[4] != '-' ||
		!std::isdigit(date[5]) || !std::isdigit(date[6]) ||
		date[7] != '-' ||
		!std::isdigit(date[8]) || !std::isdigit(date[9])) {
		return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12) return false;
	if (day < 1 || (month == 2 && day > (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) ? 29 : 28)) ||
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)) {
		return false;
	}
	return true;
}


// Print date
int	printConvert(std::map<std::string, float> Map, const char *name) {
	std::ifstream	file(name);

	if (!file.is_open()) {
		std::cout << "Error:\nCould not open in file !" << std::endl;
		return (1);
	}

	std::string	line;
	int			i = 0;
	while (std::getline(file, line)) {
		if (i == 0 && checkFirstLine(line, "date | value") == 1)
			return (1);
		if (i == 0) {
			i++;
			continue;
		}
		if (line.empty())
			return (1);
		i++;

		size_t delimiter_pos = line.find(" | ");
		std::string date = line.substr(0, delimiter_pos);
		if (delimiter_pos == std::string::npos) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (!isValidDate(date)) {
			std::cout << "Error: bad date => " << date << std::endl;
			continue;
		}
		std::string value_str = line.substr(delimiter_pos + 3);
		std::stringstream ss(value_str);
		float value = 0.0;
		ss >> value;
		if (value < 0.0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000.0) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		std::map<std::string, float>::iterator it = Map.lower_bound(date);
		if (it == Map.begin()) {
			std::cout << "No earlier date, using the earliest available: " << Map.begin()->first << " => "
					<< Map.begin()->second << std::endl;
			std::cout << date << " => " << value << " = " << Map.begin()->second * value << std::endl;
		} else if (it != Map.end() && it->first == date) {
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		} else {
			--it;
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		}
	}
	return (0);
}

// Read file
int	BitCoinExchange::readFile(const char *name) {
	std::ifstream	file("data.csv");

	if (!file.is_open()) {
		std::cout << "Error:\nCould not open in file !" << std::endl;
		return (1);
	}

	std::string	line;
	std::string	secondline;
	int			i = 0;
	std::map<std::string, float> Map;
	while (std::getline(file, line)) {
		if (i == 0 && checkFirstLine(line, "date,exchange_rate") == 1)
			return (1);
		if (i == 0) {
			i++;
			continue;
		}

		if (line.empty())
			return (1);
		if (checkLine(line) == 1 && i > 0)
			return (std::cout << line << " error" << std::endl, 1);
		if (checkFormat(line, Map) == 1 && i > 0)
			return (std::cout << line << " error" << std::endl, 1);
		i++;
	}
	printConvert(Map, name);
	return (0);
}
