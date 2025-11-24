/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:27 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/24 11:09:42 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

// ===== INCLUDES =====
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ===== DEFINE CLEAN CODE =====
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