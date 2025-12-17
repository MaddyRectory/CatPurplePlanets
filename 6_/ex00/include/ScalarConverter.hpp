/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:55:41 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/17 16:55:48 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

// ===== INCLUDES =====
#include "colors.hpp"
#include <iostream>
#include <string>

// ===== DEFINE CLEAN CODE =====
#define EXIT_SUCCESS 0
#define EXIT_FAIL 1

// ===== CLASS DECLARATION =====
class ScalarConverter
{
private:


public:
    /* default constructor, copy constructor, affecation operator, default destructor */
    ScalarConverter();
    ScalarConverter(const ScalarConverter &toCopy);
    ScalarConverter &operator=(const ScalarConverter &toCopy);
    ~ScalarConverter();


};
#endif