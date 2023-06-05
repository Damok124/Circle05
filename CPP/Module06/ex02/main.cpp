/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:50:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/01 16:39:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(clock());
	int i = std::rand() % 3;
	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	return (new C());
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);
	if (a != NULL)
		std::cout << "A type detected." << std::endl;
	else if (b != NULL)
		std::cout << "B type detected." << std::endl;
	else if (c != NULL)
		std::cout << "C type detected." << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A type detected." << std::endl;
		return ;
		(void)a;
	}
	catch(...)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "B type detected." << std::endl;
			return ;
			(void)b;
		}
		catch(...)
		{
			C& c = dynamic_cast<C&>(p);
			std::cout << "C type detected." << std::endl;
			return ;
			(void)c;
		}
	}
}

int	main(void)
{
	Base* base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
