/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:03:28 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/21 17:01:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <cstring>
# include <ctime>
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

		void	showVector(std::string const& intro) const;
		void	showDeque(std::string const& intro) const;
		void	initVector(void);
		void	initDeque(void);
		void	parsing(void);
		void	showSort(void);
};

#endif
