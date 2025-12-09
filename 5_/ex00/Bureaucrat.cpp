/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:19:58 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/09 11:38:14 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//init les var
Bureaucrat::Bureaucrat() {
    Bureaucrat("John Doe", 150);
    std::cout << BLUE << "Call default Bureaucrat constructor.\n";
    std::cout << CYAN << "Default name : John Doe, default rank 150." << RESET << std::endl;

}

Bureaucrat::Bureaucrat(std::string const & name, int rank) : _name(name) {
    if (rank > 150) {
        _rank = 150;
        std::cout << BLUE << "Welcome "<< getName() << " ! Your grade is "<< getRank() << RESET "\n";
        throw GradeTooLowException();
        }
    else if (rank < 1) {
        _rank = 1;
        std::cout << BLUE << "Welcome "<< getName() << " ! Your grade is "<< getRank() << RESET "\n";
       throw GradeTooHighException();
       }
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
        _rank = toCopy._rank;
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

//protege ce truc  bordel
int Bureaucrat::setRank(int const newRank) {
    if (newRank > 150)
        throw GradeTooLowException();
    else if (newRank < 1)
        throw GradeTooHighException();
    return _rank = newRank;
}

void Bureaucrat::promote(){
    int newRank = getRank() - 1;
    if (newRank < 1) {
        std::cout << YELLOW "You're already the BigBoss. Promotion cancelled \n" RESET << std::endl;
        throw Bureaucrat::GradeTooHighException();
    }
    setRank(newRank);
    std::cout << GREEN "Congrats, "<< getName()  <<" you've been promoted !" RESET << std::endl;
}

void Bureaucrat::demote() {
    int newRank = getRank() + 1;
    if (newRank > 150) {
        std::cout << YELLOW "Oh, can't demote you anymore. Maybe should I fire you ?\n" RESET ;
        throw Bureaucrat::GradeTooLowException();
    }
    setRank(newRank);
    std::cout << RED "I have to retrograde you, "<< getName()  <<" . Hit your targets next month ! \n" RESET ;   
}

std::ostream & operator<<(std::ostream & s, Bureaucrat const & buro) {
    s << buro.getName() << ", bureaucrat grade " << buro.getRank() << "." << std::endl;
    return s;
}
