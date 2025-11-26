/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:16 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/26 18:07:30 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShruberryCreationForm.hpp"
#include "../include/colors.hpp"

ShruberryCreationForm::ShruberryCreationForm(std::string target) 
    : AForm("ShruberryCreationForm", target, 145, 137) {}

ShruberryCreationForm::ShruberryCreationForm(const SCForm & toCopy)
    : AForm(toCopy) {}

ShruberryCreationForm::~ShruberryCreationForm() {
    std::cout   << CYAN << "Shruberry Form safely shredded !\n" RESET ;
}

ShruberryCreationForm & ShruberryCreationForm::operator=(const SCForm & toCopy) {
    if (this != &toCopy)
        AForm::operator=(toCopy);
    return *this;
}

void ShruberryCreationForm::action() {
    std::cout << "OMG a Shruberry !\n";
}