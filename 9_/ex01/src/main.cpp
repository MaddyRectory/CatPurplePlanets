#include "../include/RPN.hpp"

int main(int ac, char **av) {

	if (ac != 2) { 
		std::cerr << RED "Error : invalid arguments\n" RESET
                << "Usage: ./RPN <RPN sequence>"
                << std::endl;
		return EXIT_FAILURE;
	}
	
	for (int i=0; i<ac; i++) {
		std::cout << av[i] << std::endl;
	}
	/* code here */

	try {
		/* code here */
	} 
    catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}