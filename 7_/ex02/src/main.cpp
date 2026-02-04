/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:07:31 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/21 14:58:15 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.hpp"
#include "../include/iter.hpp"
#include "../include/Array.hpp"
#include <iostream>

//main du sujet

// #include <ctime>
// #include <cstdlib>
// #define MAX_VAL 750
// int main(int, char**)
// {
//     std::cout << GREEN "Compilation OK !" RESET << std::endl;
    
//     srand(time(NULL));
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
    
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     std::cout << BG_BLUE "Test i < 0 (Exception)" RESET << std::endl;
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     std::cout << BG_BLUE "Test i > _size (Exception)" RESET << std::endl;
//     try
//     {
//         numbers[MAX_VAL + 1] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << RED << e.what() << RESET "\n";
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror; //
//     return 0;
// }

//main perso aui teste reelement des trucs ahahah
#include <ctime>
#include <cstdlib>
#define MAX_VAL 5

template <typename T>
void printType(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void increase(T &x) {
    x++;
}

int main(void){
    std::cout << GREEN "Compilation OK !" RESET << std::endl;
    srand(time(NULL));
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
    std::cout << ": ";
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 100;
        std::cout << value << " ";
        numbers[i] = value;
        mirror[i] = value;
    }

    iter<int>(numbers, MAX_VAL, increase<int>(numbers))

    std::cout << BG_BLUE "\nTest i > _size (Exception)" RESET << std::endl;

    return 0;
}