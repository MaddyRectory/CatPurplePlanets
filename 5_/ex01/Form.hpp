/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:16:18 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/19 16:30:43 by mairivie         ###   ########.fr       */
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
class Bureaucrat;

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
    Form & operator=(const Form &toCopy);
    ~Form();

    std::string const & getName() const;
    int const &         getGradeToSign() const;
    int const &         getGradeToEx() const;
    bool const &        getSignState() const;

    void checkSignedStatus();
    
    void beSigned(Bureaucrat const & buro);
    
    // ----EXEPTIONS ---------
    //
    class GradeTooHigh : public std::exception {
        public: virtual const char * what() const throw(); };
    
    class GradeTooLow : public std::exception {
        public: virtual const char * what() const throw();};
    
    class FormAlreadySigned : public std::exception {
        public: virtual const char * what() const throw(); };
};

std::ostream & operator<<(std::ostream & s, Form const & to_print );






#endif