/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:42:42 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/16 00:59:21 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _operation("")
{
	_result = 0;
}

RPN::RPN(std::string const& operation) : _operation(operation)
{
	_result = 0;
}

RPN::RPN(RPN const& source) : _operation(source._operation)
{
	_result = source._result;
}

RPN& RPN::operator=(RPN const& source)
{
	(void)source;
	return (*this);
}

RPN::~RPN()
{
}

static bool	checkSpaces(std::string const& operation)
{
	for (unsigned long int i = 0; i < operation.size(); i++)
	{
		if (i % 2 == 0 && operation[i] == ' ')
			return (0);
		if (i % 2 == 1 && operation[i] != ' ')
			return (0);
	}
	return (1);
}

static bool	checkElements(std::string const& operation)
{
	for (unsigned long int i = 0; i < operation.size(); i++)
	{
		if (i == 0 && std::strchr("0123456789", operation[i]) == NULL)
			return (0);
		if (std::strchr("0123456789+-/*", operation[i]) == NULL)
			return (0);
	}
	return (1);
}

static std::string	removeSpaces(std::string const& operation)
{
	std::string str;
	for (unsigned long int i = 0; i < operation.size(); i++)
	{
		if (i % 2 == 0)
			str += operation[i];
	}
	return (str);
}

void	RPN::checkNotation(void) const
{
	if (_operation.empty())
		throw (std::invalid_argument("Error : empty argument is invalid"));
	if (!checkSpaces(_operation))
		throw (std::invalid_argument("Error : wrong spacing."));
	if (_operation.size() % 2 == 0)
		throw (std::invalid_argument("Error : check your argument ending"));
	std::string reduced = removeSpaces(_operation);
	if (!checkElements(reduced))
		throw (std::invalid_argument("Error : wrong content."));
}

void	RPN::calculation(void) const
{
}
