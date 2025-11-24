/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:13 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/24 11:08:51 by mairivie         ###   ########.fr       */
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

#ifndef ShruberryCreationForm_HPP
    #define ShruberryCreationForm_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
    
#define SCForm ShruberryCreationForm

class Bureaucrat;

class ShruberryCreationForm : public AForm {
    private :
    
    public :
    ShruberryCreationForm(std::string target);
    ShruberryCreationForm(const SCForm & toCopy);
    ~ShruberryCreationForm();

    ShruberryCreationForm & operator=(const SCForm & toCopy);

    virtual void execute(const Bureaucrat & buro);
};
    
#endif