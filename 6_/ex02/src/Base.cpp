/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:29:30 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/16 16:00:57 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include "../include/colors.hpp"

#include <iostream> // std::cout
#include <ctime> // time 
#include <cstdlib> // rand()

Base::~Base() { }

// randomly instantiates A, B, or C and returns the instance as a Base pointer.
// Use anything you like for the random choice implementation.
// std::srand((unsigned int)std::time(0)); // < init random en debut de main, pas a chaque ft
// Base * generate(void) {
//     int alea = rand() % 3; // < /r 1d3
//     Base * base = NULL;
//     switch (alea) {
//         case 0 :
//             base = new A;
//             break;
//         case 1 :
//             base = new B;
//             break;
//         case 2 :
//             base = new C;
//             break;                
//         default :
//             std::cout << "Unknokn form\n";
//         }
//     return base;
// }


