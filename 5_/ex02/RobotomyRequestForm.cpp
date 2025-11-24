/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:22 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/24 13:49:15 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// void PresidentialPardonForm::execute() {
//     std::cout << GREEN "Dear " << AForm::getTarget << " , today is your lucky day :\n"
//         << "you have been pardoned by Zaphod Beeblebrox ! Come back to work." RESET;
// }

#include "colors.hpp"
#include "RobotomyRequestForm.hpp"
#include <ctime> // time 
#include <cstdlib> // rand()


RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm::AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RRForm & toCopy) 
    : AForm::AForm(toCopy) {}

RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm & RobotomyRequestForm::operator=(const RRForm & toCopy) {
    if (this != &toCopy)
        AForm::operator=(toCopy);
    return *this;
}


void RobotomyRequestForm::execute() {
    srand((unsigned int)time(0));

    std::cout << CYAN "*Brrrr Krrrr Kssssss Drrrrrill*\n" << RESET;
    
    int brainXplosion = rand()%2;
    if(brainXplosion)
        std::cout << RED "*KABOOM !*\nOups, I think the robotomy failed.\n" << RESET;
    else
        std::cout << GREEN "Subject " << AForm::getTarget() << "has been robotomised with success !\n";
}
