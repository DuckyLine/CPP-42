/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:48:25 by tle-goff          #+#    #+#             */
/*   Updated: 2025/03/31 11:52:54 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

template <typename T>
void swap(T &a, T&b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b) {
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T max(T a, T b) {
	if (a > b)
		return (a);
	return (b);
}
