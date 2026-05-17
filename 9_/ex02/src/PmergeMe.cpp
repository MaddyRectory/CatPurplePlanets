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
//    print<std::vector<int> >(result, "Vector_ready");   
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
    std::sort(result.begin(), result.end());

    j = 0;
    while (j < (int)result.size()) {
        std::cout << "... ( "<< result[j].first << ", "<< result[j].second << ")\n"; 
        j++;
    }

    return result;
}

std::vector<int> vecFordJohnson(std::vector<std::pair<int,int> > vecPair, std::vector<int> jacob, int straggler) {
    std::vector<int> result;
    std::vector<int> big;
    std::vector<int> small;

    result.reserve(vecPair.size() * 2 + 1);
    small.reserve(vecPair.size());
    small.reserve(vecPair.size());

    for(int i = 0; i < (int)vecPair.size(); i++) {
        result.push_back(vecPair[i].first);
        big.push_back(vecPair[i].first);
        small.push_back(vecPair[i].second);
    }

    print<std::vector<int> >(result, "vecResult:");
    print<std::vector<int> >(big, "vecBig:");
    print<std::vector<int> >(small, "vecSmall:");

    for (int k = 1; k < (int)jacob.size(); k++)
    {
        int limit = std::min(jacob[k], (int)small.size());
        
        int i = limit;
        while (i > jacob[k-1]) 
        {
            i--; //décalage entre indices du vector Jacob et du vector result => on adapte i ici.
            std::vector<int>::iterator max_bound = std::find(result.begin(), result.end(), big[i]);
            std::vector<int>::iterator pos = std::upper_bound(result.begin(), max_bound, small[i]);
            result.insert(pos, small[i]);
        }
    }
    print<std::vector<int> >(result, ".\nvecResult before straggler:");
    if (straggler != -1) {
        std::vector<int>::iterator pos = std::upper_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }

    print<std::vector<int> >(result, "vecResult after:");

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

