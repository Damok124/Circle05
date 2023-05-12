/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:31:54 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/12 18:23:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

void test7()
{
	try
	{
		std::cout << "test7.1 / 4 - OK" << std::endl;
		std::cout << "test7.2 / 4 - OK" << std::endl;
		std::cout << "test7.3 / 4 - OK" << std::endl;
		std::cout << "test7.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{

		std::cout << e.what() << std::endl;
		std::cout << "test7 : exception catched - KO" << std::endl;
	}
}

void test8()
{
	try
	{
		std::cout << "test8.1 / 4 - OK" << std::endl;
		std::cout << "test8.2 / 4 - OK" << std::endl;
		std::cout << "test8.3 / 4 - OK" << std::endl;
		std::cout << "test8.4 / 4 - KO" << std::endl;
	}
	catch (std::exception& e)
	{

		std::cout << e.what() << std::endl;
		std::cout << "test8 : exception catched - OK" << std::endl;
	}
}

void test9()
{
	try
	{
		std::cout << "test9.1 / 4 - OK" << std::endl;
		std::cout << "test9.2 / 4 - KO" << std::endl;
		std::cout << "test9.3 / 4 - OK" << std::endl;
		std::cout << "test9.4 / 4 - KO" << std::endl;
	}
	catch (std::exception& e)
	{

		std::cout << e.what() << std::endl;
		std::cout << "test9 : exception catched - OK" << std::endl;
	}
}

void test10()
{
	try
	{
		Bureaucrat noob("Noob", 150);
		try
		{
			std::cout << "test10.1 / 3 - KO" << std::endl;
			std::cout << "test10.2 / 3 - KO" << std::endl;
			std::cout << "test10.3 / 3 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test10 : exception catched - OK" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test10 : exception catched - KO" << std::endl;
	}
}

void test11()
{
	try
	{
		Bureaucrat rookie("Rookie", 23);
		try
		{
			std::cout << "test11.1 / 3 - OK" << std::endl;
			std::cout << "test11.2 / 3 - OK" << std::endl;
			std::cout << "test11.3 / 3 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test11 : exception catched - OK" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test11 : exception catched - KO" << std::endl;
	}
}

void test12()
{
	try
	{
		Bureaucrat viceBoss("Vice-Boss", 2);
		try
		{
			std::cout << "test12.1 / 3 - OK" << std::endl;
			std::cout << "test12.2 / 3 - OK" << std::endl;
			std::cout << "test12.3 / 3 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test12 : exception catched - KO" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test12 : exception catched - KO" << std::endl;
	}
}

void test13()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		try
		{
			std::cout << "test13.1 / 3 - OK" << std::endl;
			std::cout << "test13.2 / 3 - OK" << std::endl;
			std::cout << "test13.3 / 3 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test13 : exception catched - KO" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test13 : exception catched - KO" << std::endl;
	}
}

void testForms()
{
	std::cout << "TEST 7 :\n" << std::endl;
	test7();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 8 :\n" << std::endl;
	test8();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 9 :\n" << std::endl;
	test9();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 10 :\n" << std::endl;
	test10();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 11 :\n" << std::endl;
	test11();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 12 :\n" << std::endl;
	test12();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 13 :\n" << std::endl;
	test13();
}

int	main(void)
{
	// testBureaucrat();
	// std::cout << "====================================" << std::endl;
	testForms();
	return (0);
}
