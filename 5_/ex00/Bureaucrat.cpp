/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:19:58 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/08 15:04:18 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << BLUE << "Call default Bureaucrat constructor.\n";
    std::cout << RED << "Warning : construct Bureaucrat without name or rank." << RESET << std::endl;

}

Bureaucrat::Bureaucrat(std::string const & name, int rank) : _name(name) {
    if (rank > 150)
        throw GradeTooLowException();
    else if (rank < 1)
        throw GradeTooHighException();
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
std::cout <<  getName() <<  BLUE " ! You're fired !" << RESET << std::endl;
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
        std::cout << YELLOW "Oups, sorry BigBoss, I've made a mistake. Don't fire me please \n" RESET << std::endl;
        throw Bureaucrat::GradeTooHighException();
    }
    else{
        setRank(newRank);
        std::cout << GREEN "Congrats, "<< getName()  <<" you've been promoted !" RESET << std::endl;
    }
}

void Bureaucrat::demote() {
    int newRank = getRank() + 1;
    if (newRank > 150) {
        std::cout << YELLOW "Oh it's you. Looks like you're already a minion. Maybe should I fire you ?\n" RESET ;
        throw Bureaucrat::GradeTooLowException();
    }
    else{
        setRank(newRank);
        std::cout << RED "I have to retrograde you, "<< getName()  <<" . Hit your targets next month ! \n" RESET ;   
    }
}

std::ostream & operator<<(std::ostream & s, Bureaucrat const & buro) {
    s << buro.getName() << ", bureaucrat grade " << buro.getRank() << "." << std::endl;
    return s;
}
