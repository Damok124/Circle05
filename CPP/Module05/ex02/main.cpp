/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:31:54 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/14 20:57:19 by zharzi           ###   ########.fr       */
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
		ShrubberyCreationForm shrub("Sahara");
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

// void test8()
// {
// 	try
// 	{
// 		std::cout << "test8.1 / 4 - OK" << std::endl;
// 		std::cout << "test8.2 / 4 - OK" << std::endl;
// 		std::cout << "test8.3 / 4 - OK" << std::endl;
// 		std::cout << "test8.4 / 4 - OK" << std::endl;
// 	}
// 	catch (std::exception& e)
// 	{

// 		std::cout << e.what() << std::endl;
// 		std::cout << "test8 : exception catched - OK" << std::endl;
// 	}
// }

// void test9()
// {
// 	try
// 	{
// 		std::cout << "test9.1 / 4 - OK" << std::endl;
// 		std::cout << "test9.2 / 4 - OK" << std::endl;
// 		std::cout << "test9.3 / 4 - OK" << std::endl;
// 		std::cout << "test9.4 / 4 - OK" << std::endl;
// 	}
// 	catch (std::exception& e)
// 	{

// 		std::cout << e.what() << std::endl;
// 		std::cout << "test9 : exception catched - OK" << std::endl;
// 	}
// }

void test8()
{
	try
	{
		Bureaucrat noob("Noob", 150);
		ShrubberyCreationForm shrub("Sahara");
		// RobotomyRequestForm robot("T-800");
		// PresidentialPardonForm president("Monkey D. Luffy");
		noob.executeForm(shrub);
		std::cout << "test8.1 / 4 - OK" << std::endl;
		try
		{
			shrub.beSigned(noob);
			std::cout << "test8.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test8 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			noob.upGrade();
		try
		{
			shrub.beSigned(noob);
			std::cout << "test8.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test8 : exception catched - KO" << std::endl;
		}
		noob.executeForm(shrub);
		for (int i = 0; i < 8; i++)
			noob.upGrade();
		noob.executeForm(shrub);
		std::cout << "test8.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test8 : exception catched - KO" << std::endl;
	}
}

void test9()
{
	try
	{
		Bureaucrat noob("Noob", 150);
		// ShrubberyCreationForm shrub("Sahara");
		RobotomyRequestForm robot("T-800");
		// PresidentialPardonForm president("Monkey D. Luffy");
		noob.executeForm(robot);
		std::cout << "test9.1 / 4 - OK" << std::endl;
		try
		{
			robot.beSigned(noob);
			std::cout << "test9.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test9 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			noob.upGrade();
		try
		{
			robot.beSigned(noob);
			std::cout << "test9.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test9 : exception catched - KO" << std::endl;
		}
		noob.executeForm(robot);
		for (int i = 0; i < 8; i++)
			noob.upGrade();
		noob.executeForm(robot);
		std::cout << "test9.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test9 : exception catched - KO" << std::endl;
	}
}

void test10()
{
	try
	{
		Bureaucrat noob("Noob", 150);
		// ShrubberyCreationForm shrub("Sahara");
		// RobotomyRequestForm robot("T-800");
		PresidentialPardonForm president("Monkey D. Luffy");
		noob.executeForm(president);
		std::cout << "test10.1 / 4 - OK" << std::endl;
		try
		{
			president.beSigned(noob);
			std::cout << "test10.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test10 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			noob.upGrade();
		try
		{
			president.beSigned(noob);
			std::cout << "test10.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test10 : exception catched - KO" << std::endl;
		}
		noob.executeForm(president);
		for (int i = 0; i < 8; i++)
			noob.upGrade();
		noob.executeForm(president);
		std::cout << "test10.4 / 4 - OK" << std::endl;
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
		ShrubberyCreationForm shrub("Sahara");
		// RobotomyRequestForm robot("T-800");
		// PresidentialPardonForm president("Monkey D. Luffy");
		rookie.executeForm(shrub);
		std::cout << "test11.1 / 4 - OK" << std::endl;
		try
		{
			shrub.beSigned(rookie);
			std::cout << "test11.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test11 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			rookie.upGrade();
		try
		{
			shrub.beSigned(rookie);
			std::cout << "test11.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test11 : exception catched - KO" << std::endl;
		}
		rookie.executeForm(shrub);
		for (int i = 0; i < 8; i++)
			rookie.upGrade();
		rookie.executeForm(shrub);
		std::cout << "test11.4 / 4 - OK" << std::endl;
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
		Bureaucrat rookie("Rookie", 23);
		// ShrubberyCreationForm shrub("Sahara");
		RobotomyRequestForm robot("T-800");
		// PresidentialPardonForm president("Monkey D. Luffy");
		rookie.executeForm(robot);
		std::cout << "test12.1 / 4 - OK" << std::endl;
		try
		{
			robot.beSigned(rookie);
			std::cout << "test12.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test12 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			rookie.upGrade();
		try
		{
			robot.beSigned(rookie);
			std::cout << "test12.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test12 : exception catched - KO" << std::endl;
		}
		rookie.executeForm(robot);
		for (int i = 0; i < 8; i++)
			rookie.upGrade();
		rookie.executeForm(robot);
		std::cout << "test12.4 / 4 - OK" << std::endl;
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
		Bureaucrat rookie("Rookie", 23);
		// ShrubberyCreationForm shrub("Sahara");
		// RobotomyRequestForm robot("T-800");
		PresidentialPardonForm president("Monkey D. Luffy");
		rookie.executeForm(president);
		std::cout << "test13.1 / 4 - OK" << std::endl;
		try
		{
			president.beSigned(rookie);
			std::cout << "test13.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test13 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			rookie.upGrade();
		try
		{
			president.beSigned(rookie);
			std::cout << "test13.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test13 : exception catched - KO" << std::endl;
		}
		rookie.executeForm(president);
		for (int i = 0; i < 8; i++)
			rookie.upGrade();
		rookie.executeForm(president);
		std::cout << "test13.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test13 : exception catched - KO" << std::endl;
	}
}

void test14()
{
	try
	{
		Bureaucrat viceBoss("Vice-Boss", 2);
		ShrubberyCreationForm shrub("Sahara");
		// RobotomyRequestForm robot("T-800");
		// PresidentialPardonForm president("Monkey D. Luffy");
		viceBoss.executeForm(shrub);
		std::cout << "test14.1 / 4 - OK" << std::endl;
		try
		{
			shrub.beSigned(viceBoss);
			std::cout << "test14.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test14 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			viceBoss.upGrade();
		try
		{
			shrub.beSigned(viceBoss);
			std::cout << "test14.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test14 : exception catched - KO" << std::endl;
		}
		viceBoss.executeForm(shrub);
		for (int i = 0; i < 8; i++)
			viceBoss.upGrade();
		viceBoss.executeForm(shrub);
		std::cout << "test14.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test14 : exception catched - KO" << std::endl;
	}
}

void test15()
{
	try
	{
		Bureaucrat viceBoss("Vice-Boss", 2);
		// ShrubberyCreationForm shrub("Sahara");
		RobotomyRequestForm robot("T-800");
		// PresidentialPardonForm president("Monkey D. Luffy");
		viceBoss.executeForm(robot);
		std::cout << "test15.1 / 4 - OK" << std::endl;
		try
		{
			robot.beSigned(viceBoss);
			std::cout << "test15.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test15 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			viceBoss.upGrade();
		try
		{
			robot.beSigned(viceBoss);
			std::cout << "test15.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test15 : exception catched - KO" << std::endl;
		}
		viceBoss.executeForm(robot);
		for (int i = 0; i < 8; i++)
			viceBoss.upGrade();
		viceBoss.executeForm(robot);
		std::cout << "test15.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test15 : exception catched - KO" << std::endl;
	}
}

void test16()
{
	try
	{
		Bureaucrat viceBoss("Vice-Boss", 2);
		// ShrubberyCreationForm shrub("Sahara");
		// RobotomyRequestForm robot("T-800");
		PresidentialPardonForm president("Monkey D. Luffy");
		viceBoss.executeForm(president);
		std::cout << "test16.1 / 4 - OK" << std::endl;
		try
		{
			president.beSigned(viceBoss);
			std::cout << "test16.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test16 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			viceBoss.upGrade();
		try
		{
			president.beSigned(viceBoss);
			std::cout << "test16.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test16 : exception catched - KO" << std::endl;
		}
		viceBoss.executeForm(president);
		for (int i = 0; i < 8; i++)
			viceBoss.upGrade();
		viceBoss.executeForm(president);
		std::cout << "test16.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test16 : exception catched - KO" << std::endl;
	}
}

void test17()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("Sahara");
		// RobotomyRequestForm robot("T-800");
		// PresidentialPardonForm president("Monkey D. Luffy");
		boss.executeForm(shrub);
		std::cout << "test17.1 / 4 - OK" << std::endl;
		try
		{
			shrub.beSigned(boss);
			std::cout << "test17.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test17 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			boss.upGrade();
		try
		{
			shrub.beSigned(boss);
			std::cout << "test17.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test17 : exception catched - KO" << std::endl;
		}
		boss.executeForm(shrub);
		for (int i = 0; i < 8; i++)
			boss.upGrade();
		boss.executeForm(shrub);
		std::cout << "test17.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test17 : exception catched - KO" << std::endl;
	}
}

void test18()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		// ShrubberyCreationForm shrub("Sahara");
		RobotomyRequestForm robot("T-800");
		// PresidentialPardonForm president("Monkey D. Luffy");
		boss.executeForm(robot);
		std::cout << "test18.1 / 4 - OK" << std::endl;
		try
		{
			robot.beSigned(boss);
			std::cout << "test18.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test18 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			boss.upGrade();
		try
		{
			robot.beSigned(boss);
			std::cout << "test18.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test18 : exception catched - KO" << std::endl;
		}
		boss.executeForm(robot);
		for (int i = 0; i < 8; i++)
			boss.upGrade();
		boss.executeForm(robot);
		std::cout << "test18.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test18 : exception catched - KO" << std::endl;
	}
}

void test19()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		// ShrubberyCreationForm shrub("Sahara");
		// RobotomyRequestForm robot("T-800");
		PresidentialPardonForm president("Monkey D. Luffy");
		boss.executeForm(president);
		std::cout << "test19.1 / 4 - OK" << std::endl;
		try
		{
			president.beSigned(boss);
			std::cout << "test19.2 / 4 - KO" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test19 : exception catched - OK" << std::endl;
		}
		for (int i = 0; i < 5; i++)
			boss.upGrade();
		try
		{
			president.beSigned(boss);
			std::cout << "test19.3 / 4 - OK" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "test19 : exception catched - KO" << std::endl;
		}
		boss.executeForm(president);
		for (int i = 0; i < 8; i++)
			boss.upGrade();
		boss.executeForm(president);
		std::cout << "test19.4 / 4 - OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test19 : exception catched - KO" << std::endl;
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
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 14 :\n" << std::endl;
	test14();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 15 :\n" << std::endl;
	test15();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 16 :\n" << std::endl;
	test16();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 17 :\n" << std::endl;
	test17();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 18 :\n" << std::endl;
	test18();
	std::cout << "====================================" << std::endl;
	std::cout << "TEST 19 :\n" << std::endl;
	test19();

}

int	main(void)
{
	// testBureaucrat();
	// std::cout << "====================================" << std::endl;
	testForms();
	return (0);
}
