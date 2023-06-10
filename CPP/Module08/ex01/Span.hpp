/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:14:35 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/10 17:27:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <vector>
# include <cstdlib>
# include <ctime>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	vec;
		Span();

	public:
		Span(unsigned int N);
		Span(Span const& source);
		Span& operator=(Span const& source);
		~Span();

		void	addNumber(int const n);
		void	addManyNumbers(unsigned int n);
		int		shortestSpan() const;
		int		longestSpan() const;
};

#endif
