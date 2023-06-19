/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:03:28 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/18 18:05:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <cstring>
# include <vector>
# include <deque>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		char**	_args;
		PmergeMe();

	public:
		PmergeMe(char **args);
		PmergeMe(PmergeMe const& source);
		PmergeMe& operator=(PmergeMe const& source);
		~PmergeMe();

		void	buildVector(void);
		void	buildDeque(void);
		void	parsing(void);
};

#endif
