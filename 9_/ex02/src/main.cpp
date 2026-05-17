

#include "../include/PmergeMe.hpp"

#define MAX_VAL 20

int main(int ac, char **av) {
    std::cout << OLIVE "DEBUG: PROGRAM STARTED" RESET << std::endl;
    

    try {
        checkArgInt(ac, av);
        clock_t start_time = clock();
        std::cout << start_time << " tics; \n";

        int nb_pair = (ac - 1) / 2;
        std::vector<int> jacob = calc_only_js_needed(nb_pair);

        std::vector<int> vec = initVector(ac, av);
        std::vector<std::pair<int,int> > vecPair = create_pairs(vec);
        
        /*
        std::deque<int> dek = initDeque(ac, av);
        std::sort(dek.begin(), dek.end());
        std::cout << clock() << " tics now; dif: " << (clock() - start_time) << " tics\n";     */ 
    }
    
    catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
		return FAILURE;
	}

	return SUCCESS;
}

/*pipeline :
ac/av parsing arguments
stickege vecteur
print containeur (via template)
init time
starting time
sort
end time
print time
*/