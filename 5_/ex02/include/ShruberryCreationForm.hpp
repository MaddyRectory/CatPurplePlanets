/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:13 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/26 18:16:09 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShruberryCreationForm_HPP
    #define ShruberryCreationForm_HPP

# include <string>
# include <iostream>
# include "../include/Bureaucrat.hpp"
# include "../include/AForm.hpp"
    
#define SCForm ShruberryCreationForm

class Bureaucrat;

class ShruberryCreationForm : public AForm {
    private :
        //
    public :
    ShruberryCreationForm(std::string target);
    ShruberryCreationForm(const SCForm & toCopy);
    virtual ~ShruberryCreationForm();

    ShruberryCreationForm & operator=(const SCForm & toCopy);

    virtual void action();
};
    
#endif