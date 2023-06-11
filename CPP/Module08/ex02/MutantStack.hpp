/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:46:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/11 09:21:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
	public :
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack() {}
		MutantStack(MutantStack const& source) : std::stack<T>(source) {}
		MutantStack& operator=(MutantStack const& source) {if (this == &source) return (*this); return (MutantStack(source));}
		~MutantStack() {}

		iterator begin(void) {return (std::stack<T>::c.begin());}
		iterator end(void) {return (std::stack<T>::c.end());}
};

#endif
