/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:03:17 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/19 17:15:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **args)
{
	_args = args;
}

PmergeMe::PmergeMe(PmergeMe const& source)
{
	_vec = source._vec;
	_deq = source._deq;
	_args = source._args;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& source)
{
	if (this != &source)
	{
		*this = PmergeMe(source);
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

static bool	checkArgs(char** args)
{
	std::string arg;
	for (int i = 0; args[i]; i++)
	{
		arg = args[i];
		if (arg.size() > 10)
			return (0);
		for (unsigned long int j = 0; j < arg.size(); j++)
		{
			if (strchr("0123456789", arg[j]) == NULL)
				return (0);
		}
	}
	return (1);
}

void	PmergeMe::buildVector(void)
{
	for (int i = 0; _args[i]; i++)
	{
		_vec.push_back(atoi(_args[i]));
	}
}

void	PmergeMe::buildDeque(void)
{
	for (int i = 0; _args[i]; i++)
	{
		_deq.push_back(atoi(_args[i]));
	}
}

static bool	checkDuplicates(std::vector<int> copy)
{
	sort(copy.begin(), copy.end());
	std::vector<int>::const_iterator ite = copy.end();
	for (std::vector<int>::const_iterator it = copy.begin() + 1; it != ite; it++)
	{
		if (*(it - 1) == *it)
			return (0);
	}
	return (1);
}

void	PmergeMe::parsing(void)
{
	if (!checkArgs(_args))
		throw (std::invalid_argument("Error : wrong argument(s)"));
	buildVector();
	if (!checkDuplicates(_vec))
		throw (std::invalid_argument("Error : duplicates found in arguments"));
	buildDeque();
}

void	PmergeMe::sort(void)
{

}
