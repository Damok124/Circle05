/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:50:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/01 00:22:03 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(clock());
	int i = std::rand() % 3;
	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	return (new C());
// Elle instancie de manière aléatoire A, B ou C et renvoie l'instance en tant que pointeur Base.
// Vous êtes libre d'utiliser n'importe quelle méthode pour l'implémentation du choix aléatoire.
}

void identify(Base* p)
{
// Elle affiche le type réel de l'objet pointé par p : "A", "B" ou "C".
	(void)p;
}

void identify(Base& p)
{
	(void)p;
// Elle affiche le type réel de l'objet référencé par p : "A", "B" ou "C".
// L'utilisation d'un pointeur à l'intérieur de cette fonction est interdite.
}


int	main(void)
{
	return (0);
}
