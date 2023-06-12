/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:14:35 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/12 15:10:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <vector>
# include <list>
# include <cstdlib>
# include <ctime>
# include <climits>

# define ARBITRARY_LIMIT 1000000000

class Span
{
	private:
		std::vector<int>	vec;
		unsigned int		N;
		Span();

	public:
		Span(unsigned int N);
		Span(Span const& source);
		Span& operator=(Span const& source);
		~Span();

		void		addNumber(int const n);
		void		addRandomNumbers(unsigned int n);
		long int	shortestSpan() const;
		long int	longestSpan() const;

		std::vector<int>::iterator	getBegin(void);
		std::vector<int>::iterator	getEnd(void);

		template<typename T>
		void	pushBackRange(T it, T ite)
		{
			T tmp = it;
			for (int i = 0; tmp != ite; tmp++, i++)
			{
				if (i > ARBITRARY_LIMIT)
					throw (std::out_of_range("Error : end iterator is too far or probably not on the same container."));
			}
			vec.insert(vec.end(), it, ite);
		}
};

std::ostream& operator<<(std::ostream& out, Span& source);

#endif
