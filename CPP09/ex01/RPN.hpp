/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:09:58 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/15 13:17:32 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include "iostream"
#include "cstdlib"
#include "cstring"
#include "string"
#include "vector"

class RPN {

	public:
		RPN();
		RPN(RPN const &src);
		~RPN();

		RPN	&operator=(RPN const &src);
		int	decomp(char *line);

};

#endif
