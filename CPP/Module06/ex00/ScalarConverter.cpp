/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:10:57 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/30 23:48:18 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

t_datas ScalarConverter::_datas;

void	ScalarConverter::convert(std::string const literal)
{
	ScalarConverter::_datas.type = ScalarConverter::label(literal);
	if (ScalarConverter::_datas.type != NAN && ScalarConverter::_datas.type != PLUS && ScalarConverter::_datas.type != MINUS)
	{
		if (ScalarConverter::_datas.type != OTHER)
			ScalarConverter::init(literal);
		switch (ScalarConverter::_datas.type)
		{
			case CHAR :
				ScalarConverter::fromChar(ScalarConverter::_datas.c);
				break;
			case INT :
				ScalarConverter::fromInt(ScalarConverter::_datas.i);
				break;
			case FLOAT :
				ScalarConverter::fromFloat(ScalarConverter::_datas.f);
				break;
			case DOUBLE :
				ScalarConverter::fromDouble(ScalarConverter::_datas.d);
				break;
			default :
				throw (ConverterException("Argument is not matching any literal type."));
				break;
		}
	}
}

literalType	ScalarConverter::label(std::string const literal)
{
	if (ScalarConverter::isNan(literal))
		return (NAN);
	else if (ScalarConverter::isPlusInf(literal))
		return (PLUS);
	else if (ScalarConverter::isMinusInf(literal))
		return (MINUS);
	else if (ScalarConverter::isDouble(literal))
		return (DOUBLE);
	else if (ScalarConverter::isFloat(literal))
		return (FLOAT);
	else if (ScalarConverter::isInt(literal))
		return (INT);
	else if (ScalarConverter::isChar(literal))
		return (CHAR);
	return (OTHER);
}

void	ScalarConverter::init(std::string const literal)
{
	ScalarConverter::_datas.literal = literal.c_str();
	switch (ScalarConverter::_datas.type)
	{
		case CHAR :
			ScalarConverter::_datas.c = ScalarConverter::_datas.literal[0];
			break;
		case INT :
			ScalarConverter::_datas.i = atoi(ScalarConverter::_datas.literal);
			break;
		case FLOAT :
			ScalarConverter::_datas.f = strtof(ScalarConverter::_datas.literal, NULL);
			break;
		case DOUBLE :
			ScalarConverter::_datas.d = strtod(ScalarConverter::_datas.literal, NULL);
			break;
		default :
			break;
	}
}

t_datas&		ScalarConverter::getDatas()
{
	return (ScalarConverter::_datas);
}

bool	ScalarConverter::isDouble(std::string const input)
{
	if (!input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
		return (1);
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
	if (!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
		return (1);
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

bool	ScalarConverter::isNan(std::string const input)
{
	if (input == "nan" || input == "nanf")
		return (1);
	return (0);
}

bool	ScalarConverter::isPlusInf(std::string const input)
{
	if (input == "+inf" || input == "+inff")
		return (1);
	return (0);
}

bool	ScalarConverter::isMinusInf(std::string const input)
{
	if (input == "-inf" || input == "-inff")
		return (1);
	return (0);
}

void	ScalarConverter::fromChar(char const c)
{
	ScalarConverter::_datas.i = static_cast<int>(c);
	ScalarConverter::_datas.f = static_cast<float>(c);
	ScalarConverter::_datas.d = static_cast<double>(c);
}

void	ScalarConverter::fromInt(int const i)
{
	ScalarConverter::_datas.c = static_cast<char>(i);
	ScalarConverter::_datas.f = static_cast<float>(i);
	ScalarConverter::_datas.d = static_cast<double>(i);
}

void	ScalarConverter::fromFloat(float const f)
{
	ScalarConverter::_datas.c = static_cast<char>(f);
	ScalarConverter::_datas.i = static_cast<int>(f);
	ScalarConverter::_datas.d = static_cast<double>(f);
}

void	ScalarConverter::fromDouble(double const d)
{
	ScalarConverter::_datas.c = static_cast<char>(d);
	ScalarConverter::_datas.i = static_cast<int>(d);
	ScalarConverter::_datas.f = static_cast<float>(d);
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

std::ostream& operator<<(std::ostream& out, t_datas const& source)
{
	if (source.type == NAN || source.type == PLUS || source.type == MINUS)
	{
		out << "char: impossible" << std::endl << "int: impossible" << std::endl;
		if (source.type == NAN)
			out << "float: nanf" << std::endl << "double: nan";
		if (source.type == PLUS)
			out << "float: +inff" << std::endl << "double: +inf";
		if (source.type == MINUS)
			out << "float: -inff" << std::endl << "double: -inf";
	}
	else
	{
		{
			if (source.i > 31 && source.i < 127)
				out << "char: "	<< "\'" << source.c << "\'" << std::endl;
			else if ((source.i >= 0 && source.i <= 31) || source.i == 127)
				out << "char: "	<< "Non displayable" << std::endl;
			else
				out << "char: impossible" << std::endl;
		}
		{
			if (source.d >= static_cast<double>(INT_MIN) && source.d <= static_cast<double>(INT_MAX))
				out << "int: " << source.i << std::endl;
			else
				out << "int: impossible" << std::endl;
		}
		out << "float: " << source.f << "f" << std::endl;
		out << "double: " << source.d;
	}
	return (out);
}
