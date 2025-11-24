/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:19 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/24 13:48:37 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef RobotomyRequestForm_HPP
 #define RobotomyRequestForm_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define RRForm RobotomyRequestForm


//class declaration
class Bureaucrat;

class RobotomyRequestForm : public AForm {
    private :
        //
    public :
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RRForm & toCopy);
        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(const RRForm & toCopy);

        virtual void execute();
};



#endif