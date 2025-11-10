/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:19:58 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/10 19:49:02 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << BLUE << "Call default Bureaucrat constructor.\n";
    std::cout << RED << "Warning : construct Bureaucrat without name or rank." << RESET << std::endl;

}

Bureaucrat::Bureaucrat(std::string const & name, int rank) : _name(name) {
    if (rank > 150)
    throw GradeTooLow();
    else if (rank < 1)
    throw GradeTooHigh();
    else
    this->_rank = rank;
    std::cout << BLUE << "Welcome "<< getName() << " ! Your grade is "<< getRank() << RESET "\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const & toCopy)  : _name(toCopy.getName())
{
    std::cout << BLUE << "Call Copy constructor." << RESET "\n";
    *this = toCopy;
}


Bureaucrat const & Bureaucrat::operator=(Bureaucrat const & toCopy)
{
    if(this != &toCopy)
    {
        _rank = toCopy._rank;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
std::cout <<  getName() <<  BLUE " ! You're fired ! (Bureaucrat destructor)\n" << RESET << std::endl;
}

std::string const  & Bureaucrat::getName() const {
    return this->_name;
}

int const & Bureaucrat::getRank() const {
   return this->_rank; 
}

int Bureaucrat::setRank(int const newRank) {
    return _rank = newRank;
}

void Bureaucrat::promote(){
    int newRank = getRank() - 1;
    if (newRank < 1) {
        std::cout << YELLOW "Oups, sorry BigBoss, Cannot promote you. Don't fire me please \n" RESET << std::endl;
        throw GradeTooHigh();
    }
    else{
        setRank(newRank);
        std::cout << GREEN "Congrats, "<< getName()  <<" you've been promoted !" RESET << std::endl;
    }
}

void Bureaucrat::demote() {
    int newRank = getRank() + 1;
    if (newRank > 150) {
        std::cout << YELLOW "Oh it's you. Looks like you're already at lowest grade. Maybe should I fire you ?\n" RESET ;
        throw GradeTooLow();
    }
    else{
        setRank(newRank);
        std::cout << RED "I have to retrograde you, "<< getName()  <<" . Hit your targets next month ! \n" RESET ;   
    }
}

const char * Bureaucrat::GradeTooLow::what() const throw() {
    return "Bureaucrat's grade is to law ! (must be <= 150).\n" ;
}

const char * Bureaucrat::GradeTooHigh::what() const throw() {
        return "Bureaucrat's grade is to high (must be >= 1).\n" ;
}
    

void Bureaucrat::signForm(Form & f) {
    try 
    {
        f.checkSignedStatus();
        f.beSigned(*this);
    }
    catch (const std::exception & e) {
        std::cout << _name << " couldn’t sign this " << f.getName() << " because " << e.what() ;
    }
}

std::ostream & operator<<(std::ostream & s, Bureaucrat const & buro) {
    s << buro.getName() << ", bureaucrat grade " << buro.getRank() << "." << std::endl;
    return s;
}
