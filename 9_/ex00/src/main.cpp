#define RED "\033[38;5;196m"
#define RESET "\033[0m"

#include "btc.hpp"

/*
Check arguments
class declaration
run prog : getAndDisplay 
catch exceptions
*/
int main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << RED "Error : invalid arguments\n" RESET
                << "Usage: ./btc file_name" << std::endl;
		return EXIT_FAILURE;
	}
	try {
		BitcoinEx exchange;
		exchange.getAndDisplay(av);
	} 
    catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}