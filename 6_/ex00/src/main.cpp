/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:55:18 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/05 18:10:16 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cin cout tu coco
#include "../include/colors.hpp"
#include "../include/ScalarConverter.hpp"

int main (int argc, char ** argv) {

    if (argc != 2)
        return (std::cout << RED "\nERROR: NB ARGUMENTS ! \n" RESET, 1);

    //DEBUG
    // std::cout << "Nb d'argument : " << argc << " & av[1] : " << argv[1] << std::endl;  

    ScalarConverter::convert(argv[1]);
    
    return 0;
}