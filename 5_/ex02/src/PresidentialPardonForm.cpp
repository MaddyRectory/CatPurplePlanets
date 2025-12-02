/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:30 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/02 16:39:11 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include "../include/colors.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("PresidentialPardon", target, 25, 5)  {}
    
PresidentialPardonForm::PresidentialPardonForm(const PPForm &toCopy) 
    : AForm(toCopy) {}
    
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout   << "Pardon Form " << BLUE " safely shredded !\n" RESET ;
}
    

//--------- OPERATOR --------------
    
PresidentialPardonForm & PresidentialPardonForm::operator=(const PPForm &toCopy) {
    if(this != &toCopy) 
        AForm::operator=(toCopy);
    return *this;
}


void PresidentialPardonForm::action() const {
    std::cout << GREEN "Dear " << AForm::getTarget() << " , today is your lucky day :\n"
        << "you have been pardoned by Zaphod Beeblebrox !"
        << YELLOW "\nNow come back to work." RESET
        << std::endl;
}
