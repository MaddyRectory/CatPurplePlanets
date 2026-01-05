/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:55:35 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/05 18:08:16 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

//enum Type {UNKOWN, CHAR, INT, FLOAT, DOUBLE, PSEUDO_LIT, INVALID };

//leng ==1 + pas un chiffre
bool	typeIsChar(std::string str, Type* ptr) {
        if (str.length() == 1 
            && str.find_first_of("0123456789") == std::string::npos)
            return (*ptr = CHAR, true);
        return false;
} 

//only digit e-
bool	typeIsInt(std::string str, Type* ptr) {
        if (str.find_first_not_of("0123456789-") == std::string::npos 
            && (str.find_last_of("-") == 0 || str.find_last_of("-") == std::string::npos)) 
            {
                *ptr = INT;
                return true;
            }
        return false;
} 

bool	typeIsFloat(std::string str, Type* ptr) {
        if (str.find_first_not_of("-0123456789.f") == std::string::npos
            && (str.find_last_of("-") == 0 || str.find_last_of("-") == std::string::npos) 
            && (str.find_first_of("f") == str.length() - 1)
            && (isdigit(str[str.find(".") - 1]) && isdigit(str[str.find(".") + 1])) )
            {
                *ptr = FLOAT;
                return true;
            }
        return false;
}

bool	typeIsDouble(std::string str, Type* ptr) {
        if (str.find_first_not_of("-0123456789.") == std::string::npos
            && (str.find_last_of("-") == 0 || str.find_last_of("-") == std::string::npos) 
            && (isdigit(str[str.find(".") - 1]) && isdigit(str[str.find(".") + 1])) )
            {
                *ptr = DOUBLE;
                return true;
            }
        return false;
}

//on a la liste exacte
bool	typeIsPseudo(std::string str, Type* ptr) { 
    
    	std::string special_cases[6] = {"nan", "nanf", "+inf", "-inf", "-inff", "+inff"};
        
        for (int i = 0; i < 6; i++) {
            if (str == special_cases[i])
                return (*ptr = PSEUDO_LIT, true);
        }
        return false;
}

bool	isInvalid(std::string str, Type* ptr) {
        std::cout << RED "ERROR: " << str << " is not a valid input.\n" ;
        *ptr = INVALID;
        return false;
}


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
        // case PSEUDO_LIT: return pseudotoDouble(input);
        default: return ( std::cout << RED "ERROR: Fail to convert\n", 0);
    }
}

void    printPseudoLit(std::string input) {
    
    std::string special_cases[6] = {"nan", "nanf", "+inf", "-inf", "-inff", "+inff"};

    for (int i = 0; i < 6; i++) {
        if (input == special_cases[i]) {
            if (i < 2) {
                std::cout <<"char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
            }
            else {
                std::string inf_double = input.substr(0, 4);
				std::cout << "char: impossible\nint: impossible\nfloat: " << inf_double << "f\ndouble: " << inf_double << std::endl;
            }
        }
    }
    return;
}

void	printChar(char c)
{
	if (isprint(c))
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	printInt(int i, std::string str)
{
	if ((i == -2147483648 && str == "-2147483648")|| (i == 2147483647 && str == "2147483647"))
		std::cout << "int: " << i << std::endl;
	else if (i <= std::numeric_limits<int>::min() || i >= std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	printFloat(float f)
{
	if (f < -FLT_MAX || f > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << std::endl;
}

void	printDouble(double d)
{
	if (d < -DBL_MAX || d > DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}


void ScalarConverter::convert(std::string input) {
    Type input_type = INVALID;

    bool (*getTypeTools[6])(std::string input, Type* ptr) = {typeIsChar, typeIsInt, typeIsFloat, typeIsDouble, typeIsPseudo, isInvalid};

    for (int j = 0; j < 6; j++) {
        if (getTypeTools[j](input, &input_type) == true)
            break;
    }

    if (input_type == PSEUDO_LIT)
        return (printPseudoLit(input));
    
    double pivot_value = typeToDouble(input, input_type);

    //DEBUG
    // std::cout << GREEN "pivot value = " << pivot_value << "  Hopla " RESET << std::endl;

    float f = static_cast<float>(pivot_value);
    double d = static_cast<double>(pivot_value);
    int i = static_cast<int>(pivot_value);
    char c = static_cast<char>(pivot_value);
    
    printFloat(f);
    printChar(c);
    printInt(i, input);
    printDouble(d);
    
    return;
}


