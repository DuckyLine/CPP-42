/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:59:24 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/01 19:17:01 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N): _max(N) {
	std::cout << "Span has create !" << std::endl;
}

Span::~Span() {
	std::cout << "Span has delete !" << std::endl;
}

void	Span::addNumber(int n) {
	std::cout << "Span addNumber !" << std::endl;
	if (this->_max > this->_numbers.size())
		this->_numbers.push_back(n);
	else
		throw Span::MaxNumberException();
}

int	Span::longestSpan() {
	int	length = this->_numbers.size();
	int	min = -1;
	int	max = -1;

	for (int i = 0; i < length;i++)
	{
		if (i == 0)
			min = this->_numbers[0];
		else if (min > this->_numbers[i])
			min = this->_numbers[i];
	}
	for (int i = 0; i < length;i++)
	{
		if (i == 0)
			max = this->_numbers[0];
		else if (min < this->_numbers[i])
			max = this->_numbers[i];
	}
	if (max - min <= 0)
		throw Span::DistanceException();
	return (max - min);
}

int	Span::shortestSpan() {
	int	length = this->_numbers.size();
	int	small = -1;

	for (int i = 0; i < length;i++)
	{
		for (int j = 0;j < length;j++)
		{
			if ((this->_numbers[i] - this->_numbers[j]) > 0)
			{
				if ((this->_numbers[i] - this->_numbers[j]) < small || small == -1)
					small = this->_numbers[i] - this->_numbers[j];
			}
			if (this->_numbers[i] < 0 && this->_numbers[j] < 0)
			{
				int	tmp1 = this->_numbers[i] * -1;
				int	tmp2 = this->_numbers[j] * -1;
				if (((tmp1 - tmp2) < small || small == -1) && tmp1 - tmp2 > 0)
					small = tmp1 - tmp2;
				else if (((tmp2 - tmp1) < small || small == -1) && tmp1 - tmp2 > 0)
					small = tmp1 - tmp2;
			}
		}
	}
	if (small <= 0)
		throw Span::DistanceException();
	return (small);
}

const char	*Span::MaxNumberException::what() const throw() {
	return ("Error: max number exception !");
}

const char	*Span::DistanceException::what() const throw() {
	return ("Error: distance exception !");
}
