/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:20:04 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/08 15:43:33 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void){
    
    std:: cout << "\n ------ Test 1 : construct, annonce, destroy ------" << std::endl;
    try
    {
    Form F("Test", 25, 10);
    std::cout << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    }

    std:: cout << "\n\n\n ------------- Test 2 : sign grade too low  ----------------\n\n\n";
    try
    {
    Form F("sign_to_low", 250, 10);
    std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    }
    
    std:: cout << "\n\n\n ------------- Test 3 : sign grade too high  ----------------\n\n\n";
    try
    {
    Form F("sign_to_high", 0, 10);
    std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    }

    std:: cout << "\n\n\n ------------- Test 4 : exec grade too low  ----------------\n\n\n";
    try
    {
    Form F("sign_to_low", 25, 1000);
    std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    }

    std:: cout << "\n\n\n ------------- Test 5 : exec grade too high  ----------------\n\n\n";
    try
    {
    Form F("sign_to_high", 25, 0);
    std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    }

    std:: cout << "\n\n\n ------------- Test 6 : low rank and sign twice  ----------------\n\n\n";

    try
    {
    std:: cout << "[We need to hire a new victim]\n";
    Bureaucrat john("John", 150);
        
    std:: cout << "\n[HR ask we update the Soul's Selling Contract]\n";
    Form devil_deal("S.S.C.", 150, 10);
    std::cout << devil_deal << "\n";

    std:: cout << "[Time to test it in production]\n";
    devil_deal.beSigned(john);
    std::cout << devil_deal << "\n";

    std:: cout << "[Try to sign same form again]\n";
    john.signForm(devil_deal);
    std::cout << devil_deal << "\n";
    }
    catch(const std::exception &e) {
        
    }

    std:: cout << "\n\n\n ------------- Test 7 : sign with rank too low ? and higher ?  ----------------\n\n\n";
    try
    {
    std:: cout << "[Voluntary bureaucrat please ?]\n";
    Bureaucrat bob("Robert", 42);
        
    std:: cout << "\n[And some random contracts please]\n";
    Form form_01("C52 bis", 52, 52);
    Form form_02("B007", 7, 7);

    std:: cout << RESET "[rank higher]\n";
    bob.signForm(form_01);
    std::cout << form_01 << "\n";

    std:: cout << "[rank lower]\n";
    bob.signForm(form_02);
    std::cout << form_02 << "\n";
    }
    catch(const std::exception &e) {
        
    }
    
    std:: cout << "\n\n\n ------------- Test 8 : sign after promote ?  ----------------\n\n\n";
        try
    {
    std:: cout << "[Two voluntary bureaucrats please ?]\n";
    Bureaucrat tic("Tic", 100);
    Bureaucrat tac("Tac", 100);
        
    std:: cout << "\n[And some random contracts please]\n";
    Form form_01("C99.1", 99, 42);
    Form form_02("C99.2", 99, 42);

    std:: cout << RESET "[promote Tic]\n";
    tic.promote();
    tic.signForm(form_01);
    std::cout << form_01 << "\n";

    std:: cout << "[Tac still 100]\n";
    tac.signForm(form_02);
    std::cout << form_02 << "\n";
    }
    catch(const std::exception &e) {
        
    }

    std:: cout << "\n\n\n ------------- Test 9 : sign after demote ?  ----------------\n\n\n";
    try
    {
    std:: cout << "[Two voluntary bureaucrats please ?]\n";
    Bureaucrat tic("Tic-bis", 100);
    Bureaucrat tac("Tac-bis", 100);
        
    std:: cout << "\n[And some random contracts please]\n";
    Form form_01("C100.1", 100, 42);
    Form form_02("C100.2", 100, 42);

    std:: cout << "[Tac bis still 100]\n";
    tac.signForm(form_02);
    std::cout << form_02 << "\n";
    
    std:: cout << RESET "[demote Tic bis to 101]\n";
    tic.demote();
    tic.signForm(form_01);
    std::cout << form_01 << "\n";

    }
    catch(const std::exception &e) {
        
    }
}
