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
#include "../include/colors.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShruberryCreationForm.hpp"
#include <unistd.h>

int main(void){

    std:: cout << BG_BLUE "\n\n------ [0] AForm is an abstract class (no crash) ----------------------\n" RESET << std::endl;
                //AForm stack; // << Abstract donc impossible de compiler
                AForm* ptr = NULL;
                (void)ptr;

    std::cout << BG_BLUE "\n\n------ [1] New forms : Construct, Sign, Exec, Destruct ----------------------\n" RESET << std::endl;
        try {
            Bureaucrat b("Boss", 1);

            AForm *forms[] = {
                new ShruberryCreationForm("Garden"),
                new RobotomyRequestForm("SubjectX"),
                new PresidentialPardonForm("Innocent")
            };

            for (int i = 0; i < 3; i++) {
                std::cout << BG_YELLOW "\nTest Form " << forms[i]->getName() << RESET "\n";
                b.signForm(*forms[i]);
                b.executeForm(*forms[i]);
                delete forms[i];
            }
        }
        catch (const std::exception & e){
            std::cout << YELLOW "Exeption caught : " << e.what() << RESET "\n";
        }

    std:: cout << BG_BLUE "\n\n------------- [4] Sign & Exec Stack : Schruberry Creation form ---------------\n" RESET << std::endl;
        try {
            ShruberryCreationForm scf("Christmas_home");
            Bureaucrat b("BigBoss", 1);
            scf.beSigned(b);
            scf.isExecuted(b);
        }
        catch (const std::exception & e){
            std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
        }

    std:: cout << BG_BLUE "\n\n ------ [3] Error : Exec_grade too low ----------------------\n" RESET << std::endl;
        try {
                PresidentialPardonForm ppf("InnocentMan");
                Bureaucrat b("MidBoss", 12);

                ppf.beSigned(b);
                ppf.isExecuted(b);
        }
        catch (const std::exception & e){
            std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
        }
    std:: cout << BG_BLUE "\n\n ------ [3.1] Error : Unsigned Form ----------------------\n" RESET << std::endl;
        try {
                PresidentialPardonForm ppf("InnocentMan");
                Bureaucrat b("MidBoss", 12);

                ppf.isExecuted(b);
        }
        catch (const std::exception & e){
            std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
        }

    std:: cout << BG_BLUE "\n\n ------ [4] Error : Invalid Shrub File Name ----------------------\n" RESET << std::endl;
        try {
            ShruberryCreationForm scf("Garden Space");
            Bureaucrat b("BigBoss", 1);

            scf.beSigned(b);
            scf.isExecuted(b);
        }
        catch (const std::exception & e){
            std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
        }

    std:: cout << BG_BLUE "\n\n ------ [5] Success/Failure : Robotomy REQUEST ----------------------\n" RESET << std::endl;
        try {
            RobotomyRequestForm rrf("SubjectA ");
            Bureaucrat b("MidBoss", 42);

            rrf.beSigned(b);
            rrf.isExecuted(b);
        }
        catch (const std::exception & e){
            std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
        }

    return EXIT_SUCCESS;
}