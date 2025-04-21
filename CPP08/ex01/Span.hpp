/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:59:27 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/02 15:39:57 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "vector"

class Span {

	public:
		Span(unsigned int N);
		~Span();

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();

		class MaxNumberException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class DistanceException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::vector<int>	_numbers;
		unsigned int		_max;

};
