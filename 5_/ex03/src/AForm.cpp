/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:16:13 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/19 14:36:31 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/colors.hpp"

AForm::AForm(std::string const & name, std::string const & target,
                int const sign_rk, int const ex_rk) 
            : _name(name), _target(target), _grade_to_sign(sign_rk), 
                _grade_to_ex(ex_rk) {    
    std::cout << BLUE "[Form construction request].\n" RESET 
            << CYAN " Name = " << _name
            << ". Target = " << _target  
            << ". grade_to_sign = " << _grade_to_sign 
            << ". grade_to_ex = " << _grade_to_ex 
            << ".\n" << RESET;

    if ((_grade_to_sign > 150) || (_grade_to_ex > 150)) 
        throw Bureaucrat::GradeTooLow();
    if ((_grade_to_sign < 1) || (_grade_to_ex < 1)) 
        throw Bureaucrat::GradeTooHigh();
    
    _is_signed = 0;
    std::cout << GREEN "Unsigned " << getName() << "'s creation confirmed.\n" << RESET << std::endl;
}

AForm::AForm(const AForm &toCopy)  : 
    _name(toCopy._name),
    _target(toCopy._target),
    _grade_to_sign(toCopy._grade_to_sign), 
    _grade_to_ex(toCopy._grade_to_ex)  {

    std::cout << BLUE << "Call Form Copy constructor.\n" << RESET;
}

AForm & AForm::operator=(const AForm &toCopy) {
    if(this != &toCopy)
        _is_signed = toCopy._is_signed;
    return *this;
}

AForm::~AForm() {
        std::cout   << BLUE << "[Default AForm Destructor]\n" RESET ;
} 

// ---------------------------------------------------
// GETTERS
// ---------------------------------------------------

std::string const & AForm::getName() const {
    return _name;
}

std::string const & AForm::getTarget() const {
    return _target;
}

int const & AForm::getGradeToSign() const {
    return _grade_to_sign;
}

int const & AForm::getGradeToEx() const {
    return _grade_to_ex;
}

bool const & AForm::getSignState() const{
    return _is_signed;
}

// ---------------------------------------------------
// EXEPTIONS 
// ---------------------------------------------------

const char * AForm::GradeTooHigh::what() const throw() {
    return "his grade is to high !\n" ; 
}

const char * AForm::GradeTooLow::what() const throw() {
    return "his grade is to law !\n" ;
}

const char * AForm::FormAlreadySigned::what() const throw() {
        return "this Aform is already signed.\n" ;
}

const char * AForm::FormUnsigned::what() const throw() {
        return "this Aform is already signed.\n" ;
}

// ---------------------------------------------------
// FT MEMBERS
// ---------------------------------------------------

void AForm::checkSignedStatus() const {
    if(_is_signed)
        throw AForm::FormAlreadySigned();
}

void AForm::beSigned(Bureaucrat const & buro) {
    std::cout << CYAN "Hi " << buro.getName() 
            << "! Could you approve this " << this -> _name 
            << " ?\n" RESET;
    if (_is_signed == 1)
        throw AForm::FormAlreadySigned();
    buro.getRank() <= _grade_to_sign ?
         _is_signed = 1 
         : throw AForm::GradeTooLow();   
    std::cout << GREEN "Grumphy Bureaucrat quickly sign the form without reading it.\n";    
    std::cout << CYAN "Thx " << buro.getName() 
            <<". See you at the coffee machine !\n" RESET;
    
}

void AForm::isExecuted(Bureaucrat const & buro) const {
    std::cout << CYAN "Hi " << buro.getName() << "! Could you execute this " << this -> _name << " ?\n" RESET;
    
    if (_is_signed == 0)
        throw AForm::FormUnsigned();
        
    buro.getRank() <= _grade_to_ex ?
        std::cout << GREEN "Executor stamps the form. and give it back.\n"    
        : throw AForm::GradeTooLow();
         
    std::cout << PURPLE "\nEXECUTION of the " << this -> _name << " for " << this -> _target << ".\n" RESET ;

    this -> action();
}

//------------------------------------------------------

std::ostream & operator<<(std::ostream & s, AForm const & to_print ) {
     std::cout << PURPLE 
              << "Aform's name: " << to_print.getName() 
              << " / Target : " << to_print.getTarget()
              << " / Grade min to sign : " << to_print.getGradeToSign() 
              << " / Grade min to exec: " << to_print.getGradeToEx() 
              << " / Status ? ";
    to_print.getSignState() ?
        std::cout << GREEN "[Signed]\n" << RESET
        : std::cout << YELLOW "[Empty]\n" << RESET;
    return s;
}
