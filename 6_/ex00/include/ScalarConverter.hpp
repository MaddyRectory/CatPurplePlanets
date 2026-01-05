/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:55:41 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/05 17:50:15 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

// ===== INCLUDES =====
#include "colors.hpp"
#include <iostream>
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
#endif