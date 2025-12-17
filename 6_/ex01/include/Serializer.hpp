/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:28:58 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/17 16:35:58 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
#define Serializer_HPP

// ===== DEFINE CLEAN CODE =====
#define EXIT_SUCCESS 0
#define EXIT_FAIL 1

// ===== INCLUDES =====
#include "data.h"
#include <stdint.h>

// ===== CLASS DECLARATION =====
class Serializer
{
private:
    Serializer();
public:
    static uintptr_t serialize( struct s_data* ptr);
    static struct s_data* deserialize(uintptr_t raw);
};
#endif