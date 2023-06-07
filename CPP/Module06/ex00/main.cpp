/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:04:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/05 20:31:11 by zharzi           ###   ########.fr       */
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
		std::cout << ScalarConverter::getDatas() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	return (0);
}
