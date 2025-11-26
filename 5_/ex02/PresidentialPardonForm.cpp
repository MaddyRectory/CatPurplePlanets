/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:30 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/24 16:31:15 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "colors.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("PresidentialPardon", target, 25, 5)  {}
    
PresidentialPardonForm::PresidentialPardonForm(const PPForm &toCopy) 
    : AForm(toCopy) {}
    
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout   << CYAN << "Pardon Form safely shredded !\n" RESET ;
}
    

//--------- OPERATOR --------------
    
PresidentialPardonForm & PresidentialPardonForm::operator=(const PPForm &toCopy) {
    if(this != &toCopy) 
        AForm::operator=(toCopy);
    return *this;
}


void PresidentialPardonForm::action() {
    std::cout << GREEN "Dear " << AForm::getTarget() << " , today is your lucky day :\n"
        << "you have been pardoned by Zaphod Beeblebrox ! Now come back to work." RESET;
}
