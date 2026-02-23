
#pragma once

#include <exception>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include "colors.hpp"

class Span {
    private :
        std::set<int>   _storage;
        unsigned int    _maxSize;

        Span();

    public :
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

// METHODS

        void    addNumber(int new_nbr);
        void	addNumbers(std::set<int>::iterator begin, std::set<int>::iterator end);

        void    printNumbers();

        unsigned int     shortestSpan();
        unsigned int     longestSpan();

// EXCEPTIONS

        class NoSpanException : public std::exception {
			const char* what() const throw() {
				return ("Not enough elements to find a span");
			}
		};
		
		
		class FullStorageException : public std::exception {
			const char* what() const throw() {
				return ("Cannot add more numbers, container would exceed max size");
			}
		};

};