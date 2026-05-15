#include "../include/PmergeMe.hpp"


void	checkArgInt(int ac, char **av) {
	for (int i = 1; i < ac ; i++) {
        if (std::atoi(av[i]) <= 0)
            throw ArgNotANumber();
    }
    std::cout << OLIVE "DEBUG: check arg == int ok." RESET << std::endl;
}

//------------- UTILS

/*
void	checkArgInt(int ac, char **av) {
	for (int i = 1; i < ac ; i++) {
        if (std::atoi(av[i]) < 0)
		    std::cout << av[i] << " ";
        else
            throw ArgNotANumber();
    }
    
	std::cout << std::endl;
}
*/

