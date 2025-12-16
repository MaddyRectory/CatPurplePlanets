/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:07:00 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/16 18:38:29 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cin cout tu coco
#include <ctime> // init du random
#include <cstdlib> //usage du random
#include <exception> // je voulais typeinfo pour bad_cast mais interdit :(
#include "../include/colors.hpp"
#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

// randomly instantiates A, B, or C and returns the instance as a Base pointer.
// Use anything you like for the random choice implementation.
Base * generate(void) {
    Base * ptr = NULL;
    int alea = rand() % 3;
    
    switch (alea) {
        case 0 :
            ptr = new A;
            break;
        case 1 :
            ptr = new B;
            break;
        case 2 :
            ptr = new C;
            break;                
        default :
            std::cout << "Unknokn form\n";
        }
    return ptr;
}

// Prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base* p) {
        if (dynamic_cast<A*>(p) != NULL)
            std::cout << YELLOW "class A\n" RESET;
        else if (dynamic_cast<B*>(p) != NULL)
            std::cout << PURPLE "class B\n" RESET;
        else if (dynamic_cast<C*>(p) != NULL)
            std::cout << CYAN "class C\n" RESET;
        else 
            std::cout << RED "WTF c'est quoi cette classe inconnue ?\n" RESET;
}

// Prints the actual type of the object referenced by p: "A", "B", or "C". 
// Using a pointer inside this function is forbidden.
// Including the typeinfo header is forbidden. 
void identify(Base & p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << YELLOW "class A\n" RESET;
        (void)a;
        return;
    }
    catch (const std::exception& e) { }
    
    try {
        B & b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << PURPLE "class B\n" RESET;
        return;
    }
    catch (const std::exception& e) { }
        
    try {
        C & c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << CYAN "class C\n" RESET;
        return;
    }
    catch (const std::exception& e) { }
}

// NB: echec de cast sur reference throw std::bad_cast
//mais <typeinfo> interdit donc exception = generaliste

int main (void) {
    
    std::cout << GREEN "\nCompilation OK !" RESET << std::endl;
    
    std::srand((unsigned int)std::time(0)); // < init random en debut de main, pas a chaque ft boulette
    
    std::cout << BG_BLUE "\nTest random generator" RESET << std::endl;
        int now = 0;
        int nb_test = 0;
        int result[3] = {0};
        
        for (int i = 0; i <= 99999; i++) { 
            now = rand() % 3;
            result[now]++;
            nb_test++;
        }
        std::cout << nb_test << " random test. \nResult 0/1/2 are " YELLOW
            << result[0] << " / " PURPLE 
            << result[1] << " / " CYAN
            << result[2] << RESET " \n";

            
    std::cout << BG_BLUE "\nPTR - Generate & Identify one instance (ptr >> NULL)" RESET << std::endl;
        Base * ptr = NULL; 
        ptr = generate();
        identify(ptr);
        delete ptr;

    std::cout << BG_BLUE "\nREFF - Generate & Identify one instance (ref >> exception)" RESET << std::endl;
        Base * b = generate();
        Base & ref = *b; 
        identify(ref);
        delete b;
        
    std::cout << BG_BLUE "\n Compare Identify(ptr) & Identify(ref)" RESET << std::endl;
        Base * list[4];
        for (int i = 0; i <= 3; i++) { 
            list[i] = generate();
            std::cout << "Comp. nbr " << i << " : \n" << std::endl;
            identify(list[i]); //ptr
            identify(*list[i]); //ref
            
            delete list[i];
        }
        return 0;
}