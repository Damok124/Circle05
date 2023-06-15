/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:42:39 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/16 00:51:50 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
// # include <cstdlib>
# include <cstring>
# include <stack>

class RPN
{
	private:
		std::string		_operation;
		std::stack<int>	_stack;
		long int	_result;

		RPN();
		RPN(RPN const& source);
		RPN& operator=(RPN const& source);

	public :
		RPN(std::string const& operation);
		~RPN();

		void	checkNotation(void) const;
		void	calculation(void) const;
};

#endif
