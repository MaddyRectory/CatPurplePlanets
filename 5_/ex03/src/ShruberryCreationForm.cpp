/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:59:16 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/02 16:47:10 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShruberryCreationForm.hpp"
#include "../include/colors.hpp"
#include <iostream>
#include <fstream>
#include <string>


ShruberryCreationForm::ShruberryCreationForm(std::string target) 
    : AForm("ShruberryCreationForm", target, 145, 137) {}

ShruberryCreationForm::ShruberryCreationForm(const SCForm & toCopy)
    : AForm(toCopy) {}

ShruberryCreationForm::~ShruberryCreationForm() {
    std::cout   << "Shruberry Form " << BLUE " safely shredded !\n" RESET ;
}

ShruberryCreationForm & ShruberryCreationForm::operator=(const SCForm & toCopy) {
    if (this != &toCopy)
        AForm::operator=(toCopy);
    return *this;
}

const char * ShruberryCreationForm::NameTooLong::what() const throw() {
    return " unable to create a file with this target's name.\n lenght max = 100\n" ; 
}

const char * ShruberryCreationForm::NameInvalidChar::what() const throw() {
    return " unable to create a file with this target's name.\n need only letters, digits, - or _\n" ; 
}

std::string ShruberryCreationForm::_createFileName() const {
    if (getTarget().size() > 100)
        throw ShruberryCreationForm::NameTooLong();
    std::string goodCharFilename = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_";
    if (getTarget().find_first_not_of(goodCharFilename) != std::string::npos)
        throw ShruberryCreationForm::NameInvalidChar();
    std::string fileName = getTarget() + "_shrubbery";
    return fileName;
};

std::string ShruberryCreationForm::_createForest() const {
    std::string forest;

    forest += "\n    ()           ()           ()    \n";
    forest += "    /\\           /\\           /\\   \n";
    forest += "   / *\\         / *\\         / *\\  \n";
    forest += "  / *  \\       / *  \\       / *  \\ \n";
    forest += " / *  * \\     / *  * \\     / *  * \\ \n";
    forest += " ^^^[]^^^     ^^^[]^^^     ^^^[]^^^ \n";
    forest += "---------------------------------------\n";
    forest += "     *            *            *     \n";
    forest += "    /.\\          /.\\          /.\\   \n";
    forest += "   /o..\\        /o..\\        /o..\\  \n";
    forest += "   /..o\\        /..o\\        /..o\\  \n";
    forest += "  /.o..o\\      /.o..o\\      /.o..o\\ \n";
    forest += "  /...o.\\      /...o.\\      /...o.\\ \n";
    forest += " /..o....\\    /..o....\\    /..o....\\ \n";
    forest += " ^^^[_]^^^    ^^^[_]^^^    ^^^[_]^^^ \n";
    forest += "---------------------------------------- \n";

    return forest;    
};

void ShruberryCreationForm::action() const {
    std::cout << YELLOW " Operation shruberry ! NOW!\n" RESET;
    std::string fileName = _createFileName();
    std::cout << GREEN " Magic forest successfully created. \n"
        << RESET " Please cat [ " << fileName 
        << " ] to get your trees ! Merry Xmas :)\n\n";
    std::string forest = _createForest();
    std::fstream ofs(fileName.c_str(), std::ios::out);
    ofs << forest;
}

    // std::ofstream shrub(fileName, std::ios::out | std::ios::app);
    
    
    // if !shrub)
    //     throw //impossible d'ouvrir le fichier
    

// check nom de target valide pour fichier 
//creer string nom du fichier (append) avec target
// check si fichier existe
// non :
// creer ostream du fichier (check c'est quoi les ios::machin )
//  exept : erreur creation fichier, target invalide, 
// >>> FT grow forest generer la foret string
// put forest dans fichier via ostream
// oui : 
// get ofstream du fichier
// aller a la fin + ajouter foret
// raser contenu du fichier et planter foret a la place
// close file

