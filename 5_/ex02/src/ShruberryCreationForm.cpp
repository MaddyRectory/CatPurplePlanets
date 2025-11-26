/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:16 by mairivie          #+#    #+#             */
/*   Updated: 2025/11/26 19:15:57 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShruberryCreationForm.hpp"
#include "../include/colors.hpp"
#include <iostream>
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm(std::string target) 
    : AForm("ShruberryCreationForm", target, 145, 137) {}

ShruberryCreationForm::ShruberryCreationForm(const SCForm & toCopy)
    : AForm(toCopy) {}

ShruberryCreationForm::~ShruberryCreationForm() {
    std::cout   << CYAN << "Shruberry Form safely shredded !\n" RESET ;
}

ShruberryCreationForm & ShruberryCreationForm::operator=(const SCForm & toCopy) {
    if (this != &toCopy)
        AForm::operator=(toCopy);
    return *this;
}

void ShruberryCreationForm::action() {
    std::cout << "OMG a Shruberry !\n";
    std::ofstream shrub("test.txt", std::ios::out | std::ios::app);
    // if !shrub)
    //     throw //impossible d'ouvrir le fichier
    
}