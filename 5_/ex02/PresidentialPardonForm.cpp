/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:30 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/19 18:10:05 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#define PPForm PresidentialPardonForm

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("PresidentialPardon", target, 25, 5)  {}
    
PresidentialPardonForm::PresidentialPardonForm(const PPForm &toCopy) 
    : AForm(toCopy) {}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PPForm &toCopy) {
    if(this != &toCopy) {
       this->_is_signed = toCopy.getSignState();
    }
    return *this;
}
    
PresidentialPardonForm::~PresidentialPardonForm() {}


//
//
// TODO 20 NOV : POURQUOI OPERATOR = PLANTE
//
//