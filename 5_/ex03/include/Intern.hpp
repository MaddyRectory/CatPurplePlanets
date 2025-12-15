/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:15:22 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/15 14:32:50 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CPP
#define INTERN_CPP

#include "colors.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>

class Intern {
    private:
        // cf subject The intern has no name, no grade, and no unique characteristic
    public:
        Intern();
        Intern(const Intern & toCopy);
        Intern & operator=(const Intern & toCopy);
        virtual ~Intern();
        
        AForm * makeForm(std::string const form_name, std::string const target);

        class UnknownForm : public std::exception {
            public: virtual const char * what() const throw(); };
};

#endif