/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:27:59 by mairivie          #+#    #+#             */
/*   Updated: 2025/12/16 15:34:23 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Base_HPP
    #define Base_HPP

// ===== INCLUDES =====

// ===== DEFINE CLEAN CODE =====
#define EXIT_SUCCESS 0
#define EXIT_FAIL 1

// ===== CLASS DECLARATION =====
class Base {
    public :
        virtual ~Base(); 
};

// static Base *  generate(void);
// static void    identify(Base* p);
// static void    identify(Base& p);
#endif