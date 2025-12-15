/*

TODO: check char inerdits dans noms de fichier asef efasdasfsdfas
Si oui check target > ex target invalid

creation shrubbery form
cas ok
shruberry allready planted
si ficher existe deja, planter a la place ou apres ?
=
include fstream
ouverture en lecture std::ifstream
ouverture en ecriture std

http://sdz.tdct.org/sdz/lecture-et-ecriture-dans-les-fichiers-en-c.html


Robotomy
faire 10 form, les faire signer par un buro
+> check le random
Ex : robo fail
TODO : try/catch a faire au lvl superieur comme le buro

Pardon
just print the info

executor
ex : grade too low
ex : form pas signe

fonction membre virtual = methode (resolution dynamique)
fonction membre non virtuelle (resolution statique)

classe abstraite
Methode pure => virtual + =0
    methode non utilisable, objet non initiable = classe abstraite

Interface = classe avec que des methodes pure
    interface ne peut pas avoir d'atributs

*/
// #include "../include/colors.hpp"
// #include "../include/PresidentialPardonForm.hpp"
// #include "../include/RobotomyRequestForm.hpp"
// #include "../include/ShruberryCreationForm.hpp"
// #include "../include/Intern.hpp"
// #include <unistd.h>

// int main(void){

//     std:: cout << "\n ------ New Forms : construct & destroy ----------------------" << std::endl;
//     try {
//         RobotomyRequestForm rrf("SubjectA ");
//         PresidentialPardonForm ppf("InnocentMan");
//         ShruberryCreationForm scf("Garden");
//     }
//     catch (const std::exception & e){
//         std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
//     }

//     std:: cout << "\n ------ Intern : construct & destroy ----------------------" << std::endl;
//     try {
//         Intern int_A;
//     }
//     catch (const std::exception & e){
//         std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
//     }
//     std:: cout << "\n ------ Intern : main in subject ----------------------" << std::endl;
//     try {
//         Intern someRandomIntern;
//         AForm* rrf;

//         rrf = someRandomIntern.makeForm("robotomy request", "Bender");
//         delete rrf;
//     }
//     catch (const std::exception & e){
//         std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
//     }
//     std:: cout << "\n ------ Intern : Bad Form Name  ----------------------" << std::endl;
//     try {
//         Intern stud;
//         AForm* form;

//         form = stud.makeForm("save the world", "Bender");
//     }
//     catch (const std::exception & e){
//         std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
//     }
//     std:: cout << "\n ------ Intern creates form, bureaucrat sign it ----------------------" << std::endl;
//     try {
//         Intern someOtherIntern;
//         Bureaucrat B("boss", 1);
//         AForm* ppf;

//         ppf = someOtherIntern.makeForm("presidential pardon", "Bender");

//         if (ppf) {
//             B.signForm(*ppf);
//             B.executeForm(*ppf);
//             delete ppf;
//         }
//     }
//     catch (const std::exception & e){
//         std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
//     }
//     return 0;
// }

#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/colors.hpp"

int main(void)
{   
    std::cout << BG_BLUE "\n------ [0] Intern : construct & destroy ----------------------\n" RESET << std::endl; 
            try {
                Intern int_A;
            }
            catch (const std::exception & e){
                std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
            }

    std::cout << BG_BLUE "\n------ [1] Intern : main in subject ----------------------\n" RESET << std::endl;
            try {
                Intern someRandomIntern;
                AForm* rrf;

                rrf = someRandomIntern.makeForm("robotomy request", "Bender");
                delete rrf;
            }
            catch (const std::exception & e){
                std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
            }     

    std::cout << BG_BLUE "\n------ [2] Intern creates valid forms (polymorphism) ----------------------\n" RESET << std::endl;

        AForm* forms[3];
            try {
                Intern intern;
                Bureaucrat boss("Boss", 1);

                forms[0] = intern.makeForm("robotomy request", "Marvin");
                forms[1] = intern.makeForm("shruberry creation", "Garden");
                forms[2] = intern.makeForm("presidential pardon", "Arthur");

                for (int i = 0; i < 3; i++) {
                    std::cout << BG_YELLOW "\nTrying to sign and exec "<< forms[i]->getName() << RESET " \n" ;
                    boss.signForm(*forms[i]);
                    boss.executeForm(*forms[i]);
                }
            }
            catch (const std::exception & e){
                std::cout << YELLOW "Exception caught : " << e.what() << RESET << std::endl;
            }
            for (int i = 0; i < 3; i++) {
                    delete forms[i];
            }

    std::cout << BG_BLUE "\n------ [3] UNKNOWN Form Name ----------------------\n" RESET << std::endl;
    
        AForm* badName = NULL;
        try {
            Intern stud;
            badName = stud.makeForm("save the world", "Bender");
        }
        catch (const std::exception & e){
            std:: cout << YELLOW "Exception caught : " << e.what() << RESET " \n";
        }
        delete badName;

    std::cout << BG_BLUE "\n------ [4] Playground ----------------------\n" RESET << std::endl;

        AForm* yourForm = NULL;
        Intern intern;
        Bureaucrat boss("Boss", 1);
            try {
                yourForm = intern.makeForm("RODobotomy request", "Marvin");
                boss.signForm(*yourForm);
                boss.executeForm(*yourForm);
            }
            catch (const std::exception & e){
                std::cout << YELLOW "Exception caught : " << e.what() << RESET << std::endl;
            }
        delete yourForm;

        return 0;
}
