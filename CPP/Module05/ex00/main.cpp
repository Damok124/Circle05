/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:31:54 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/12 15:09:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void	test1()
{
	try
	{
		Bureaucrat one("One", 1);
		std::cout << "test1.1 / 3 - OK" << std::endl;
		Bureaucrat two("Two", 75);
		std::cout << "test1.2 / 3 - OK" << std::endl;
		Bureaucrat three("Three", 150);
		std::cout << "test1.3 / 3 - OK" << std::endl;
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
		std::cout << "test2.1 / 3 - KO" << std::endl;
		Bureaucrat two("Two", -1);
		std::cout << "test2.2 / 3 - KO" << std::endl;
		Bureaucrat three("Three", -2206499);
		std::cout << "test2.3 / 3 - KO" << std::endl;
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
		std::cout << "test3.1 / 3 - OK" << std::endl;
		Bureaucrat two("Two", 151);
		std::cout << "test3.2 / 3 - KO" << std::endl;
		Bureaucrat three("Three", 16899946);
		std::cout << "test3.3 / 3 - KO" << std::endl;
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
		std::cout << "test4.1 / 3 - OK" << std::endl;
		Bureaucrat two(one);
		std::cout << "test4.2 / 3 - OK" << std::endl;
		std::cout << two << std::endl;
		std::cout << "test4.3 / 3 - OK" << std::endl;
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
		std::cout << "test5.1 / 4- OK" << std::endl;
		one.downGrade();
		std::cout << one << std::endl;
		std::cout << "test5.2 / 4- OK" << std::endl;
		one.upGrade();
		std::cout << one << std::endl;
		std::cout << "test5.3 / 4- OK" << std::endl;
		one.upGrade();
		std::cout << one << std::endl;
		std::cout << "test5.4 / 4 - KO" << std::endl;
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
		std::cout << "test6.1 / 4- OK" << std::endl;
		one.upGrade();
		std::cout << one << std::endl;
		std::cout << "test6.2 / 4- OK" << std::endl;
		one.downGrade();
		std::cout << one << std::endl;
		std::cout << "test6.3 / 4- OK" << std::endl;
		one.downGrade();
		std::cout << one << std::endl;
		std::cout << "test6.4 / 4 - KO" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test6 : exception catched - OK" << std::endl;
	}
}

void testBureaucrat()
{
	std::cout << "TEST 1 :\n" << std::endl;
	test1();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 2 :\n" << std::endl;
	test2();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 3 :\n" << std::endl;
	test3();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 4 :\n" << std::endl;
	test4();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 5 :\n" << std::endl;
	test5();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 6 :\n" << std::endl;
	test6();
}

int	main(void)
{
	testBureaucrat();
	return (0);
}
