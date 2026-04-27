#include "../include/btc.hpp"

/*
int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << "Error : bad argument\n";
        return EXIT_FAILURE ;
    }
    std::cout << "File name: " << av[1] << std::endl;
    if ()
    
    

    return EXIT_SUCCESS;
}
*/    

int main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << RED "Error : invalid arguments\n" RESET
                << "Usage: ./btc file_name"
                << std::endl;
		return EXIT_FAILURE;
	}
	
	BitcoinExchange exchange;

	try {
		exchange.getAndDisplay(av);
	} 
    catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}