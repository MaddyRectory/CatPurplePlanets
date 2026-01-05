/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:55:35 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/05 11:44:54 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"


bool	isChar(std::string str) {} //leng ==1 + pas un chiffre

bool	isInt(std::string str) {} //only digit e-

bool	isFloat(std::string str) {}

bool	isDouble(std::string str) {}

bool	isSpe(std::string str) { //on a la liste exacte
    
    	std::string special_cases[6] = {"nan", "nanf", "+inf", "-inf", "-inff", "+inff"};
        
        for (int i = 0; i < 6; i++) {
            if (str == special_cases[i])
                return true;
        }
        return false;
}

bool	isInvalid(std::string str) {}

void ScalarConverter::convert(std::string input) {
    
    std::cout << GREEN "\nConversion OK !" RESET << std::endl;
    
    enum listType {UNKOWN, CHAR, INT, FLOAT, DOUBLE, PSEUDO_LIT, INVALID };
    
    char    c;
    int     i;
    float   f;
    double  d;
    int     type = 0;

    bool (*typeList[6])(std::string input) = {isChar, isInt, isFloat, isDouble, isSpe, isInvalid};

    for (type = 0; type < 6; type++) {
        if (typeList[type](input) == true)
            std::cout << "Found the type GG !"; //ft convert to type
    }

    // ft_
    //use type found to convert char to type
    //cast into double
    //print with static cast
    
    
}