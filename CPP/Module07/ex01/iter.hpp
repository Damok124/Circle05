/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:48:23 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/06 18:11:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename Ptr, typename Len, typename Fun>
void	iter(Ptr* array, Len length, Fun function)
{
	if (array && length > 0 && function)
	{
		for (Len i = 0; i < length; i++)
			function(array[i]);
	}
}

#endif
