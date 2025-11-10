/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:20:04 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/10 20:06:18 by mairivie         ###   ########.fr       */
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

    std:: cout << "\n ------ Test 2 : sign grade to low ------ " << std::endl;
    try
    {
    Form F("sign_to_low", 250, 10);
    std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    }

    std:: cout << "\n ------ Test 3 sign grade to high ------ " << std::endl;
    try
    {
    Form F("sign_to_high", 0, 10);
    std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    }

    std:: cout << "\n ------ Test 4 : exec grade to low ------ " << std::endl;
    try
    {
    Form F("sign_to_low", 25, 1000);
    std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    }

    std:: cout << "\n ------ Test 5 : exec grade to high ------ " << std::endl;
    try
    {
    Form F("sign_to_high", 25, 0);
    std::cout << PURPLE << F << RESET;
    }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    }

    std:: cout << "\n ------ Test 6 : now we make a deal ------" << std::endl;
    try
    {
    std:: cout << "[We need to hire a new victim]\n";
    Bureaucrat john("John", 150);
        
    std:: cout << "\n[HR ask we update the soul's selling contract]\n";
    Form devil_deal("S.S.C.", 150, 10);
    std::cout << CYAN "Form's info : "<< devil_deal << RESET "\n";

    std:: cout << "[Time to test it in production]\n";
    devil_deal.beSigned(john);
    std::cout << CYAN "Form's info : "<< devil_deal << RESET "\n";

    std:: cout << "[Try to sign same form again]\n";
    john.signForm(devil_deal);
    std::cout << CYAN "Form's info : "<< devil_deal << RESET "\n";
    }
    catch(const std::exception &e) {
        
    }
}