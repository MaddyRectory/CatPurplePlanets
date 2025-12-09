/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:20:04 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/09 18:15:31 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void){

std:: cout << "\n ------ Test 1 - constructors/destructors ------ \n" << std::endl;
    try
    {
    Bureaucrat def;
    Bureaucrat Ok(coucou, 42);

    std::cout << CYAN << def << RESET;
    std::cout << CYAN << Ok << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : "<< RESET " \n";
        std::cout << e.what(); 
    }

std:: cout << "\n ------ Test 2 - empty name [no crash] ------ \n" << std::endl;
    try
    {    
    Bureaucrat Badname("", 42);
    std::cout << CYAN " BadName : "<< Badname << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : "<< RESET " \n";
        std::cout << e.what(); 
    }
    
std:: cout << "\n ------ Test 3 - rank too high ------------------------ \n" << std::endl;
    try
    {    
    Bureaucrat tooHigh("Top", -75);
    std::cout << CYAN "A : "<< tooHigh << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : "<< RESET " \n";
        std::cout << e.what(); 
    }
    
std:: cout << "\n ------ Test 4 - rank too low -------------------------- \n" << std::endl;
    try
    {    
    Bureaucrat tooLow("Flop", 1234);
    std::cout << CYAN "A : "<< tooLow << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : "<< RESET " \n";
        std::cout << e.what(); 
    }
    
std:: cout << "\n------ Test 5 : promotions ------\n" << std::endl;
    try 
    {
    Bureaucrat A("Great", 150);
    A.promote();
    std::cout << CYAN << A << RESET;
    A.promote();
    std::cout << CYAN << A << "\n" RESET ;
    
    Bureaucrat C("Best", 2);
    C.promote();
    std::cout << CYAN << C << RESET;
    C.promote();
    std::cout << CYAN << C << "\n" RESET ;
    }
    catch (const std::exception & e){
        std::cout << e.what(); 
    }
    
std:: cout << "\n------ Test 6 : Lazy workers are demoted ------\n" << std::endl;
    try
    {
        
    Bureaucrat C("Burned-Out", 1);
    C.demote();
    std::cout << CYAN << C << RESET;
    C.demote();
    std::cout << CYAN << C << "\n" RESET;
    
    Bureaucrat A("Lazy", 149);
    A.demote();
    std::cout << CYAN << A << RESET;
    A.demote();
    std::cout << CYAN << A << "\n" RESET ;
    
    }
    catch (const std::exception & e){
        std::cout << e.what(); 
    }
    
    return 0;
}


