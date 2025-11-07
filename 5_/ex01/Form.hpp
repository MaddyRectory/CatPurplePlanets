/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:16:18 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/07 17:46:03 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

// ===== INCLUDES =====
#include "Bureaucrat.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

// ===== DEFINE CLEAN CODE =====
#define EXIT_SUCCESS 0
#define EXIT_FAIL 1

// ===== CLASS DECLARATION =====
class Form
{
private:
    std::string const & _name;
    int const _grade_to_sign;
    int const _grade_to_ex;
    bool _is_signed;

public:
    Form(std::string const & name, int const grade_to_sign, int const grade_to_ex);
    Form(const Form &toCopy);
    Form operator=(const Form &toCopy);
    ~Form();

    std::string const & getName() const;
    int const &         getGradeToSign() const;
    int const &         getGradeToEx() const;
    bool const &        getSignState() const;

    
    void beSigned(Bureaucrat const & buro);
};

std::ostream & operator<<(std::ostream & s, Form const & to_print );


// ----EXEPTIONS ---------
//
class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Creation denied : highest grade is 1.\n " ;
        }
};

class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Creation denied : lowest grade is 150.\n " ;
        };
};

class FormAlreadySigned : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "This form is already signed, I can't do it again.\n " ;
        };
};


#endif