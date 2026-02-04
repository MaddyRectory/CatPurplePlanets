/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:07:07 by mairivie          #+#    #+#             */
/*   Updated: 2026/01/12 14:46:48 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Template : Mecanisme en c++ qui permet d'utiliser des types comme parametres
//Avantage : c'est comme un patron "general" qui va s'adapter tout seul
//pas besoin de declarere explicitement une version de la fonction pour chaqun des types
//susceptibles d'etre utilise. Template defini une seule fois.
//Au moment de la compilation, compilateur va "traduire" ce template dans 
//toutes les versions de la fonction dont il a besoin (instanciation des templates)

//ici : declaration de parametre template. pourra ensuite etre utilise dans les fonctions.
template <typename T> //pourrait aussi etre template <class T> car en CPP tous les type sont aussi des classe 
T min(T a, T b){
    return (a < b ? a : b);
}

template <typename T> //nb, param template doit etre redeclare avant chaque fonction/classe template
T max(T a, T b){
    return (a > b ? a : b);
}

template <typename T>
void swap(T & a, T & b) {
    T temp = a;
    a = b;
    b = temp;
}