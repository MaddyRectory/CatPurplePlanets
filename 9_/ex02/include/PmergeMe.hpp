#pragma once

#define ORANGE "\033[38;5;208m"
#define RED "\033[38;5;196m"
#define TEAL "\033[38;5;49m"
#define PURPLE "\033[38;5;129m"
#define OLIVE "\033[38;5;58m"
#define RESET "\033[0m"

#define SUCCESS 0
#define FAILURE 1

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <exception>
#include <utility>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <typeinfo>

void	checkArgInt(int ac, char **av);
std::vector<int> initVector(int ac, char ** av);
std::deque<int> initDeque(int ac, char **av);
std::vector<int> calc_only_js_needed(int ac);
std::vector<std::pair<int,int> >  create_pairs(std::vector<int> container);


class ArgNotANumber : public std::exception {
public :
    virtual const char *what() const throw() {
        return (RED "at least one argument is not a positiv int.\033[0m");
    }
};

template <typename T> 
T min(T a, T b){
    return (a < b ? a : b);
}

template <typename T> 
T max(T a, T b){
    return (a > b ? a : b);
}

template <typename T>
void swap(T & a, T & b) {
    T temp = a;
    a = b;
    b = temp;
}

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

// ===== Re-utilisation de l'easyfind du 08 =====
//modif a faire pour que ça throw si un doublon est trouvé

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

// ===== SOURCES =====

// about find : https://dpt-info.di.unistra.fr/~grosjean/cpoa/STL.pdf
// page 9
// https://en.cppreference.com/w/cpp/container.html
// source pour les methodes communes aux containers

