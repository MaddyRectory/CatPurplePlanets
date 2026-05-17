#include "../include/PmergeMe.hpp"


void	checkArgInt(int ac, char **av) {
	for (int i = 1; i < ac ; i++) {
        if (std::strtol(av[i], NULL, 10) <= 0)
            throw ArgNotANumber();
    }
    std::cout << OLIVE "DEBUG: check arg == int ok." RESET << std::endl;
}

//strtol(nptr, NULL, 10);

std::vector<int> initVector(int ac, char **av){
	
    std::vector<int> result;
    for (int i = 1; i < ac ; i++) {
        if (std::strtol(av[i], NULL, 10) <= 0)
            throw ArgNotANumber();
        result.push_back(std::strtol(av[i], NULL, 10));
    }
    std::cout << OLIVE "DEBUG: fin initContainerVector" RESET << std::endl;
    print<std::vector<int> >(result, "Vector_ready");   
    return result;
}

std::vector<std::pair<int,int> >  create_pairs(std::vector<int> container) {
    std::vector<std::pair<int,int> > result;

    for(int i = 0; i < (int)container.size() -1; i += 2 ){
        std::pair<int,int> tmp = std::make_pair(container[i], container[i+1]);
        if (tmp.first < tmp.second)
            swap(tmp.first, tmp.second);
        result.push_back(tmp);
    }

    // DEBUG - print la liste des pairs en colonne
    int j = 0;
    while (j < (int)result.size()) {
        std::cout << "( "<< result[j].first << ", "<< result[j].second << ")\n"; 
        j++;
    }
    return result;
}

std::vector<int> calc_only_js_needed(int nb_pair) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    int n = 2;
    while (jacobsthal.back() < nb_pair) {
        int jacob_next = jacobsthal[n-1] + (2 * jacobsthal[n-2]);
        jacobsthal.push_back(jacob_next);
        n++;
    }
    print<std::vector<int> >(jacobsthal, "JJ suit");
    return jacobsthal;
}


std::deque<int> initDeque(int ac, char **av){
	
    std::deque<int> result;
    for (int i = 1; i < ac ; i++) {
        if (std::strtol(av[i], NULL, 10) <= 0)
            throw ArgNotANumber();
        result.push_back(std::strtol(av[i], NULL, 10));
    }
    std::cout << OLIVE "DEBUG: fin initDEQ" RESET << std::endl; 
    print<std::deque<int> >(result, "deck init");      
    return result;
}


//------------- UTILS

/*
void	checkArgInt(int ac, char **av) {
	for (int i = 1; i < ac ; i++) {
        if (std::strtol(av[i]) < 0)
		    std::cout << av[i] << " ";
        else
            throw ArgNotANumber();
    }
    
	std::cout << std::endl;
}
*/

