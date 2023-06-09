/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:08:09 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/09 20:54:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

int main( void )
{
	std::list<int> lst;
	std::vector<int> vec;
	std::deque<int> deq;

	lst.push_back(88);
	lst.push_back(65);
	lst.push_back(36);
	lst.push_back(50);

	vec.push_back(46);
	vec.push_back(99);
	vec.push_back(76);
	vec.push_back(58);

	deq.push_back(62);
	deq.push_back(18);
	deq.push_back(64);
	deq.push_back(97);

	// easyfind(vec, 76);
	// easyfind(deq, 64);
	return 0;
}

/*
Bien sûr, mettez en œuvre et soumettez vos propres tests pour vous assurer que tout fonctionne comme prévu.
Vous n'avez pas besoin de gérer les conteneurs associatifs.
*/
