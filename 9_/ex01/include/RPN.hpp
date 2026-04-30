#ifndef RPN_HPP
	#define RPN_HPP

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define ORANGE "\033[38;5;208m"
#define RED "\033[38;5;196m"
#define TEAL "\033[38;5;49m"
#define PURPLE "\033[38;5;129m"
#define OLIVE "\033[38;5;58m"
#define RESET "\033[0m"

#include <stack>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <typeinfo>
#include <cfloat>

class RPN {
	private :
		std::stack<std::string>	_operator;
		
		void	makeOperation(std::string &token);
		int		popOperandAndVerif();


	public :
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		void	calculator(std::string &op);

};

	class EmptyOperation : public std::exception {
	public :
		virtual const char *what() const throw() {
			return (RED "Error : Empty operation\033[0m");
		}
};

	class InvalidExpression : public std::exception {
	public :
		virtual const char *what() const throw() {
			return (RED "Error : Invalid Expression\033[0m");
		}
};

	class DivisionByZero : public std::exception {
	public :
		virtual const char *what() const throw() {
			return (RED "Error : Division by zero\033[0m");
		}
};
	class ArgNotANumber : public std::exception {
	public :
		virtual const char *what() const throw() {
			return (RED "Error : Argument is not a number\033[0m");
		}
};

	class InvalidOperator : public std::exception {
	public :
		virtual const char *what() const throw() {
			return (RED "Error : Invalid operator\033[0m");
		}
};

#endif