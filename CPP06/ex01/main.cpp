/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:35:18 by tle-goff          #+#    #+#             */
/*   Updated: 2025/03/31 10:59:48 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data *		data = new Data;
	uintptr_t	raw;

	std::cout << data << std::endl;

	raw = Serializer::serialize(data);

	std::cout << raw << std::endl;

	data = Serializer::deserialize(raw);

	std::cout << data << std::endl;

	delete data;
	return 0;
}
