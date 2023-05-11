/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:31:54 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/11 16:10:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void	test1()
{
	try
	{
		Bureaucrat one("One", 1);
		std::cout << "test1.1 / 3 succeed" << std::endl;
		Bureaucrat two("Two", 75);
		std::cout << "test1.2 / 3 succeed" << std::endl;
		Bureaucrat three("Three", 150);
		std::cout << "test1.3 / 3 succeed" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test1 : exception catched - KO" << std::endl;
	}
}

void	test2()
{
	try
	{
		Bureaucrat one("One", 0);
		std::cout << "test2.1 / 3 wrong behaviour" << std::endl;
		Bureaucrat two("Two", -1);
		std::cout << "test2.2 / 3 wrong behaviour" << std::endl;
		Bureaucrat three("Three", -2206499);
		std::cout << "test2.3 / 3 wrong behaviour" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test2 : exception catched - OK" << std::endl;
	}
}

void	test3()
{
	try
	{
		Bureaucrat one("One", 1);
		std::cout << "test3.1 / 3 succeed" << std::endl;
		Bureaucrat two("Two", 151);
		std::cout << "test3.2 / 3 wrong behaviour" << std::endl;
		Bureaucrat three("Three", 16899946);
		std::cout << "test3.3 / 3 wrong behaviour" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test3 : exception catched - OK" << std::endl;
	}
}

void	test4()
{
	try
	{
		Bureaucrat one("One", 1);
		std::cout << "test4.1 / 3 succeed" << std::endl;
		Bureaucrat two(one);
		std::cout << "test4.2 / 3 succeed" << std::endl;
		std::cout << two << std::endl;
		std::cout << "test4.3 / 3 succeed" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test4 : exception catched - KO" << std::endl;
	}
}

void	test5()
{
	try
	{
		Bureaucrat one("One", 1);
		std::cout << one << std::endl;
		std::cout << "test5.1 / 4 succeed" << std::endl;
		one.downGrade();
		std::cout << one << std::endl;
		std::cout << "test5.2 / 4 succeed" << std::endl;
		one.upGrade();
		std::cout << one << std::endl;
		std::cout << "test5.3 / 4 succeed" << std::endl;
		one.upGrade();
		std::cout << one << std::endl;
		std::cout << "test5.4 / 4 wrong behaviour" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test5 : exception catched - OK" << std::endl;
	}
}

void	test6()
{
	try
	{
		Bureaucrat one("One", 150);
		std::cout << one << std::endl;
		std::cout << "test6.1 / 4 succeed" << std::endl;
		one.upGrade();
		std::cout << one << std::endl;
		std::cout << "test6.2 / 4 succeed" << std::endl;
		one.downGrade();
		std::cout << one << std::endl;
		std::cout << "test6.3 / 4 succeed" << std::endl;
		one.downGrade();
		std::cout << one << std::endl;
		std::cout << "test6.4 / 4 wrong behaviour" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test6 : exception catched - OK" << std::endl;
	}
}

int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return (0);
}
