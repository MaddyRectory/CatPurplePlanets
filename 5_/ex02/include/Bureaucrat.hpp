/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:20:01 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/26 18:07:30 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

// ===== INCLUDES =====
#include "../include/AForm.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

// ===== DEFINE CLEAN CODE =====

// ===== CLASS DECLARATION =====
class AForm;

class Bureaucrat
{
    private:
        std::string const  _name;
        int           _rank;

    public:
        Bureaucrat();
        Bureaucrat(std::string const & name, int rank);
        Bureaucrat(Bureaucrat const & toCopy);
        Bureaucrat const &operator=(Bureaucrat const & toCopy);
        ~Bureaucrat();
        
        std::string const  & getName() const;
        int const & getRank() const;
        int setRank(int const newRank);

    class GradeTooHigh : public std::exception {
        public:
            virtual const char* what() const throw(); 
    };

    class GradeTooLow : public std::exception {
        public:
            virtual const char* what() const throw(); 
    };

    void promote();
    void demote();
    void signForm(AForm & f);

};

std::ostream & operator<<(std::ostream & s, Bureaucrat const & buro);

#endif