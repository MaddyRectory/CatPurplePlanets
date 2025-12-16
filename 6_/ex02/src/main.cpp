/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:07:00 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/16 16:41:40 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../include/colors.hpp"
#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

// randomly instantiates A, B, or C and returns the instance as a Base pointer.
// Use anything you like for the random choice implementation.
Base * generate(void) {
    int alea = rand() % 3; // < /r 1d3
    Base * ptr = NULL;
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
        if (dynamic_cast<A*>(p))
            std::cout << YELLOW "class A\n" RESET;
        if (dynamic_cast<B*>(p))
            std::cout << PURPLE "class B\n" RESET;
        if (dynamic_cast<C*>(p))
            std::cout << CYAN "class C\n" RESET;
    
}

        // if (dynamic_cast<A*>(p))
        //     std::cout << YELLOW "class A\n" RESET;
        // else if (dynamic_cast<B*>(p))
        //     std::cout << PURPLE "class B\n" RESET;
        // else if (dynamic_cast<C*>(p))
        //     std::cout << CYAN "class C\n" RESET;
        // else
        //     std::cout << RED "class Base\n" RESET;

// // Prints the actual type of the object referenced by p: "A", "B", or "C". 
// // Using a pointer inside this function is forbidden.
// void identify(Base& p) {
//         if (dynamic_cast<A*>(p))
//             std::cout << "C'est un A\n";
//         if (dynamic_cast<B*>(p))
//             std::cout << "C'est un B\n";
//         if (dynamic_cast<C*>(p))
//             std::cout << "C'est un C\n";
// }

int main (void) {
    
    std::cout << GREEN "\nCompilation OK !" RESET << std::endl;
    
    std::srand((unsigned int)std::time(0)); // < init random en debut de main, pas a chaque ft boulette
    
    std::cout << BG_BLUE "\nTest random generator" RESET << std::endl;
        int now = 0;
        int nb_test = 0;
        int result[3];
        
        for (int i = 0; i <= 99999; i++) { 
            now = rand() % 3;
            result[now]++;
            nb_test++;
        }
        std::cout << nb_test << " random test. \nResult 0/1/2 are " YELLOW
            << result[0] << " / " PURPLE 
            << result[1] << " / " CYAN
            << result[2] << RESET " \n";

            
    std::cout << BG_BLUE "\nGenerate & Identify one instance (ptr)" RESET << std::endl;
        Base * ptr = NULL; 

        ptr = generate();
        identify(ptr);
        delete ptr;

        
    std::cout << BG_BLUE "\nGenerate & Identify multi instance (ptr)" RESET << std::endl;
        Base * list[10];
        for (int i = 0; i <= 9; i++) { 
            list[i] = generate();
            identify(list[i]);
            delete list[i];
        }
    
        return 0;
}