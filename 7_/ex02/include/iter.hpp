/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:07:10 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/12 17:01:37 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

template < typename T >
void    iter(T * array, int size_array, void function(T & arg) ){
    for (int i = 0; i < size_array; i++) {
        function(array[i]);
    }
}

template < typename T >
void    iter(T * array, int size_array, void function(const T & arg) ){
        for (int i = 0; i < size_array; i++) {
            function(array[i]);
        }
}
