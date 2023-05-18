/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:31:54 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/17 12:43:32 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
		ShrubberyCreationForm shrub("Matrix");
		RobotomyRequestForm robot("T-800");
		PresidentialPardonForm president("Monkey D. Luffy");
		ShrubberyCreationForm shrub2(shrub);
		RobotomyRequestForm robot2(robot);
		PresidentialPardonForm president2(president);
		std::cout << "==================" << std::endl;
		AForm* a = &robot;
		AForm* b = &president;
		std::cout << "a value : " << *a << std::endl;
		std::cout << "b value : "  << *b << std::endl;
		*a = *b;
		std::cout << "a value : " << *a << std::endl;
		std::cout << "b value : "  << *b << std::endl;
		std::cout << "==================" << std::endl;
		std::cout << "test7.1 / 3 - OK" << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << president << std::endl;
		std::cout << "test7.2 / 3 - OK" << std::endl;
		std::cout << shrub2 << std::endl;
		std::cout << robot2 << std::endl;
		std::cout << president2 << std::endl;
		std::cout << "test7.3 / 3 - OK" << std::endl;
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
		Bureaucrat noob("Noob", 150);
		ShrubberyCreationForm shrub("Sahara");
		noob.executeForm(shrub);
		std::cout << "test8.1 - OK" << std::endl;
		try
		{
			shrub.beSigned(noob);
			std::cout << "test8.2 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test8.2 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			noob.upGrade();
		try
		{
			shrub.beSigned(noob);
			std::cout << "test8.3 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test8.3 : exception catched - KO" << std::endl;
		}
		noob.executeForm(shrub);
		for (int i = 0; i < 8; i++)
			noob.upGrade();
		if (noob.executeForm(shrub))
			std::cout << "test8.4 - OK" << std::endl;
		else
			std::cout << "test8.4 - KO" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test8.1 : exception catched - KO" << std::endl;
	}
}

void test9()
{
	try
	{
		Bureaucrat rookie("Rookie", 150);
		RobotomyRequestForm robot("T-800");
		rookie.executeForm(robot);
		std::cout << "test9.1 - OK" << std::endl;
		try
		{
			robot.beSigned(rookie);
			std::cout << "test9.2 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test9.2 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 78; i++)
			rookie.upGrade();
		try
		{
			robot.beSigned(rookie);
			std::cout << "test9.3 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test9.3 : exception catched - KO" << std::endl;
		}
		rookie.executeForm(robot);
		for (int i = 0; i < 27; i++)
			rookie.upGrade();
		if (rookie.executeForm(robot) && rookie.executeForm(robot) && rookie.executeForm(robot) && rookie.executeForm(robot))
			std::cout << "test9.4 - OK" << std::endl;
		else
			std::cout << "test9.4 - KO" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test9.1 : exception catched - KO" << std::endl;
	}
}

void test10()
{
	try
	{
		Bureaucrat futureBoss("FutureBoss", 150);
		PresidentialPardonForm president("Monkey D. Luffy");
		futureBoss.executeForm(president);
		std::cout << "test10.1 - OK" << std::endl;
		try
		{
			president.beSigned(futureBoss);
			std::cout << "test10.2 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test10.2 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 125; i++)
			futureBoss.upGrade();
		try
		{
			president.beSigned(futureBoss);
			std::cout << "test10.3 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test10.3 : exception catched - KO" << std::endl;
		}
		futureBoss.executeForm(president);
		for (int i = 0; i < 20; i++)
			futureBoss.upGrade();
		if (futureBoss.executeForm(president))
			std::cout << "test10.4 - OK" << std::endl;
		else
			std::cout << "test10.4 - KO" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test10.1 : exception catched - KO" << std::endl;
	}
}

void testForms()
{
	std::cout << "====================================" << std::endl;
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
}

void test11()
{
	try
	{
		Intern one = Intern();
		std::cout << "test11.1 / 3 - OK" << std::endl;
		Intern two(one);
		std::cout << "test11.2 / 3 - OK" << std::endl;
		Intern three;
		three = two;
		std::cout << "test11.3 / 3 - OK" << std::endl;
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
		Intern one;
		AForm* form = one.makeForm("Presidential Pardon Form", "The code reviewer");
		Bureaucrat boss("Boss", 1);
		if (form)
		{
			std::cout << *form << std::endl;
			boss.executeForm(*form);
			delete form;
			std::cout << "test12.1 / 4 - OK" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test12.1 : exception catched - KO" << std::endl;
	}
	try
	{
		Intern one;
		AForm* form = one.makeForm("Presidential Pardon Form", "The code reviewer");
		Bureaucrat boss("Boss", 1);
		if (form)
		{
			form->beSigned(boss);
			std::cout << *form << std::endl;
			boss.executeForm(*form);
			delete form;
		}
		std::cout << "test12.2 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test12.2 : exception catched - KO" << std::endl;
	}
	try
	{
		Intern one;
		AForm* form = one.makeForm("Robotomy Request Form", "The code reviewer");
		Bureaucrat boss("Boss", 1);
		if (form)
		{
			form->beSigned(boss);
			std::cout << *form << std::endl;
			boss.executeForm(*form);
			delete form;
		}
		std::cout << "test12.3 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test12.3 : exception catched - KO" << std::endl;
	}
	try
	{
		Intern one;
		AForm* form = one.makeForm("Shrubbery Creation Form", "home");
		Bureaucrat boss("Boss", 1);
		if (form)
		{
			form->beSigned(boss);
			std::cout << *form << std::endl;
			boss.executeForm(*form);
			delete form;
		}
		std::cout << "test12.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test12.4 : exception catched - KO" << std::endl;
	}
}

void test13()
{
	try
	{
		Intern one;
		AForm* form = one.makeForm("Shrubbery", "Failure");
		Bureaucrat boss("Boss", 1);
		if (form)
		{
			form->beSigned(boss);
			std::cout << *form << std::endl;
			boss.executeForm(*form);
			delete form;
		}
		std::cout << "test12.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test12.4 : exception catched - KO" << std::endl;
	}
}

void testIntern()
{
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
	testBureaucrat();
	std::cout << "====================================" << std::endl;
	testForms();
	std::cout << "====================================" << std::endl;
	testIntern();
	return (0);
}
