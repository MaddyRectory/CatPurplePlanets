/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:31 by mairivie          #+#    #+#             */
/*   Updated: 2026/02/10 16:49:55 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef easyfind_HPP
#define easyfind_HPP

// ===== INCLUDES =====
#include "colors.hpp"
#include <iostream>
#include <exception>
#include <algorithm>
#include <iterator>


// ===== FT_DECLARATION =====

template <typename T>
typename T::iterator easyfind(T & container, int a) {
    if (container.empty())
        throw std::invalid_argument("container is empty");
    
    typename T::iterator it = container.begin();
    while(it != container.end() && *it != a) {
            ++it;    
    }
    if (it == container.end())
        throw std::invalid_argument("no occurence found");
    return it;
}

// template <typename T>
// T * easyfind(T container, int a) {
//     if (container.empty())
//         throw std::exception("container is empty");
    
//     int size = container.size();
//     for (int it = 1; it != size; it++) {
//         if (container[it] == a)
//             return container[it];    // c'est bien un pointeru TODO:
//     }
//     throw std::exception("no occurence found");
// }

template <typename T>
void print(T & container, std::string name) {
    std::cout << name << " [ ";
    
    typename T::iterator it = container.begin();
    while(it != container.end()) {
            std::cout << *it << " ";
            ++it;    
    }
    std::cout << " ]" << std::endl;
}

// ===== SOURCES =====

// about find : https://dpt-info.di.unistra.fr/~grosjean/cpoa/STL.pdf
// page 9
// https://en.cppreference.com/w/cpp/container.html
// source pour les methodes communes aux containers




#endif