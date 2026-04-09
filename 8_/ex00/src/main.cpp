/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:38 by mairivie          #+#    #+#             */
/*   Updated: 2026/04/09 09:25:46 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

#include <vector>
#include <list>
#include <deque>
#include <algorithm>


#include <iostream>

//typename T::iterator easyfind(T & container, int a) {
//void print(T & container, std::string name)

// template <typename T>
// typename T::iterator easyfind(T & container, int a) {
//     if (container.empty())
//         throw std::invalid_argument("container is empty");
    
//     typename T::iterator it = container.begin();
//     while(it != container.end() && *it != a) {
//             ++it;    
//     }
//     if (it == container.end())
//         throw std::invalid_argument("no occurence found");
//     return it;
// }

// template <typename T>
// void print(T & container, std::string name) {
//     std::cout << name << " [ ";
    
//     typename T::iterator it = container.begin();
//     while(it != container.end()) {
//             std::cout << *it << " ";
//             ++it;    
//     }
//     std::cout << " ]" << std::endl;
// }


int main(void) {

    std::cout << CYAN "=== Empty Container ===" RESET << std::endl;
    try {
    std::vector<int> v;
    easyfind(v, 42);
    std::cout <<"target found !"<< std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

        std::cout << RED "\n=== No Occurence found ===" RESET << std::endl;
    try
    {
    std::vector<int> v;
    v.push_back(6);
    v.push_back(9);
    
    easyfind(v, -42);
    std::cout << "target found !" << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    int values[6] = {42, 4, 2, -42, 4242, -142};
    //container(first, last); = constructeur par range, 
    //construit le container avec tous les elements entre first (inclus) et last (exclus) 
    int target = 42;
    std::cout << "target is : " << target << std::endl;
    
    std::cout << CYAN "\n=== VECTOR ===" RESET << std::endl;
    try {
    std::vector<int> v(&values[0], &values[6]);
    print<std::vector<int> >(v, "State 0");
    v.push_back(6);
    v.push_back(9);
    print<std::vector<int> >(v, "State 1");
    v[2] = -1;
    print<std::vector<int> >(v, "State 2");

    
    easyfind(v, target);
    std::cout << GREEN "target found !" RESET << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::cout << CYAN "\n=== LIST ===" RESET << std::endl;
    try
    {
    std::list<int> v(&values[0], &values[6]);
    print<std::list<int> >(v, "State 0");
    v.push_back(6);
    v.push_back(9);
    print<std::list<int> >(v, "State 1");
    
    easyfind(v, target);
    std::cout << GREEN "target " << target << " found !" RESET << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << CYAN "\n=== DEQUE ===" RESET << std::endl;
    try
    {
    std::deque<int> v(&values[0], &values[6]);
    print<std::deque<int> >(v, "State 0");
    v.push_back(6);
    v.push_front(9);
    print<std::deque<int> >(v, "State 1");
    
    easyfind(v, target);
    std::cout << GREEN "target found !" RESET << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}