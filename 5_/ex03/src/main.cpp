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
#include "../include/Intern.hpp"
#include <unistd.h>

int main(void){

    std:: cout << "\n ------ New Forms : construct & destroy ----------------------" << std::endl;
    try
        {
        RobotomyRequestForm rrf("SubjectA ");
        PresidentialPardonForm ppf("InnocentMan");
        ShruberryCreationForm scf("Garden");
        }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    }

    std:: cout << "\n ------ Intern : construct & destroy ----------------------" << std::endl;
    
        Intern int_A;

    // std:: cout << "\n ------ Intern : new test ----------------------" << std::endl;
    
    //     Intern int_A;

    // try {}

    // std:: cout << "\n ------ New Forms : sign & exec ----------------------" << std::endl;
    // try
    //     {
    //     Bureaucrat b("BigBoss", 1);

    //     std:: cout << "\n   ---- Presidential Pardon ----------------\n ";
    //     PresidentialPardonForm ppf("InnocentMan");
    //     ppf.beSigned(b);
    //     ppf.isExecuted(b);
    //     std:: cout << "\n   ---- Robotomy Request ------------------\n ";
    //     RobotomyRequestForm rrfb("Subject X");
    //     rrfb.beSigned(b);
    //     rrfb.isExecuted(b);
    //     std:: cout << "\n   ---- Shruberry Creation ------------------\n ";
    //     ShruberryCreationForm scf("Garden");
    //     scf.beSigned(b);
    //     scf.isExecuted(b);

    //     }
    // catch (const std::exception & e){
    //     std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    // }

    // std:: cout << "\n ------ Now it's your turn ----------------------" << std::endl;
    // try
    //     {
    //     //hire different graded bureaucrat
    //     Bureaucrat a("BigBoss", 1);
    //     Bureaucrat b("MidBoss", 19);
    //     Bureaucrat c("MiniBoss", 142);

    //     //choose your form
    //     PresidentialPardonForm ppf("InnocentMan");
    //     // RobotomyRequestForm rrf("Subject X");
    //     // ShruberryCreationForm scf("Garden");

    //     //do your tests
    //     ppf.beSigned(a); 
    //     ppf.isExecuted(a);
    //     // ppf.beSigned(a);   
    //     // ppf.isExecuted(a);
    //     }
    // catch (const std::exception & e){
    //     std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    // }



    // RobotomyRequestForm rrf("SubjectA ");
    // RobotomyRequestForm rrfb("SubjectB ");
    // rrf.beSigned(b);
    // rrf.execute(b);
    //         rrf.execute(b);
    // rrfb.beSigned(b);
    // rrfb.execute(b);
    //         rrfb.execute(b); 

    return 0;
}