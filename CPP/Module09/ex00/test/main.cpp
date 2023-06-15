/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:08:09 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/15 12:53:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

int main()
{
	std::string test = "2111111111111166666666666666666666666666666666666666666666666666666666666666666666666";
	if (strtof(test.c_str(), NULL) > 1000)
		std::cout << strtof(test.c_str(), NULL) * 2.0 << std::endl;
	return 0;
}

