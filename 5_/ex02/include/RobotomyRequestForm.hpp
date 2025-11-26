/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:19 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/26 18:07:30 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef RobotomyRequestForm_HPP
 #define RobotomyRequestForm_HPP

#include <string>
#include <iostream>
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

#define RRForm RobotomyRequestForm


//class declaration
class Bureaucrat;

class RobotomyRequestForm : public AForm {
    private :
        //
    public :
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RRForm & toCopy);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(const RRForm & toCopy);

        virtual void action();
};



#endif