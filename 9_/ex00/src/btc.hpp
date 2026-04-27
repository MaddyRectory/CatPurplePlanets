#ifndef BTC_EX_HPP
	#define BTC_EX_HPP

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/*
#define FLOAT_MAX 1000
#define FLOAT_MIN 0
*/

#define DATA_FILE "./src/data.csv"

#define ORANGE "\033[38;5;208m"
#define RED "\033[38;5;196m"
#define TEAL "\033[38;5;49m"
#define PURPLE "\033[38;5;129m"
#define OLIVE "\033[38;5;58m"
#define RESET "\033[0m"

#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <typeinfo>
#include <cfloat>


class BitcoinEx {

	private :
		std::map<std::string, double>	_bitcoin;
		std::map<std::string, double>	_value_bitcoin;

		void		readData(const char *file_name, std::string separator);
		void		displayPrice(std::string &value, std::string &date);
		std::string	trimWhiteSpaces(std::string &line);
		bool		lineIsValid(std::string &key, std::string &value, const std::string &line);
	
	public :
		BitcoinEx();
		~BitcoinEx();
		BitcoinEx(const BitcoinEx &copy);
		BitcoinEx &operator=(const BitcoinEx &copy);

		std::map<std::string, double>	getBitcoin() const;
		std::map<std::string, double>	getValueBitcoin() const;
		void							getAndDisplay(char **av);
};

/**
 * ! EXCEPTIONS
 */

	class NotPositifNumber : public std::exception {
	public :
		virtual const char *what() const throw() {
			return RED "Error: Not a positive number" RESET;
		}
};

	class TooLargeNumber : public std::exception {
	public :
		virtual const char *what() const throw() {
			return RED "Error: Too large number" RESET;
		}
};

	class CouldNotOpenFile : public std::exception {
	public :
		virtual const char *what() const throw() {
			return RED "Error: Invalid Data File" RESET;
		}
};
	class InvalidInputFile : public std::exception {
	public :
		virtual const char *what() const throw() {
			return RED "Error: Invalid Input File" RESET;
		}
};

	class LowerDataNotFound : public std::exception {
	public :
		virtual const char *what() const throw() {
			return RED "Error: No exchange rate for this date" RESET;
		}
};


#endif 