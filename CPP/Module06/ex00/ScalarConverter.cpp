/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:10:57 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/29 22:40:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

t_datas ScalarConverter::source;

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

literalType	ScalarConverter::label(std::string const literal)
{
	if (ScalarConverter::isDouble(literal))
		return (DOUBLE);
	else if (ScalarConverter::isFloat(literal))
		return (FLOAT);
	else if (ScalarConverter::isInt(literal))
		return (INT);
	else if (ScalarConverter::isChar(literal))
		return (CHAR);
	return (OTHER);
}

bool	ScalarConverter::isDouble(std::string const input)
{
	size_t dotPos = input.find_first_of(".");
	if (dotPos != std::string::npos && dotPos != 0 && dotPos != input.length() - 1)
	{
		const char *str = input.c_str();
		char *end;
		strtod(str, &end);
		std::string check = end;
		if (check.length() == 0)
			return (1);
	}
	return (0);
}

bool	ScalarConverter::isFloat(std::string const input)
{
	size_t dotPos = input.find_first_of(".");
	if (dotPos != std::string::npos && dotPos != 0 && dotPos != input.length() - 2)
	{
		const char *str = input.c_str();
		char *end;
		strtof(str, &end);
		std::string check = end;
		if (check.length() == 1 && check == "f")
			return (1);
	}
	return (0);
}

bool	ScalarConverter::isInt(std::string const input)
{
	const char *str = input.c_str();
	char *end;
	long int value = strtol(str, &end, 10);
	std::string check = end;
	if (check.length() == 0 && value >= INT_MIN && value <= INT_MAX)
		return (1);
	return (0);
}

bool	ScalarConverter::isChar(std::string const input)
{
	if (input.length() == 1)
		return (1);
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

ScalarConverter::ConverterException::ConverterException(std::string const& message) throw()
{
	_message = message;
}

ScalarConverter::ConverterException::~ConverterException() throw()
{
}

const char* ScalarConverter::ConverterException::what() const throw()
{
	return (_message.c_str());
}
