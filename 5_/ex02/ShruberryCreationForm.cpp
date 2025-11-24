/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:16 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/21 17:02:57 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"
#include "colors.hpp"

ShruberryCreationForm::ShruberryCreationForm(std::string target) 
    : AForm("ShruberryCreationForm", target, 145, 137) {}

ShruberryCreationForm::ShruberryCreationForm(const SCForm & toCopy)
    : AForm(toCopy) {}

ShruberryCreationForm::~ShruberryCreationForm() {}

ShruberryCreationForm & ShruberryCreationForm::operator=(const SCForm & toCopy) {
    if (this != &toCopy)
        AForm::operator=(toCopy);
    return *this;
}

void ShruberryCreationForm::execute(const Bureaucrat & buro) {
    
}