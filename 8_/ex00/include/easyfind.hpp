/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:31 by mairivie          #+#    #+#             */
/*   Updated: 2026/02/05 14:54:55 by mairivie         ###   ########.fr       */
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


// ===== CLASS DECLARATION =====

template <typename T>
typename T::iterator easyfind(T & container, int a) {
    if (container.empty())
        throw std::exception("container is empty");
    
    typename T::iterator it = container.begin();
    while(it != container.end() && *it != a) {
            ++it;    
    }
    if (it == container.end())
        throw std::exception("no occurence found");
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



#endif