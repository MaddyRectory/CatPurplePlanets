/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:55:35 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/09 15:32:42 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

//DEBUG
// const char* typeToString(Type toCheck) {
//     switch (toCheck) {
//         case CHAR: return "CHAR";
//         case INT: return "INT";
//         case FLOAT: return "FLOAT";
//         case DOUBLE: return "DOUBLE";
//         case PSEUDO_LIT: return "PSEUDO";
//         default: return "INVALID";
//     }
// }

double typeToDouble(std::string input, Type toCheck) {
    switch (toCheck) {
        case DOUBLE: return strtod(input.c_str(), NULL);
        case CHAR: return static_cast<double>(input[0]);
        case INT: return static_cast<double>(atoi(input.c_str()));
        case FLOAT: return static_cast<double>(strtof(input.c_str(), NULL));
        // DEBUG: case PSEUDO_LIT: return pseudotoDouble(input);
        default: return ( std::cout << RED "ERROR: Fail to convert\n", 0);
    }
}

static bool (*getTypeTools[6])(std::string input, Type* ptr) = {
        typeIsChar, typeIsInt, typeIsFloat, 
        typeIsDouble, typeIsPseudo, isInvalid
    };

void ScalarConverter::convert(std::string input) {
    Type input_type = INVALID;

    for (int j = 0; j < 6; j++) {
        if (getTypeTools[j](input, &input_type) == true)
            break;
    }
    
    if (input_type == INVALID)
        return;
    if (input_type == PSEUDO_LIT)
        return (printPseudoLit(input));
    
    double pivot_value = typeToDouble(input, input_type);

    std::cout << std::fixed << std::setprecision(1);
    
    char c = static_cast<char>(pivot_value);
    int i = static_cast<int>(pivot_value);
    float f = static_cast<float>(pivot_value);
    double d = static_cast<double>(pivot_value);

    i >=130 ? printCharKO() : printChar(c);
    printInt(i, input);
    printFloat(f);
    printDouble(d);
    
    return;
}


