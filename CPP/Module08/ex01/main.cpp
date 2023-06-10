/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:48:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/10 17:30:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

// int main()
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
		test.addManyNumbers(23000);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test2(void)
{
	std::cout << "Test 2 must fail:" << std::endl;
	Span test = Span(0);
	try
	{
		test.addManyNumbers(23000);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test3(void)
{
	std::cout << "Test 3 must fail:" << std::endl;
	Span test = Span(1);
	try
	{
		test.addManyNumbers(23000);
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test4(void)
{
	std::cout << "Test 4 must fail:" << std::endl;
	Span test = Span(2);
	try
	{
		test.addManyNumbers(1);
		std::cout << test.longestSpan() << std::endl;
		std::cout << test.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
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
}

int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	return (0);
}
