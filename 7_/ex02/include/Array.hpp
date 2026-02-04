/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:07:19 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/21 14:43:06 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Array_HPP
#define Array_HPP

// ===== INCLUDES =====
#include "colors.hpp"
#include <iostream>
#include <string>
#include <exception>

// ===== CLASS DECLARATION =====

template <typename T>
class Array
{
private:
    T*      _data;
    int     _size;

public:

//CONSTRUCTORS & DESTRUCTORS

    Array() :_data(NULL), _size(0) {}
    
    Array(int size) : _data(NULL), _size(size) {
            if (size > 0)
                _data = new T[size];
    }
    
    Array(const Array &toCopy) : _data(NULL), _size(toCopy._size) { 
        if (_size > 0) {
            _data = new T[_size];
            for (int i = 0; i < _size; i++)
                _data[i] = toCopy._data[i];
        }
    }
    
    ~Array() { delete[] _data; }
    
//OPERATORS
    
    Array &operator=(const Array &toCopy) {
        if (this != &toCopy) {
            delete[] _data;
            _size = toCopy.size;
            if (_size > 0) {
                _data = new T[_size];
                for (int i = 0; i < _size; i++)
                    _data[i] = toCopy._data[i];
            }
            else 
                _data = NULL;
        }    
        return *this;
    }

    T & operator[](int i) {
        if (i >= _size || i < 0)
            throw std::exception();
        return _data[i];
    }

    const T & operator[](int i) const {
        if (i >= _size || i < 0)
            throw std::exception();
        return _data[i];
    }

//GETTERS
    
    int get_size() const {
        return _size;
    }
};

#endif
