#include "../include/ScalarConverter.hpp"

void    printPseudoLit(std::string input) {
    
    std::string special_cases[6] = {"nan", "nanf", "+inf", "-inf", "-inff", "+inff"};

    for (int i = 0; i < 6; i++) {
        if (input == special_cases[i]) {
            if (i < 2) {
                std::cout <<"char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
            }
            else {
                std::string inf_double = input.substr(0, 4);
				std::cout << "char: impossible\nint: impossible\nfloat: " << inf_double << "f\ndouble: " << inf_double << std::endl;
            }
        }
    }
    return;
}

void	printChar(char c)
{
	if (isprint(c))
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	printInt(int i, std::string str)
{
	if ((i == -2147483648 && str == "-2147483648")|| (i == 2147483647 && str == "2147483647"))
		std::cout << "int: " << i << std::endl;
	else if (i <= std::numeric_limits<int>::min() || i >= std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	printFloat(float f)
{
	if (f < -FLT_MAX || f > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << std::endl;
}

void	printDouble(double d)
{
	if (d < -DBL_MAX || d > DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}