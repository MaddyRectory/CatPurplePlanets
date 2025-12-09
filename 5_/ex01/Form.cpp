/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:16:13 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/09 17:09:48 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("[BLANK]"), _grade_to_sign(150), _grade_to_ex(150), _is_signed(0) {
    std::cout << CYAN << "Call Form default constructor.\n" << RESET ;
}

Form::Form(std::string const & name, int const sign_rk, int const ex_rk) 
        : _name(name), _grade_to_sign(sign_rk), _grade_to_ex(ex_rk) {
    
    std::cout << BLUE 
              << "[Form construction request].\n" CYAN
              << " Name = " << _name 
              << ". grade_to_sign = " << _grade_to_sign 
              << ". grade_to_ex = " << _grade_to_ex 
              << ". Unsigned.\n" 
              << RESET;
    if ((_grade_to_sign > 150) || (_grade_to_ex > 150)) 
        throw Bureaucrat::GradeTooLow();
    if ((_grade_to_sign < 1) || (_grade_to_ex < 1)) 
        throw Bureaucrat::GradeTooHigh();
    
    _is_signed = 0;
    std::cout << GREEN  << _name << "'s creation confirmed.\n\n" << RESET;
}

Form::Form(const Form &toCopy)  
    : _name(toCopy._name), _grade_to_sign(toCopy._grade_to_sign), _grade_to_ex(toCopy._grade_to_ex) {
}

Form & Form::operator=(const Form &toCopy) {
    if(this != &toCopy)
        _is_signed = toCopy._is_signed;
    return *this;
}

Form::~Form() {
    std::cout << BLUE << "[Form Destructor] -> Form " << _name 
            << " safely shredded !\n" << RESET;
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

void Form::checkSignedStatus() const {
    if(_is_signed)
        throw Form::FormAlreadySigned();
}

const char * Form::GradeTooLow::what() const throw() {
    return "his grade is too low !\n" ;
}

const char * Form::FormAlreadySigned::what() const throw() {
        return "this form is already signed.\n" ;
}


// void Bureaucrat::signForm(Form & f) {
//     try 
//     {
//         f.checkSignedStatus();
//         f.beSigned(*this);
//     }
//     catch (const std::exception & e) {
//         std::cout << _name << " couldn’t sign this " << f.getName() << " because " << e.what() ;
//     }

void Form::beSigned(Bureaucrat const & buro) {
    try 
    {
    std::cout << CYAN "Hi " << buro.getName() << "! Could you approve this " << _name << " ?\n" RESET;
    if (_is_signed == true)
        throw Form::FormAlreadySigned();
        
    buro.getRank() <= _grade_to_sign ?
         _is_signed = true 
         : throw Form::GradeTooLow();
         
    std::cout << GREEN "Grumphy Bureaucrat quickly sign the form without reading it.\n";    
    std::cout << CYAN "Thx " << buro.getName() 
            <<". See you at the coffee machine !\n" RESET;
    }
    catch (const std::exception & e) {
        std::cout << buro.getName() << " couldn’t sign this " << _name << " because " << e.what();
    }
    
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
