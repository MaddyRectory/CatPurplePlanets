#include "../include/PmergeMe.hpp"


void	checkArgInt(int ac, char **av) {
	for (int i = 1; i < ac ; i++) {
        if (std::atoi(av[i]) <= 0)
            throw ArgNotANumber();
    }
    std::cout << OLIVE "DEBUG: check arg == int ok." RESET << std::endl;
}

std::vector<int> initContainer(int ac, char **av){
	
    std::vector<int> result;
    for (int i = 1; i < ac ; i++) {
        if (std::atoi(av[i]) <= 0)
            throw ArgNotANumber();
        result.push_back(std::atoi(av[i]));
    }
    std::cout << OLIVE "DEBUG: fin initContainerVector" RESET << std::endl;
    print<std::vector<int> >(result, "vec init");   
    return result;
}

std::list<int> initList(int ac, char **av){
	
    std::list<int> result;
    for (int i = 1; i < ac ; i++) {
        if (std::atoi(av[i]) <= 0)
            throw ArgNotANumber();
        result.push_back(std::atoi(av[i]));
    }
    std::cout << OLIVE "DEBUG: fin initLIST" RESET << std::endl; 
    print<std::list<int> >(result, "list init");      
    return result;
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

