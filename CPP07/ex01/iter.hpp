/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:18:28 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/23 12:13:40 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void	iter(T* adress, int length, void (*fonct)(T&)) {
	int	i = 0;

	while (i < length)
	{
		fonct(adress[i]);
		i++;
	}
}

template<typename T>
void	iter(const T* adress, int length, void (*fonct)(const T&)) {
	int	i = 0;

	while (i < length)
	{
		fonct(adress[i]);
		i++;
	}
}
