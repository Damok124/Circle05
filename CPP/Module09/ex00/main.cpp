/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:08:09 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/15 21:53:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	try
	{
		if (argc == 1)
			throw (std::invalid_argument("Error : could not open file."));
		if (argc > 2)
			throw (std::invalid_argument("Error : too many arguments."));
		BitcoinExchange core(argv[1]);
		core.checkFiles();
		core.buildMap();
		core.displayResults();
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
