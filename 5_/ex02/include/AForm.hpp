/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:16:18 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/19 14:37:44 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Aform_HPP
#define Aform_HPP

// ===== INCLUDES =====
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>

// ===== DEFINE CLEAN CODE =====
#define EXIT_SUCCESS 0
#define EXIT_FAIL 1

// ===== CLASS DECLARATION =====
class Bureaucrat;

class AForm
{
private:
    std::string const  _name;
    std::string const & _target; //All forms need a target => _private in AClass
    int const _grade_to_sign;
    int const _grade_to_ex;
    bool _is_signed;

public:
    AForm(std::string const & name, std::string const & target, int const grade_to_sign, int const grade_to_ex);
    AForm(const AForm &toCopy);
    AForm & operator=(const AForm &toCopy);
    virtual ~AForm() = 0;

    std::string const & getName() const;
    std::string const & getTarget() const;
    int const &         getGradeToSign() const;
    int const &         getGradeToEx() const;
    bool const &        getSignState() const;

    void checkSignedStatus() const;
    void beSigned(Bureaucrat const & buro);
    void isExecuted(Bureaucrat const & buro) const;
    virtual void action() const = 0;
    
    // ----EXEPTIONS ---------
    //
    class GradeTooHigh : public std::exception {
        public: virtual const char * what() const throw(); };
    
    class GradeTooLow : public std::exception {
        public: virtual const char * what() const throw();};
    
    class FormAlreadySigned : public std::exception {
        public: virtual const char * what() const throw(); };

    class FormUnsigned : public std::exception {
        public: virtual const char * what() const throw(); };
};

std::ostream & operator<<(std::ostream & s, AForm const & to_print );

#endif