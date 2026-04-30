#include "../include/RPN.hpp"

int main(int ac, char **av) {

	if (ac != 2) { 
		std::cerr << RED "Error : invalid arguments\n" RESET
                << "Usage: ./RPN <RPN sequence>"
                << std::endl;
		return EXIT_FAILURE;
	}

	RPN			calculator;
	std::string expression = av[1];
	
	try {
		calculator.calculator(expression);
	}	
    catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/*
#include "RPN.hpp"

int main(int ac, char **av) {
	
if (ac < 2) {
		std::cout << "Usage: ./rpn \"[expression]\"" << std::endl;
		return FAILURE;
	}
	
	RPN			calculator;
	std::string expression = av[1];
	
	try {
		calculator.calculator(expression);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return FAILURE;
	}
	return SUCCESS;
}
*/