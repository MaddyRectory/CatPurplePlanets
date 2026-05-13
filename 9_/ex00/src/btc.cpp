
#include "btc.hpp"

BitcoinEx::BitcoinEx() {
	try {
		readData(DATA_FILE, ",");
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		exit (EXIT_FAILURE);
	}
}

BitcoinEx::~BitcoinEx() {
}

BitcoinEx::BitcoinEx(const BitcoinEx &copy) {
	*this = copy;
}

BitcoinEx	&BitcoinEx::operator=(const BitcoinEx &copy) {
	if (this != &copy) {
		if (!this->_bitcoin.empty())
			this->_bitcoin.clear();
		this->_bitcoin = copy._bitcoin;
		if (!this->_value_bitcoin.empty())
			this->_value_bitcoin.clear();
		this->_value_bitcoin = copy._value_bitcoin;
	}
	return *this;
}

std::map<std::string, double>	BitcoinEx::getBitcoin() const {
	return _bitcoin;
}

std::map<std::string, double>	BitcoinEx::getValueBitcoin() const {
	return _value_bitcoin;
}

// -------------------- UTILS

//trim spaces and tabs (I do nt accept other whitespaces)
std::string	BitcoinEx::trimWhiteSpaces(std::string &line) {
	size_t start = line.find_first_not_of(" \t");
	if (start == std::string::npos)
		return "";
	size_t end = line.find_last_not_of(" \t");
	return line.substr(start, end - start + 1);
}

//
bool	BitcoinEx::lineIsValid(std::string &key, std::string &value, const std::string &line) {
	std::istringstream	iss(value);
	float				floatValue;

	iss >> floatValue;

	if (iss.fail() || !iss.eof())
	{
		return false;
	}
	if (key.empty() || value.empty() || line.empty()
		|| key.length() != 10)
		return false;
	return true;
}

bool	BitcoinEx::dateIsValid(std::string &date){

	int year = std::atoi(date.substr(0,4).c_str());
	int month = std::atoi(date.substr(5,6).c_str());
	int day = std::atoi(date.substr(8,9).c_str());

	std::cout << year << " m:" << month << " d:" << day << "\n";

	if (month < 1 || month > 12)
		return false;
	if (year < 2008 || day < 1 || day > 31)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day <= 30);
	if (month == 2) {
		//std::cout << year << " " << (year % 4) << "\n";
		if (year % 4 != 0)
			return (day <= 28);
		else
			return (day <= 29);
	}
	return true;
}

/**
 * @brief Read the data from the file and store it in a map
 */
void	BitcoinEx::readData(const char *file_name, std::string separator)
{

	std::ifstream file(file_name);
	if (!file.is_open())
		throw CouldNotOpenFile();
	
	std::string line;
	
	// * Pour sauter la première ligne
	std::getline(file, line);
	if (line != "date,exchange_rate" )   
        throw CouldNotOpenFile();

	while (std::getline(file, line))
	{
		std::string key = line.substr(0, line.find(separator));
		std::string value = line.substr(line.find(separator) + 1);

		key = trimWhiteSpaces(key);
		value = trimWhiteSpaces(value);

		if (!lineIsValid(key, value, line)
			|| value.find_first_not_of("0123456789.") != std::string::npos)
			throw CouldNotOpenFile();

		_value_bitcoin.insert(std::pair<std::string, double>(key, std::strtod(value.c_str(), NULL)));
	}
}

/**
 * @brief Get the data from the input file and display the price
 */
void	BitcoinEx::getAndDisplay(char **av)
{
	std::ifstream file(av[1]);
	if (!file.is_open())
		throw CouldNotOpenFile();

	std::string line;

	std::getline(file, line);
	if (line != "date | value" )   
		throw InvalidInputFile();
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		std::string date = line.substr(0, line.find("|"));
		std::string value = line.substr(line.find("|") + 1);

		date = trimWhiteSpaces(date);
		value = trimWhiteSpaces(value);

		if (!dateIsValid(date))
		{
			std::cout << RED << "Error: Bad input ==> "
					  << ORANGE << date
					  << RESET << std::endl;
			continue;
		}
		try {
			displayPrice(value, date);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

/**
 * @brief Display the final price of the bitcoin
 */
void	BitcoinEx::displayPrice(std::string &value, std::string &date) {

		std::map<std::string, double>::iterator it;
		float									final_price;
		float									nb_bitcoin = std::strtod(value.c_str(), NULL);

		if (nb_bitcoin < FLOAT_MIN)
			throw NotPositifNumber();
		if (nb_bitcoin > FLOAT_MAX)
			throw TooLargeNumber();

		if (_value_bitcoin.find(date) != _value_bitcoin.end())
			final_price = nb_bitcoin * _value_bitcoin[date];
		else
		{
			it = _value_bitcoin.lower_bound(date);
			if (it == _value_bitcoin.begin())
				throw LowerDataNotFound();
			it--;
			final_price = nb_bitcoin * it->second;
		}
		std::cout	<< ORANGE << date
					<< PURPLE << " => "
					<< ORANGE << nb_bitcoin
					<< PURPLE << " = "
					<< TEAL << final_price
					<< RESET << std::endl;
}