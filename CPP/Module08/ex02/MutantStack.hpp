/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:46:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/10 23:58:19 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

// Pour réparer cette injustice, vous devez rendre le conteneur std::stack itérable.

// Écrivez une classe MutantStack. Elle sera implémentée à partir d'un std::stack.
template<typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack() {}
		MutantStack(MutantStack const& source) {(void)source;}
		MutantStack& operator=(MutantStack const& source) {(void)source; return (*this);}
		~MutantStack() {}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) {return (std::stack<T>::c.begin());}
		iterator end(void) {return (std::stack<T>::c.end());}
};

#endif

// Elle offrira toutes les fonctions membres de celui-ci, ainsi qu'une
// fonctionnalité supplémentaire : des itérateurs.
// Bien sûr, vous écrirez et soumettrez vos propres tests pour vous assurer que tout
// fonctionne comme prévu.




// Si vous l'exécutez une première fois avec votre MutantStack, puis une deuxième fois
// en remplaçant le MutantStack par, par exemple, un std::list, les deux sorties devraient
// être identiques. Bien sûr, lorsque vous testez un autre conteneur, mettez à jour le code
// ci-dessous avec les fonctions membres correspondantes (push() peut devenir push_back(), par exemple).



// Now, time to move on more serious things. Let’s develop something weird.
// The std::stack container is very nice. Unfortunately, it is one of the only STL Con-
// tainers that is NOT iterable. That’s too bad.
// But why would we accept this? Especially if we can take the liberty of butchering the
// original stack to create missing features.
// To repair this injustice, you have to make the std::stack container iterable.
// Write a MutantStack class. It will be implemented in terms of a std::stack.
// It will offer all its member functions, plus an additional feature: iterators.
// Of course, you will write and turn in your own tests to ensure everything works as
// expected.

// If you run it a first time with your MutantStack, and a second time replacing the
// MutantStack with, for example, a std::list, the two outputs should be the same. Of
// course, when testing another container, update the code below with the corresponding
// member functions (push() can become push_back()).
