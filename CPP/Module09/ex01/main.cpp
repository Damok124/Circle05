/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:08:09 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/16 00:26:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int argc, char** argv)
{
	try
	{
		if (argc < 2)
			throw (std::invalid_argument("Error : one argument needed."));
		if (argc > 2)
			throw (std::invalid_argument("Error : too many arguments."));
		if (argc == 2)
		{
			RPN data(argv[1]);
			data.checkNotation();
			data.calculation();
		}
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}

// • Your program must take an inverted Polish mathematical expression as an argu-
// ment.
// • The numbers used in this operation and passed as arguments will always be less
// than 10. The calculation itself but also the result do not take into account this rule.
// • Your program must process this expression and output the correct result on the
// standard output.
// • If an error occurs during the execution of the program an error message should be
// displayed on the standard output.
// • Your program must be able to handle operations with these tokens: "+ - / *".

// You must use at least one container in your code to validate this
// exercise.

// You don’t need to manage the brackets or decimal numbers.
//overflow
//division par zero
//stack size doit etre a 1 a la fin
