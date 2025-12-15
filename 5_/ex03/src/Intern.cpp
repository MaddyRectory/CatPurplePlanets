/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:15:16 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/15 14:41:28 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"


Intern::Intern() {
    std::cout << BLUE "Welcome intern (constructor)\n" RESET ;
}

Intern::Intern(const Intern & toCopy) {
    *this = toCopy;     
}

Intern::~Intern() {
    std::cout << BLUE "Bye bye intern (destructor)\n" RESET ;
}

Intern & Intern::operator=(const Intern & toCopy) {
    if (this != &toCopy)
        *this = toCopy;
    return *this;   
}

const char * Intern::UnknownForm::what() const throw() {
    return "ERROR: Don't know this form name.\n" ;
}

// Factory Function : 
//WARNING : comme usage de new, il faudra faire gaffe a delete !

// static AForm * makePPF(std::string const target){
//     return (new PresidentialPardonForm(target));
// }
// static AForm * makeSCF(std::string const target){
//     return (new ShruberryCreationForm(target));
// }
// static AForm * makeRRF(std::string const target){
//     return (new RobotomyRequestForm(target));
// }

AForm * Intern::makeForm(std::string const form_name, std::string const target) {
    
    std::string listForm[3] = {
        "shruberry creation", 
        "robotomy request", 
        "presidential pardon" };
    AForm * newForm = NULL;
    
    std::cout << BLUE "Intern try to print a [" CYAN
            << form_name << BLUE "] for [" CYAN
            << target << BLUE "]\n\n" RESET;
    
    for (int i = 0; i <= 2; i++) {
        if (form_name == listForm[i]) {
            switch (i) {
                case 0 :
                    newForm = new ShruberryCreationForm(target);
                    break;
                case 1 :
                    newForm = new RobotomyRequestForm(target);
                    break;
                case 2 :
                    newForm = new PresidentialPardonForm(target);
                    break;                
                default :
                    std::cout << "Unknokn form\n";
                }
            std::cout << GREEN "SUCCESS : Intern creates a " RESET << form_name << " form ! \n\n";
            return (newForm);
            }
        }
        if (newForm == NULL) {
            std::cout << RED "No result for [" << form_name << "] in DB.\n" RESET
                    << "Available forms are : "
                    << "shrubbery creation, robotomy request, presidential pardon."
                    << std::endl;
            throw Intern::UnknownForm();
    }
    return (newForm);
}

