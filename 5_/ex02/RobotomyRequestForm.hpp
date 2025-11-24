/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:19 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/24 11:09:00 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef PresidentialPardonForm_HPP
// #define PresidentialPardonForm_HPP

// // ===== INCLUDES =====
// #include "Bureaucrat.hpp"
// #include "AForm.hpp"
// #include "colors.hpp"
// #include <iostream>
// #include <string>

// // ===== DEFINE CLEAN CODE =====
// #define EXIT_SUCCESS 0
// #define EXIT_FAIL 1
// #define PPForm PresidentialPardonForm

// // ===== CLASS DECLARATION =====
// class Bureaucrat;

// class PresidentialPardonForm : public AForm {
//     private:

//     public:
//         PresidentialPardonForm(std::string target);
//         PresidentialPardonForm(const PPForm &toCopy);
//         ~PresidentialPardonForm();
        
//         PresidentialPardonForm & operator=(const PPForm &toCopy);

//         virtual void execute();

// };
// #endif

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <string>
#include <iostream>
#include <AForm.hpp>
#include <Bureaucrat.hpp>

#define RRForm RobotomyRequestForm


//class declaration
class Bureaucrat;

class RobotomyRequestForm : public AForm {
    private :

    public :
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RRForm & toCopy);
        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(const RRForm & toCopy);

        virtual void execute(const Bureaucrat & buro);
};



#endif