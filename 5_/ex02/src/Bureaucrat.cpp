/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:19:58 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/15 12:01:38 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/colors.hpp"

Bureaucrat::Bureaucrat() : _name("John Doe") {
    _rank = 150;
    std::cout << BLUE << "Call default Bureaucrat constructor.\n" RESET ; 
}

Bureaucrat::Bureaucrat(std::string const & name, int rank) : _name(name) {
    std::cout << BLUE "Trying to hire "<< getName() << " at rank "<< rank << RESET "\n";
    if (rank > 150) {
        _rank = 150;
        throw GradeTooLow();
        }
    else if (rank < 1) {
        _rank = 1;
       throw GradeTooHigh();
       }
    this->_rank = rank;
    std::cout << GREEN << "Welcome "<< getName() << " ! Your grade is "<< getRank() << RESET "\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const & toCopy)  : _name(toCopy.getName())
{
    std::cout << BLUE << "Call Copy constructor." << RESET "\n";
    *this = toCopy;
}


Bureaucrat const & Bureaucrat::operator=(Bureaucrat const & toCopy)
{
    if(this != &toCopy)
        _rank = toCopy.getRank();
    return *this;
}

Bureaucrat::~Bureaucrat() {       
    std::cout <<  getName() <<  BLUE " ! You're fired ! [DESTRUCTOR]" << RESET << std::endl;
}
//-------------------------------------------------------------------------------

std::string const  & Bureaucrat::getName() const {
    return this->_name;
}

int const & Bureaucrat::getRank() const {
   return this->_rank; 
}

int Bureaucrat::setRank(int const newRank) {
    if (newRank > 150)
        throw GradeTooLow();
    else if (newRank < 1)
        throw GradeTooHigh();
    return _rank = newRank;
}

//-----------------------------------------------------------------------------

const char * Bureaucrat::GradeTooLow::what() const throw() {
    return "Bureaucrat's grade is too low ! (must be <= 150).\n" ;
}

const char * Bureaucrat::GradeTooHigh::what() const throw() {
        return "Bureaucrat's grade is too high (must be >= 1).\n" ;
}

//------------------------------------------------------------------------------

void Bureaucrat::promote(){
    int newRank = getRank() - 1;
    if (newRank < 1) {
        std::cout << YELLOW "You're already the BigBoss. Promotion cancelled \n" RESET << std::endl;
        throw Bureaucrat::GradeTooHigh();
    }
    setRank(newRank);
    std::cout << GREEN "Congrats, "<< getName()  <<" you've been promoted !" RESET << std::endl;
}

void Bureaucrat::demote() {
    int newRank = getRank() + 1;
    if (newRank > 150) {
        std::cout << YELLOW "Oh, can't demote you anymore. Maybe should I fire you ?\n" RESET ;
        throw Bureaucrat::GradeTooLow();
    }
    setRank(newRank);
    std::cout << RED "I have to retrograde you, "<< getName()  <<" . Hit your targets next month ! \n" RESET ;   
}
    

void Bureaucrat::signForm(AForm & f) {
    if (f.getSignState())
        throw AForm::FormAlreadySigned();
    f.beSigned(*this);
    // }
    // catch (const std::exception & e) {
    //     std::cout << _name << " couldn’t sign this " << f.getName() << " because " << e.what() ;
    // }
}

void Bureaucrat::executeForm(AForm const & f) {
    if (!f.getSignState())
        throw AForm::FormUnsigned();
    f.isExecuted(*this);
}

std::ostream & operator<<(std::ostream & s, Bureaucrat const & buro) {
    s << buro.getName() 
        << ", bureaucrat grade " 
        << buro.getRank() << "." 
        << std::endl;
    return s;
}