/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:16:13 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/10 20:07:01 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Form::Form() {
// std::cout << BLUE << "Call Form default constructor." << RESET << std::endl;
// }

Form::Form(std::string const & name, int const sign_rk, int const ex_rk) 
        : _name(name), _grade_to_sign(sign_rk), _grade_to_ex(ex_rk) {
    
    std::cout << BLUE 
              << "[Form construction request].\n Name = " << _name 
              << ". grade_to_sign = " << _grade_to_sign 
              << ". grade_to_ex = " << _grade_to_ex 
              << ". Unsigned.\n" 
              << RESET;
    if ((_grade_to_sign > 150) || (_grade_to_ex > 150)) 
        throw Bureaucrat::GradeTooLow();
    if ((_grade_to_sign < 1) || (_grade_to_ex < 1)) 
        throw Bureaucrat::GradeTooHigh();
    
    _is_signed = 0;
    std::cout << GREEN  << _name << "'s creation confirmed.\n\n";
}

Form::Form(const Form &toCopy)  
    : _name(toCopy._name), _grade_to_sign(toCopy._grade_to_sign), _grade_to_ex(toCopy._grade_to_ex) {
}

Form Form::operator=(const Form &toCopy) {
    if(this != &toCopy)
    {
        Form newForm(toCopy._name, toCopy._grade_to_sign, toCopy._grade_to_ex);
        return newForm;
    }
    return toCopy;
}

Form::~Form() {
        std::cout   << BLUE << "[Form Destructor]"
                    << " -> Form " << _name 
                    << " safely shredded !\n" 
                    << RESET;
}

std::string const & Form::getName() const {
    return _name;
}

int const & Form::getGradeToSign() const {
    return _grade_to_sign;
}

int const & Form::getGradeToEx() const {
    return _grade_to_ex;
}

bool const & Form::getSignState() const{
    return _is_signed;
}

void Form::checkSignedStatus() {
    if(_is_signed)
        throw Form::FormAlreadySigned();
}

const char * Form::GradeTooLow::what() const throw() {
    return "his grade is to law ! (must be <= 150).\n" ;
}

const char * Form::GradeTooHigh::what() const throw() {
        return "grade to high (must be >= 1).\n" ;
}

const char * Form::FormAlreadySigned::what() const throw() {
        return "this form is already signed.\n" ;
}


void Form::beSigned(Bureaucrat const & buro) {
    std::cout << CYAN "Hi " << buro.getName() << "! Could you approve this " << _name << " ?\n" RESET;
    
    if (_is_signed == 1)
        throw Form::FormAlreadySigned();
        
    buro.getRank() <= _grade_to_sign ?
         _is_signed = 1 
         : throw Bureaucrat::GradeTooLow();
         
    std::cout << GREEN "Grumphy Bureaucrat quickly sign the form without reading it.\n";    
    std::cout << CYAN "Thx " << buro.getName() 
            <<". See you at the coffee machine !\n" RESET;
    
}



std::ostream & operator<<(std::ostream & s, Form const & to_print ) {
     std::cout << PURPLE 
              << "Form's name: " << to_print.getName() 
              << " / Grade min to sign : " << to_print.getGradeToSign() 
              << " / Grade min to exec: " << to_print.getGradeToEx() 
              << " / Status ? ";
    to_print.getSignState() ?
        std::cout << GREEN "[Signed]\n" 
        : std::cout << YELLOW "[Empty]\n";
    std::cout << RESET;
    return s;
}
