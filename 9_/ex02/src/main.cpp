

#include "../include/PmergeMe.hpp"

#define MAX_VAL 20

int main(int ac, char **av) {
    std::cout << OLIVE "DEBUG: PROGRAM STARTED" RESET << std::endl;
    

    try {
        clock_t start_time = clock();
//       std::vector<int> lambda = check_arg(ac, av);
//        std::cout << "unsorted sequence: ";
        checkArgInt(ac, av);
        std::cout << start_time << " tics; end: " << clock() << " ics\n";
//        printNumbers(lambda);

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