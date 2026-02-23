



/*
#include "../Span.hpp"

#include <exception>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

class Span {
    private :
        Span();
        set storage;
        unsignedint size;

    public :
        Span(unsignedint N) : size(N) {};
        // copy ?
        // operator= ?
        ~Span() { delete storage; };

        void    addNumber(int new_nbr);
        void    addNunber(int * arrray, int size);
        int     shortestSpan();
        int     longestSpan();

        class NoSpanException : public std::exception {
			const char* what() const throw() {
				return ("There is no span to find");
			}
		};
		
		
		class FullSpanException : public std::exception {
			const char* what() const throw() {
				return ("The span is full");
			}
		};



};

*/

#include "Span.hpp"
#include <limits>
#include <set>

Span::Span() {}

Span::Span(unsigned int N): maxSize(N) {}

Span::Span(const Span &other) {
	if (this == &other)
		return ;
	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this == &other)
		return (*this);
	maxSize = other.maxSize;
	storage = other.storage;
	return (*this);
}

Span::~Span() {}

// METHODS

void	Span::addNumber(int number) {
	if (storage.size() >= maxSize)
		throw  FullSpanException();
	storage.insert(number);
}

void	Span::addNumbers(std::set<int>::iterator begin, std::set<int>::iterator end) {
    unsigned int distance = std::distance(begin, end);

    if (container.size() + distance > maxSize)
        throw std::out_of_range("Cannot add more numbers, container would exceed max size");
    container.insert(begin, end);
}

void	Span::printNumbers() {
	std::cout << "Stored values: ";
	for (std::set<int>::iterator it = storage.begin(); it != storage.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;	
}

unsigned int    Span::shortestSpan() {

	unsigned int	shortSpan;

	if (storage.size() < 2)
		throw NoSpanException();
    
	shortSpan = std::numeric_limits<int>::max();
	for (std::set<int>::iterator it = storage.begin(); it != storage.end(); it++)
	{
		std::set<int>::iterator next_it = it;
		next_it++;
		unsigned int span = *next_it - *it;
		if (span < shortSpan)
			shortSpan = span;
	}
	return (shortSpan);
}

unsigned int	Span::longestSpan() {
	if (storage.size() < 2)
		throw NoSpanException();
	return (*storage.rbegin() - *storage.begin());
}