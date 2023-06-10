/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:08:09 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/10 11:35:58 by zharzi           ###   ########.fr       */
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

	{
		std::list<int>::const_iterator l_ite = lst.end();
		std::list<int>::const_iterator l_it = easyfind(lst, 36);
		if (l_it != l_ite)
			std::cout << "OK : " << *l_it << std::endl;
		else
			std::cout << "KO : Value not found in list" << std::endl;
		l_it = easyfind(lst, 100);
		if (l_it != l_ite)
			std::cout << "KO : " << *l_it << std::endl;
		else
			std::cout << "OK : Value not found in list" << std::endl;
	}

	{
		std::vector<int>::const_iterator v_it = easyfind(vec, 76);
		std::vector<int>::const_iterator v_ite = vec.end();
		if (v_it != v_ite)
			std::cout << "OK : " << *v_it << std::endl;
		else
			std::cout << "KO : Value not found in vector" << std::endl;
		v_it = easyfind(vec, 100);
		if (v_it != v_ite)
			std::cout << "KO : " << *v_it << std::endl;
		else
			std::cout << "OK : Value not found in vector" << std::endl;
	}

	{
		std::deque<int>::const_iterator d_it = easyfind(deq, 64);
		std::deque<int>::const_iterator d_ite = deq.end();
		if (d_it != d_ite)
			std::cout << "OK : " << *d_it << std::endl;
		else
			std::cout << "KO : Value not found in double-ended queue" << std::endl;
		d_it = easyfind(deq, 100);
		if (d_it != d_ite)
			std::cout << "KO : " << *d_it << std::endl;
		else
			std::cout << "OK : Value not found in double-ended queue" << std::endl;
	}

	return 0;
}
