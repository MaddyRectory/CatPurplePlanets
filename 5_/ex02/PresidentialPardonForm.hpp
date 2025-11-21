/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:27 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/21 12:13:26 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

// ===== INCLUDES =====
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

// ===== DEFINE CLEAN CODE =====
#define EXIT_SUCCESS 0
#define EXIT_FAIL 1
#define PPForm PresidentialPardonForm

// ===== CLASS DECLARATION =====
class Bureaucrat;

class PresidentialPardonForm : public AForm {
    private:

    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PPForm &toCopy);
        ~PresidentialPardonForm();
        
        PresidentialPardonForm & operator=(const PPForm &toCopy);

        virtual void execute();

};
#endif