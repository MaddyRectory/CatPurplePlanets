/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:55:18 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/22 16:13:29 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cin cout tu coco
#include "../include/colors.hpp"
#include "../include/ScalarConverter.hpp"

int main (int argc, char ** argv) {
    
    std::cout << GREEN "\nCompilation OK !" RESET << std::endl;
    
    if (argc != 2)
        return (std::cout << RED "\nERROR: TROP D'ARGUMENTS ! \n" RESET, 1);
    std::cout << "Nb d'argument : " << argc << " & av[1] : " << argv[1] << std::endl;  


    
    return 0;
}