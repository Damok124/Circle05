/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:10:57 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/24 21:08:10 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string const literal)
{
	ScalarConverter::source.type = ScalarConverter::label(literal);
	switch (ScalarConverter::source.type)
	{
		case CHAR :
			ScalarConverter::fromChar(ScalarConverter::source.c);
			break;
		case INT :
			ScalarConverter::fromInt(ScalarConverter::source.i);
			break;
		case FLOAT :
			ScalarConverter::fromFloat(ScalarConverter::source.f);
			break;
		case DOUBLE :
			ScalarConverter::fromDouble(ScalarConverter::source.d);
			break;
		default :
			throw (ConverterException("Argument is not matching any literal type."));
			break;
	}
}

type	ScalarConverter::label(std::string const literal)
{
	if (ScalarConverter::isChar(literal))
		return (CHAR);
	else if (ScalarConverter::isInt(literal))
		return (INT);
	else if (ScalarConverter::isFloat(literal))
		return (FLOAT);
	else if (ScalarConverter::isDouble(literal))
		return (DOUBLE);
	return (OTHER);
}

bool	ScalarConverter::isChar(std::string const input)
{
	if (input.length() == 1)
		return (1);
	return (0);
}

bool	ScalarConverter::isInt(std::string const input)
{
	return (0);
}

bool	ScalarConverter::isFloat(std::string const input)
{
	return (0);
}

bool	ScalarConverter::isDouble(std::string const input)
{
	return (0);
}

void	ScalarConverter::fromChar(char const c)
{
	ScalarConverter::source.i = c;
	ScalarConverter::source.f = c;
	ScalarConverter::source.d = c;
}

void	ScalarConverter::fromInt(int const i)
{
	ScalarConverter::source.c = i;
	ScalarConverter::source.f = i;
	ScalarConverter::source.d = i;
}

void	ScalarConverter::fromFloat(float const f)
{
	ScalarConverter::source.c = f;
	ScalarConverter::source.i = f;
	ScalarConverter::source.d = f;
}

void	ScalarConverter::fromDouble(double const d)
{
	ScalarConverter::source.c = d;
	ScalarConverter::source.i = d;
	ScalarConverter::source.f = d;
}
