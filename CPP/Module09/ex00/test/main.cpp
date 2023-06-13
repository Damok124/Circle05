/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:08:09 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/13 14:32:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "mon_fichier.txt";
    std::ifstream file(filename.c_str()); // Ouvre le fichier en lecture

    if (file) {
        // Le fichier est ouvert avec succès
        // Vous pouvez effectuer des opérations de lecture sur le fichier ici
        std::cout << "Le fichier est ouvert avec succès." << std::endl;
        file.close(); // Ferme le fichier une fois que vous avez fini de l'utiliser
    } else {
        // Erreur lors de l'ouverture du fichier
        std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
    }

    return 0;
}

////////			TEST

/*
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "mon_fichier.txt";
    std::ifstream file(filename.c_str());

    if (file) {
        std::string line;
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
*/
