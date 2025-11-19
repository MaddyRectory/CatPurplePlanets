/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:27 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/19 18:01:21 by mairivie         ###   ########.fr       */
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

// ===== CLASS DECLARATION =====
class Bureaucrat;

class PresidentialPardonForm : public AForm {
    private:

    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &toCopy);
        PresidentialPardonForm & operator=(const PresidentialPardonForm &toCopy);
        ~PresidentialPardonForm();

};
#endif