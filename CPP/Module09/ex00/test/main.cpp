/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:08:09 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/13 20:49:50 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string filename = "test.txt";
	std::ifstream file(filename.c_str());

	if (file) {
		std::string line;
		std::getline(file, line);
		std::cout << line << std::endl;
		file.clear();
		file.seekg(0);
		while (std::getline(file, line)) {
			// Traitez chaque ligne ici
			std::cout << line << std::endl;
		}
		file.close();
	} else {
		std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
	}

	return 0;
}

