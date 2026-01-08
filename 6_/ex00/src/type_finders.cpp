#include "../include/ScalarConverter.hpp"

//enum Type {UNKOWN, CHAR, INT, FLOAT, DOUBLE, PSEUDO_LIT, INVALID };

//leng ==1 + pas un chiffre
bool	typeIsChar(std::string str, Type* ptr) {
        if (str.length() == 1 
            && str.find_first_of("0123456789") == std::string::npos)
            return (*ptr = CHAR, true);
        return false;
} 

//only digit e-
bool	typeIsInt(std::string str, Type* ptr) {
        if (str.find_first_not_of("0123456789-") == std::string::npos 
            && (str.find_last_of("-") == 0 || str.find_last_of("-") == std::string::npos)) 
            {
                *ptr = INT;
                return true;
            }
        return false;
} 

bool	typeIsFloat(std::string str, Type* ptr) {
        if (str.find_first_not_of("-0123456789.f") == std::string::npos
            && (str.find_last_of("-") == 0 || str.find_last_of("-") == std::string::npos) 
            && (str.find_first_of("f") == str.length() - 1)
            && (isdigit(str[str.find(".") - 1]) && isdigit(str[str.find(".") + 1])) )
            {
                *ptr = FLOAT;
                return true;
            }
        return false;
}

bool	typeIsDouble(std::string str, Type* ptr) {
        if (str.find_first_not_of("-0123456789.") == std::string::npos
            && (str.find_last_of("-") == 0 || str.find_last_of("-") == std::string::npos) 
            && (isdigit(str[str.find(".") - 1]) && isdigit(str[str.find(".") + 1])) )
            {
                *ptr = DOUBLE;
                return true;
            }
        return false;
}

//on a la liste exacte
bool	typeIsPseudo(std::string str, Type* ptr) { 
    
    	std::string special_cases[6] = {"nan", "nanf", "+inf", "-inf", "-inff", "+inff"};
        
        for (int i = 0; i < 6; i++) {
            if (str == special_cases[i])
                return (*ptr = PSEUDO_LIT, true);
        }
        return false;
}

bool	isInvalid(std::string str, Type* ptr) {
        std::cout << RED "ERROR: " << str << " is not a valid input.\n" ;
        *ptr = INVALID;
        return false;
}