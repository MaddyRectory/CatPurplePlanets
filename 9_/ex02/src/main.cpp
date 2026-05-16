

#include "../include/PmergeMe.hpp"

#define MAX_VAL 20

int main(int ac, char **av) {
    std::cout << OLIVE "DEBUG: PROGRAM STARTED" RESET << std::endl;
    

    try {
        checkArgInt(ac, av);
        clock_t start_time = clock();
        std::cout << start_time << " tics; \n";
        std::vector<int> vec = initContainer(ac, av);
        std::sort(vec.begin(), vec.end());
        std::cout << clock() << " tics now; dif: " << (clock() - start_time) << " tics\n";
        start_time = clock();
        std::cout << start_time << " tics; \n";
        std::list<int> list = initList(ac, av);
        list.sort();
        std::cout << clock() << " tics now; dif: " << (clock() - start_time) << " tics\n";      
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