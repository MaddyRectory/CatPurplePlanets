/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:55:41 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/08 12:50:26 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

// ===== INCLUDES =====
#include "colors.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>
#include <cfloat>
#include <cmath>
#include <ctype.h>

// ===== DEFINE CLEAN CODE =====
#define EXIT_SUCCESS 0
#define EXIT_FAIL 1

// ===== ENUM =====
enum Type {UNKOWN, CHAR, INT, FLOAT, DOUBLE, PSEUDO_LIT, INVALID };

// ===== CLASS DECLARATION =====
class ScalarConverter {
    public:
        static void convert(std::string input);
};

// ===== TYPE FINDERS =====

bool	typeIsChar(std::string str, Type* ptr);
bool	typeIsInt(std::string str, Type* ptr);
bool	typeIsFloat(std::string str, Type* ptr);
bool	typeIsDouble(std::string str, Type* ptr);
bool	typeIsPseudo(std::string str, Type* ptr);
bool	isInvalid(std::string str, Type* ptr);

// ===== PRINTERS =====

void    printPseudoLit(std::string input);
void	printChar(char c);
void	printInt(int i, std::string str);
void	printFloat(float f);
void	printDouble(double d);

#endif