/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:27:23 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/01 17:58:41 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include "iostream"

template<typename T>
int	easyfind(T *obj, int n) {
	for (int i = 0; obj[i]; i++)
	{
		if (obj[i] == n)
			return (i);
	}
	return (-1);
}

#endif
