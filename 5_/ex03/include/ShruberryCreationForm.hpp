/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:13 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/15 09:17:16 by mairivie         ###   ########.fr       */
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
        std::string _createFileName() const;
        std::string _createForest() const;
    public :
        ShruberryCreationForm();
        ShruberryCreationForm(std::string target);
        ShruberryCreationForm(const SCForm & toCopy);
        virtual ~ShruberryCreationForm();

    ShruberryCreationForm & operator=(const SCForm & toCopy);

    class NameTooLong : public std::exception {
        public: virtual const char * what() const throw(); };
        
    class NameInvalidChar : public std::exception {
        public: virtual const char * what() const throw(); };
            
    virtual void action() const;
};


#endif