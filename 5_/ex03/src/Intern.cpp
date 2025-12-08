/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:15:16 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/08 11:47:13 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"


Intern::Intern() {
    std::cout << BLUE "Welcome intern (constructor)\n" RESET ;
}

// Intern::Intern(const Intern & toCopy) {
    
// }

Intern::~Intern() {
    std::cout << BLUE "Bye bye intern (destructor)\n" RESET ;
}

// Intern & Intern::operator=(const Intern & toCopy) {
    
// }