/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:59:52 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/09 20:54:44 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>

template<typename T>
typename T::const_iterator	*easyfind(T const& container, int value)
{
	typename T::const_iterator it;
	typename T::const_iterator ite = container.end();

	for (it = container.begin(); it != ite; ++it)
	{
		if (*it == value)
			return (it);
	}
	return (NULL);
}
// En supposant que T est un conteneur d'entiers, cette fonction doit trouver
// la première occurrence du deuxième paramètre dans le premier paramètre.
// Si aucune occurrence n'est trouvée,
// vous pouvez soit générer une exception, soit renvoyer une valeur d'erreur
// de votre choix. Si vous avez besoin d'inspiration,
// analysez le comportement des conteneurs standard.

// Bien sûr, mettez en œuvre et soumettez vos propres tests.
// Vous n'avez pas besoin de gérer les conteneurs associatifs.

/*
A first easy exercise is the way to start off on the right foot.
Write a function template easyfind that accepts a type T. It takes two parameters.
The first one has type T and the second one is an integer.
Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.
If no occurrence is found, you can either throw an exception or return an error value
of your choice. If you need some inspiration, analyze how standard containers behave.
Of course, implement and turn in your own tests to ensure everything works as ex-
pected.
You don’t have to handle associative containers.
*/

#endif
