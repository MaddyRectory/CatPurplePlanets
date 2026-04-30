#include "../include/RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_operator = other._operator;
	}
	return *this;
}

int	RPN::popOperandAndVerif() {
	std::stringstream	ss;
	int					operand;
	
	ss << _operator.top();
	_operator.pop();
	if (!(ss >> operand))
		throw InvalidOperator();
	ss.clear();

	return operand;
}

void	RPN::makeOperation(std::string &token) {

	int					operand1;
	int					operand2;
	int					result;
	std::stringstream	ss;

/**
 * ! Verification de la stack et de la division par zero
 */
	if (_operator.size() < 2)
		throw InvalidExpression();
	operand1 = popOperandAndVerif();
	if (token == "/" && operand1 == 0)
		throw DivisionByZero();

/**
 * ! Pop element de la stack et verif overflow
 */
	operand2 = popOperandAndVerif();

/**
 * ! Calcul du resultat
 */
	switch(token[0]) {
		case '+':
			result = operand2 + operand1;
			break;
		case '-':
			result = operand2 - operand1;
			break;
		case '*':
			result = operand2 * operand1;
			break;
		case '/':
			result = operand2 / operand1;
			break;
		case '%':
			result = operand2 % operand1;
			break;
		default:
			throw InvalidOperator();
	}

/**
 * ! Push du resultat dans la stack
 */
	std::stringstream res;
	res << result;
	_operator.push(res.str());
}

void RPN::calculator(std::string &op) {
	
	std::string		token;

	size_t			start_pos = 0;
	size_t			end_pos = 0;

	if (op.empty())
		throw EmptyOperation();

	while (start_pos < op.length()) {
		
		end_pos = op.find(" ", start_pos);
		if (end_pos == std::string::npos)
		{
			token = op.substr(start_pos, op.length() - start_pos);
			makeOperation(token);
			break ;
		}
		token = op.substr(start_pos, end_pos - start_pos);

		if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
			_operator.push(token);
		else
			makeOperation(token);
		
		start_pos = end_pos + 1;
	}
	if (_operator.size() != 1)
		throw InvalidExpression();
	std::cout << TEAL << _operator.top() << RESET << std::endl;
}
