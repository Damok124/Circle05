/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:04:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/24 21:08:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char** argv)
{
	std::string str;
	try
	{
		if (ac != 2)
			throw (ScalarConverter::ConverterException("wrong number of arguments"));
		str = argv[1];
		if (str.empty())
			throw (ScalarConverter::ConverterException("your argument is an empty string"));
		ScalarConverter::convert(str);
	}
	catch (std::exception& e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	return (0);
}

// Write a program to test that your class works as expected.

// You have to first detect the type of the literal passed as parameter,
// convert it from string to its actual type,
// then convert it explicitly to the three other data types.

// Lastly, display the results as shown below.

// If a conversion does not make any sense or overflows,
// display a message to inform the user that the type conversion is impossible.
// Include any header you need in order to handle numeric limits and special values.

//	shell :
// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan
// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0
