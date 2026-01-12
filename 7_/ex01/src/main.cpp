/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:07:15 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/12 17:01:08 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"
#include "../include/colors.hpp"
#include <iostream>


template <typename T>
void printType(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void increase(T &x) {
    x++;
}

int main(void) {
	int             intArray[] = {0, 1, 2, 3, 4};
    const int       constArray[] = {10, 11, 12, 13, 14}; 
	std::string     stringArray[] = {"Hello", "World", "!"};

    std::cout << BG_BLUE "\n--- Array of int (modifiable) ---" RESET << std::endl;
    
	std::cout << "Initial state:" << std::endl;
	iter(intArray, 5, printType<int>);
	iter(intArray, 5, increase<int>);
    std::cout << "\nAfter increase iteration :" << std::endl;
    iter(intArray, 5, printType<int>);

    std::cout << BG_BLUE "\n--- Array of int (const) ---" RESET << std::endl;
    
    iter(constArray, 5, printType<const int>);
	// iter(constArray, 5, increase<int>); // Warning ne compilera pas
    // iter(constArray, 5, printType<int>);
    
    std::cout << BG_BLUE "\n--- Array of string ---" RESET << std::endl;

	iter(stringArray, 3, printType<std::string>);
    // iter(constArray, 5, increase<char>); // Warning ne compilera pas
    // iter(constArray, 5, printType<int>);
}