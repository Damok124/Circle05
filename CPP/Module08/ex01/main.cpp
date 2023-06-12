/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:48:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/12 17:08:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

// int main()//if you want to make furthermore tests, make them on the second main.
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

//expected output :
// 2
// 14

void	test1(void)
{
	std::cout << "Test 1 must succeed:" << std::endl;
	Span test = Span(20000);
	try
	{
		test.addRandomNumbers(23000);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test2(void)
{
	std::cout << "Test 2 must fail:" << std::endl;
	Span test = Span(0);
	try
	{
		test.addRandomNumbers(23000);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test3(void)
{
	std::cout << "Test 3 must fail:" << std::endl;
	Span test = Span(1);
	try
	{
		test.addRandomNumbers(23000);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test4(void)
{
	std::cout << "Test 4 must fail:" << std::endl;
	Span test = Span(2);
	try
	{
		test.addRandomNumbers(1);
		std::cout << test.longestSpan() << std::endl;
		std::cout << test.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test5(void)
{
	std::cout << "Test 5 must fail:" << std::endl;
	Span test = Span(2);
	try
	{
		test.addNumber(1);
		test.addNumber(2);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
		test.addNumber(3);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test6(void)
{
	std::cout << "Test 6 must succeed:" << std::endl;
	Span test = Span(5);
	try
	{
		std::list<int> mod;
		mod.push_back(INT_MIN);
		test.addNumber(INT_MAX);
		std::cout << test << std::endl;
		std::list<int>::iterator ite = mod.end();
		for (std::list<int>::iterator it = mod.begin(); it != ite; it++)
			std::cout << *it << std::endl;
		std::list<int>::iterator it = mod.begin();
		test.pushBackRange(it, ite);
		std::cout << test << std::endl;
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test7(void)
{
	std::cout << "Test 7 must fail:" << std::endl;
	Span test = Span(5);
	try
	{
		std::list<int> mod1;
		std::list<int> mod2;
		mod1.push_back(12);
		mod1.push_back(23);
		mod1.push_back(34);
		mod2.push_back(9);
		mod2.push_back(8);
		mod2.push_back(7);
		test.addRandomNumbers(5);
		std::cout << test << std::endl;
		std::list<int>::iterator ite = mod1.end();
		for (std::list<int>::iterator it = mod1.begin(); it != ite; it++)
			std::cout << *it << std::endl;
		std::list<int>::iterator it = mod2.begin();
		test.pushBackRange(it, ite);
		std::cout << test << std::endl;
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test8(void)
{
	std::cout << "Test 8 must fail:" << std::endl;
	Span test = Span(5);
	try
	{
		std::list<int> mod1;
		std::list<int> mod2;
		mod1.push_back(12);
		mod1.push_back(23);
		mod1.push_back(34);
		mod2.push_back(9);
		mod2.push_back(8);
		mod2.push_back(7);
		test.addRandomNumbers(5);
		std::cout << test << std::endl;
		std::list<int>::iterator ite = mod1.end();
		for (std::list<int>::iterator it = mod1.begin(); it != ite; it++)
			std::cout << *it << std::endl;
		std::list<int>::iterator it = mod2.begin();
		test.pushBackRange(ite, it);
		std::cout << test << std::endl;
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test9(void)
{
	std::cout << "Test 9 must fail:" << std::endl;
	Span test = Span(5);
	try
	{
		std::list<int> mod;
		mod.push_back(INT_MIN);
		mod.push_back(0);
		mod.push_back(INT_MAX);
		test.addRandomNumbers(4);
		std::cout << test << std::endl;
		std::list<int>::iterator ite = mod.end();
		for (std::list<int>::iterator it = mod.begin(); it != ite; it++)
			std::cout << *it << std::endl;
		std::list<int>::iterator it = mod.begin();
		test.pushBackRange(it, ite);
		std::cout << test << std::endl;
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	return (0);
}
