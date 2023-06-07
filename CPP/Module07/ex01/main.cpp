/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:48:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/06 18:49:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

struct s_pack
{
	int		i;
	char	c;
}typedef t_pack;

std::ostream& operator<<(std::ostream& out, t_pack const& data)
{
	out << "t_pack int " << data.i << "\tchar " << data.c;
	return (out);
}

template<typename T>
void	printVal(T const& val)
{
	static int i;
	std::cout << "[" << i << "] :\t" << val << std::endl;
	i++;
}

int	main(void)
{
	int		len = 10;
	int		tab[len];
	for (int i = 0; i < len; i++)
	{
		if (i < 2)
			tab[i] = 1;
		else
			tab[i] = tab[i - 2] + tab[i - 1];
	}
	char	str[5] = {'h', 'e', 'l', 'l', 'o'};
	t_pack special[3] = {{23, 'd'}, {10, 'm'}, {89, 'y'}};
	iter(str, 5, &printVal<char>);
	std::cout << std::endl;
	iter(tab, len, &printVal<int>);
	std::cout << std::endl;
	iter(special, 3, &printVal<t_pack>);
	return (0);
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
