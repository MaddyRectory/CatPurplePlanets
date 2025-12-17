/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:28:49 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/17 16:36:22 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

    uintptr_t Serializer::serialize( struct s_data* ptr) {
        uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
        return raw;
    }
    
    struct s_data* Serializer::deserialize(uintptr_t raw) {
        struct s_data* ptr = reinterpret_cast<struct s_data *>(raw);
        return ptr;
    }

    // uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    // Data* ptr = reinterpret_cast<Data*>(raw);
