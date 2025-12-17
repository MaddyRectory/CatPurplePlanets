/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:25:15 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/17 16:51:14 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cin cout tu coco
#include "../include/colors.hpp"
#include "../include/Serializer.hpp"

int main (void) {
    
    std::cout << GREEN "\nCompilation OK !" RESET << std::endl;
    
    std::cout << BG_BLUE "\n[1] Test : struct data not empty\n" RESET << std::endl;
    
    struct s_data object;
    
        object.x = 1;
        object.y = 2;
        object.z = 42;

    std::cout << "data(x) = " << object.x
            << "\ndata(y) = " << object.y
            << "\ndata(z) = " << object.z << "\n";

    std::cout << "\n INFO: memory adress is : " << &object;

    std::cout << BG_BLUE "\n\n[2] Test : cast magic" RESET << std::endl;
    
    struct s_data * data_ptr = &object;
    uintptr_t data_raw = Serializer::serialize(data_ptr);
    struct s_data * data_ptr_nxt = Serializer::deserialize(data_raw);
    
    std::cout << "data_ptr = " << data_ptr
            << "\ndata_raw = " << data_raw
            << "\ndata_ptr_nxt = " << data_ptr_nxt << " \n";

    if (data_ptr == data_ptr_nxt)
        std::cout << GREEN "\ndata_ptr == data_ptr_nxt. GG !\n" << std::endl;
        
    return 0;
}

//Subject : quel diff entre une struct et une classe en cpp
//pk + pertinent la struct ici ?
// reinterpret_cast et uintptr_t