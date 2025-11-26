/*
creation announce destruction (check form permission)
Shrub
Rbo
pard



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
#include "../include/../include/colors.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShruberryCreationForm.hpp"

int main(void){

    std:: cout << "\n------ Test Bur00 : Best workers get promotions -----------------\n" << std::endl;
    try
    {
    Bureaucrat A("Good", 150);
    Bureaucrat B("Great", 42);
    Bureaucrat C("Best", 2);

    A.promote();
    std::cout << CYAN << A << RESET;
    B.promote();
    std::cout << CYAN << B << RESET;
    C.promote();
    std::cout << CYAN << C << RESET;

    A.promote();
    std::cout << CYAN << A << RESET ;
    B.promote();
    std::cout << CYAN << B << RESET ;
    C.promote();
    std::cout << CYAN << C << RESET ;
    
    }
    catch (const std::exception & e){
        std::cout << e.what() << std::endl; 
    }
    
    std:: cout << "\n------ Test Bur01 : Lazy workers are demoted -----------------" << std::endl;
    try
    {
    Bureaucrat A("Stupid", 149);
    Bureaucrat B("Lazy", 42);
    Bureaucrat C("Burned-Out", 1);

    C.demote();
    std::cout << CYAN << C << RESET;
    B.demote();
    std::cout << CYAN << B << RESET;
    A.demote();
    std::cout << CYAN << A << RESET;

    C.demote();
    std::cout << CYAN << C << RESET;
    B.demote();
    std::cout << CYAN << B << RESET;
    A.demote();
    std::cout << CYAN << A << RESET;
    
    }
    catch (const std::exception & e){
        std::cout << e.what() << std::endl; 
    }

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

    std:: cout << "\n ------ New Forms : sign then exec ----------------------" << std::endl;
    try
        {
        Bureaucrat b("BigBoss", 1);
        
        PresidentialPardonForm ppf("InnocentMan");
        ppf.beSigned(b);
        ppf.execute(b);
        RobotomyRequestForm rrf("SubjectA ");
        rrf.beSigned(b);
        rrf.execute(b);
        ShruberryCreationForm scf("Garden");
        scf.beSigned(b);
        scf.execute(b);


        }
    catch (const std::exception & e){
        std:: cout << YELLOW "Exeption caught : " << e.what() << RESET " \n";
    }



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