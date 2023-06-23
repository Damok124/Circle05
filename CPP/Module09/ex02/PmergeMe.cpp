/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:03:17 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/23 14:49:13 by zharzi           ###   ########.fr       */
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
		*this = PmergeMe(source);
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

static bool	checkArgs(char** args)
{
	std::string arg;
	long int	test = 0;
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
		test = strtol(args[i]);
	}
	return (1);
}

void	PmergeMe::initVector(void)
{
	for (int i = 0; _args[i]; i++)
		_vec.push_back(atoi(_args[i]));
}

void	PmergeMe::initDeque(void)
{
	for (int i = 0; _args[i]; i++)
		_deq.push_back(atoi(_args[i]));
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
	initVector();
	if (!checkDuplicates(_vec))
		throw (std::invalid_argument("Error : duplicates found in arguments"));
	initDeque();
}

static std::vector<int>	mergeInsertVector(std::vector<int> const& source)
{
	if (source.size() == 1)
		return (source);
	std::vector<int> left;
	std::vector<int> right;
	if (source.size() > 10)
	{
		for (unsigned long int i = 0; i < source.size(); i++)
		{
			if (i < source.size() / 2)
				left.push_back(source[i]);
			else
				right.push_back(source[i]);
		}
		left = mergeInsertVector(left);
		right = mergeInsertVector(right);
	}
	else
	{
		std::copy(source.begin(), source.begin() + 1, std::back_inserter(left));
		std::copy(source.begin() + 1, source.end(), std::back_inserter(right));
	}
	std::vector<int>::iterator it_l;
	std::vector<int>::iterator ite_l;
	while (right.size())
	{
		it_l = left.begin();
		ite_l = left.end();
		for (it_l = left.begin(); it_l != ite_l; it_l++)
			if (*it_l > *(right.begin()))
				break ;
		left.insert(it_l, *(right.begin()));
		right.erase(right.begin());
	}
	return (left);
}

static std::deque<int> mergeInsertDeque(std::deque<int> const& source)
{
	if (source.size() == 1)
		return (source);
	std::deque<int> left;
	std::deque<int> right;
	if (source.size() > 5)
	{
		for (unsigned long int i = 0; i < source.size(); i++)
		{
			if (i < source.size() / 2)
				left.push_back(source[i]);
			else
				right.push_back(source[i]);
		}
		left = mergeInsertDeque(left);
		right = mergeInsertDeque(right);
	}
	else
	{
		std::copy(source.begin(), source.begin() + 1, std::back_inserter(left));
		std::copy(source.begin() + 1, source.end(), std::back_inserter(right));
	}
	std::deque<int>::iterator it_l;
	std::deque<int>::iterator ite_l;
	while (right.size())
	{
		it_l = left.begin();
		ite_l = left.end();
		for (it_l = left.begin(); it_l != ite_l; it_l++)
			if (*it_l > *(right.begin()))
				break ;
		left.insert(it_l, *(right.begin()));
		right.pop_front();
	}
	return (left);
}

void	PmergeMe::showSort(void)
{
	clock_t startVec = clock();
	showVector("Before :    ");
	_vec = mergeInsertVector(_vec);
	showVector("After :     ");
	clock_t endVec = clock();
	std::cout << "Time to process a range of " << _vec.size()
	<< " elements with std::vector : " << static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC << " sec" << std::endl;//choisir ut correcte
	clock_t startDeq = clock();
	// showDeque("Before :    ");
	_deq = mergeInsertDeque(_deq);
	// showDeque("After :     ");
	clock_t endDeq = clock();
	std::cout << "Time to process a range of " << _deq.size()
	<< " elements with std::deque  : " << static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC << " sec" << std::endl;//choisir ut correcte
}

void	PmergeMe::showVector(std::string const& intro) const
{
	std::vector<int>::const_iterator ite = _vec.end();
	std::cout << intro;
	for (std::vector<int>::const_iterator it = _vec.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::showDeque(std::string const& intro) const
{
	std::deque<int>::const_iterator ite = _deq.end();
	std::cout << intro;
	for (std::deque<int>::const_iterator it = _deq.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
