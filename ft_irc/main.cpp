/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:36:30 by zharzi            #+#    #+#             */
/*   Updated: 2023/08/10 19:01:44 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "Error : usage ./ircserv [PORT] [PASSWORD]" << std::endl;
    }
    return (0);
}

// Fichiers de rendu Makefile, *.{h, hpp}, *.cpp, *.tpp, *.ipp,
// un fichier de configuration optionnel

Arguments port : Le port d’écoute
password : Le mot de passe de connexion
Fonctions ex-
ternes autorisées
Tout ce qui respecte la norme C++ 98.
socket, close, setsockopt, getsockname,
getprotobyname, gethostbyname, getaddrinfo,
freeaddrinfo, bind, connect, listen, accept, htons,
htonl, ntohs, ntohl, inet_addr, inet_ntoa, send,
recv, signal, sigaction, lseek, fstat, fcntl, poll
(ou équivalent)
Libft autorisée n/a
Description Un serveur IRC en C++ 98