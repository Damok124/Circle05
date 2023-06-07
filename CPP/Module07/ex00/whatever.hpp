/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:39:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/06 11:06:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T>
T min(T const& a, T const& b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
T max(T const& a, T const& b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
