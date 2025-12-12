/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:20:04 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/12 15:16:22 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void){
    
std:: cout << "\n ------ Test 1 : DEFAULT construct, annonce, destroy ------" << std::endl;
    try {
        Form blank;
        std::cout << blank << RESET;
        } 
    catch (const std::exception & e) {
        std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
    }
    
std:: cout << "\n ------ Test 1bis : construct, annonce, destroy ------" << std::endl;
    try {
        Form F("TIG", 142, 42);
        std::cout << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
    }

    std:: cout << "\n------------- Test 2 : sign grade too low  ----------------\n";
    try {
        Form F("sign_to_low", 250, 10);
        std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
    }
    
std:: cout << "------------- Test 3 : sign grade too high  ----------------\n";
    try {
        Form F("sign_to_high", 0, 10);
        std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
    }

    std:: cout << "------------- Test 4 : exec grade too low  ----------------\n";
    try {
        Form F("sign_to_low", 25, 1000);
        std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
    }

std:: cout << "------------- Test 5 : exec grade too high  ----------------\n";
    try {
        Form F("sign_to_high", 25, 0);
        std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
    }

std:: cout << " ------------- Test 6 : Sign twice  ----------------\n";

    try {
        Bureaucrat john("John", 142);
        Form devil_deal("SoulSellingContract", 150, 10);

        std:: cout << "[Sign this innocent piece of paper]\n";
        std::cout << devil_deal << "\n";
        
        devil_deal.beSigned(john);
        
        std::cout << devil_deal << "\n";

        std:: cout << "[Try to sign same form again]\n";
        
        devil_deal.beSigned(john);
    }
    catch(const std::exception &e) {
        std:: cout << YELLOW "Error : " << e.what() << RESET " \n";
    }

std:: cout << " \n------------- Test 7 : sign rank too low----------------\n";
    try {
        Bureaucrat buro("Bobby", 125);
        Form form_02("Big Contract", 52, 7);
        
        buro.signForm(form_02);
        std::cout << form_02 << "\n";
    }
    catch(const std::exception &e) {
                std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
    }
}


// TODO : adieu les catch dans les .cpp, c'est dans le main que je dois gerer ca
// oui oui, meme si c'est moche
// = on s'en moque les destructeurs sont pas visibles
// rajoute des tabs
// remet des accolades
// doc sur les int en reference (pas fou comme pratique)