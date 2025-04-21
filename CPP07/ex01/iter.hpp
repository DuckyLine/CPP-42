/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:18:28 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/01 12:48:09 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T, typename Func>
void	iter(T* adress, int length, Func fonction) {
	int	i = 0;

	while (i < length)
	{
		fonction(adress[i]);
		i++;
	}
}
