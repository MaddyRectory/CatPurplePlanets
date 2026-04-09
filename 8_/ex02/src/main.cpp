/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:23:40 by mairivie          #+#    #+#             */
/*   Updated: 2026/04/09 09:23:41 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"
#include <iostream>

#define PRINT(x) std::cout << x << std::endl

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	PRINT("Top: ");
	PRINT(mstack.top());

	mstack.pop();

	PRINT("Size: ");
	PRINT(mstack.size());

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	PRINT("Iterator: ");
	while (it != ite)
	{
		PRINT(*it);
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}