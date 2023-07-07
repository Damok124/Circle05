/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:08:09 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/21 16:55:18 by zharzi           ###   ########.fr       */
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
