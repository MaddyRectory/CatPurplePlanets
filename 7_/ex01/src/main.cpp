/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:07:15 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/12 15:44:10 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"
#include <iostream>


template <typename T>
void print_this_type(T const &x)
{
	std::cout << x << std::endl;
}

int main(void) {
	int intArray[] = {1, 2, 3, 4, 5};
	std::string stringArray[] = {"Hello", "World", "!"};

	std::cout << "intArray: " << std::endl;
	iter(intArray, 5, print_this_type<int>);

	std::cout << std::endl << "stringArray: " << std::endl;
	iter(stringArray, 3, print_this_type<std::string>);
}

