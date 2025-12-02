/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:22 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/02 16:40:02 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// void PresidentialPardonForm::execute() {
//     std::cout << GREEN "Dear " << AForm::getTarget << " , today is your lucky day :\n"
//         << "you have been pardoned by Zaphod Beeblebrox ! Come back to work." RESET;
// }

#include "../include/colors.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include <ctime> // time 
#include <cstdlib> // rand()


RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm::AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RRForm & toCopy) 
    : AForm::AForm(toCopy) {}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout   << "Robotomy Form " << BLUE " safely shredded !\n" RESET ;
}


RobotomyRequestForm & RobotomyRequestForm::operator=(const RRForm & toCopy) {
    if (this != &toCopy)
        AForm::operator=(toCopy);
    return *this;
}


void RobotomyRequestForm::action() const {
    
    std::cout << CYAN "*Brrrr Krrrr Kssssss Drrrrrill*\n" << RESET;
    
    srand((unsigned int)time(0));
    int brainXplosion = rand()%2;
    if(brainXplosion) { 
        std::cout << RED "*KABOOM !*\n "
            << "Oups, I think the robotomy failed." RESET
            << std::endl;
    }
    else {
        std::cout << GREEN "TODOOM !*\nSubject " 
            << AForm::getTarget() 
            << "has been robotomised with success !" RESET
            << std::endl;        
    }
}
