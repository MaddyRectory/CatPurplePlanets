/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:55:35 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/17 16:57:14 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
std::cout << BLUE << "Call ScalarConverter default constructor." << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy)
{
    *this = toCopy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &toCopy)
{
    if(this != &toCopy)
    {

    }
    return *this;
}

ScalarConverter::~ScalarConverter() {
std::cout << BLUE << "Call ScalarConverter default destructor." << RESET << std::endl;
}
