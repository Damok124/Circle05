/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:36:30 by zharzi            #+#    #+#             */
/*   Updated: 2023/08/15 19:03:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Server.hpp"

int main(int argc, char** argv)
{
    int port = 0;
    str password;
    
    try
    {
        if (argc == 3 && check_port(argv[1]) && check_password(argv[2]))
        {
            port = get_port(argv[1]);
            password = get_password(argv[2]);
            server(port, password);
        }
        else
            throw (std::invalid_argument("Error : usage ./ircserv [PORT] [PASSWORD]"));
    }
    catch(const std::exception const& e)
    {
        std::cout << e.what() << std::endl;
		return (1);
    }
    return (0);
}

// Fichiers de rendu Makefile, *.{h, hpp}, *.cpp, *.tpp, *.ipp,
// un fichier de configuration optionnel

/*
socket: Crée un nouveau point de communication (socket) pour la programmation réseau.
Syntaxe : int socket(int domain, int type, int protocol);

close: Ferme un socket ou un fichier ouvert.
Syntaxe : int close(int sockfd);

setsockopt: Configure des options pour un socket.
Syntaxe : int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);

getsockname: Récupère l'adresse locale associée à un socket.
Syntaxe : int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

getprotobyname: Récupère les informations sur un protocole par son nom.
Syntaxe : struct protoent *getprotobyname(const char *name);

gethostbyname: Récupère les informations sur un hôte par son nom.
Syntaxe : struct hostent *gethostbyname(const char *name);

getaddrinfo: Récupère les informations d'adresse en fonction de certains critères.
Syntaxe : int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res);

freeaddrinfo: Libère la mémoire allouée par getaddrinfo.
Syntaxe : void freeaddrinfo(struct addrinfo *res);

bind: Lie un socket à une adresse locale.
Syntaxe : int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

connect: Établit une connexion à un socket distant.
Syntaxe : int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

listen: Met en attente un socket pour les connexions entrantes.
Syntaxe : int listen(int sockfd, int backlog);

accept: Accepte une connexion entrante sur un socket.
Syntaxe : int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

htons et htonl: Convertissent des valeurs entre l'ordre d'octets de l'hôte et l'ordre d'octets du réseau.
Syntaxe : uint16_t htons(uint16_t hostshort); (pour htons)
uint32_t htonl(uint32_t hostlong); (pour htonl)

ntohs et ntohl: Convertissent des valeurs entre l'ordre d'octets du réseau et l'ordre d'octets de l'hôte.
Syntaxe : uint16_t ntohs(uint16_t netshort); (pour ntohs)
uint32_t ntohl(uint32_t netlong); (pour ntohl)

inet_addr: Convertit une adresse IP sous forme de chaîne en une adresse au format binaire.
Syntaxe : in_addr_t inet_addr(const char *cp);

inet_ntoa: Convertit une adresse IP au format binaire en une chaîne de caractères.
Syntaxe : char *inet_ntoa(struct in_addr in);

send et recv: Envoient et reçoivent des données sur un socket.
Syntaxe : ssize_t send(int sockfd, const void *buf, size_t len, int flags); (pour send)
ssize_t recv(int sockfd, void *buf, size_t len, int flags); (pour recv)

signal et sigaction: Gèrent les signaux du système.
Syntaxe : void (*signal(int signum, void (*handler)(int)))(int); (pour signal)
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact); (pour sigaction)

lseek: Déplace le curseur de lecture/écriture dans un fichier.
Syntaxe : off_t lseek(int fd, off_t offset, int whence);

fstat: Récupère les informations sur un fichier.
Syntaxe : int fstat(int fd, struct stat *buf);

fcntl: Effectue diverses opérations sur un descripteur de fichier.
Syntaxe : int fcntl(int fd, int cmd, ...);

poll: Permet de surveiller plusieurs descripteurs de fichiers ou sockets pour des événements spécifiques.
Syntaxe : int poll(struct pollfd *fds, nfds_t nfds, int timeout);
fds: Tableau de structures pollfd spécifiant les descripteurs à surveiller.
nfds: Nombre total de descripteurs à surveiller.
timeout: Temps maximal à attendre pour un événement en millisecondes.

select: Surveille un ensemble de descripteurs de fichiers ou sockets pour des événements spécifiques.
Syntaxe : int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
nfds: Le plus grand descripteur dans les ensembles plus 1.
readfds, writefds, exceptfds: Ensembles de descripteurs à surveiller pour la lecture, l'écriture et les exceptions.
timeout: Durée maximale à attendre pour un événement.

Ces fonctions (poll et select) permettent de surveiller plusieurs descripteurs de fichiers ou sockets et de détecter
quand ils sont prêts pour la lecture, l'écriture ou lorsqu'une exception survient.
Cela facilite la gestion asynchrone de multiples entrées/sorties dans les applications.
*/