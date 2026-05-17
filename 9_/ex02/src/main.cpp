

#include "../include/PmergeMe.hpp"

#define MAX_VAL 20

int main(int ac, char **av) {
    std::cout << OLIVE "DEBUG: PROGRAM STARTED" RESET << std::endl;
    

    try {
        checkArgInt(ac, av);
        int nb_pair = (ac - 1) / 2;
        std::vector<int> jacob = calc_only_js_needed(nb_pair);


        clock_t start_time = clock();
        std::cout << start_time << " ms start \n";
        std::vector<int> vec = initVector(ac, av);
        print<std::vector<int> >(vec, "Vector_ready"); 
        int straggler = -1;
        if (vec.size() % 2 != 0)
            straggler = vec.back();
        if (straggler > 0)
            std::cout << OLIVE "There is a straggler and its value is: " << straggler << RESET " \n";
        std::vector<std::pair<int,int> > vecPair = create_pairs(vec);
        std::vector<int> final = vecFordJohnson(vecPair, jacob, straggler);
        clock_t stop_time = clock();
        std::cout << clock() << " ms stop\ndif: " << (stop_time - start_time) << " ms\n";

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