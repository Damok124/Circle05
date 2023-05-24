/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:09:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/24 10:37:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private :
		ScalarConverter();
		ScalarConverter(ScalarConverter const& source);
		ScalarConverter& operator=(ScalarConverter const& source);

		static std::string const	_input;

	public :
		virtual			~ScalarConverter();

		static void		convert(std::string const literal);

		static bool		isChar(std::string const input);
		static bool		isInt(std::string const input);
		static bool		isFloat(std::string const input);
		static bool		isDouble(std::string const input);

		static char		toChar(std::string const input);
		static int		toInt(std::string const input);
		static float	toFloat(std::string const input);
		static double	toDouble(std::string const input);
};

#endif

// Write a static class ScalarConverter
// that will contain a method "convert" takes as parameter a string representation of a C++ literal in its most common form.

// This literal must belong to one of the following a scalar types:
// • char
// • int
// • float
// • double

// Except for char parameters, only the decimal notation will be used.

// Examples of char literals: ’c’, ’a’, ...

// To make things simple, please note that non displayable characters shouldn’t be used as inputs.

// If a conversion to char is not displayable, prints an informative message.

// Examples of int literals: 0, -42, 42...

// Examples of float literals: 0.0f, -4.2f, 4.2f...

// You have to handle these pseudo literals as well (you know, for science):
// -inff, +inff and nanf.

// Examples of double literals: 0.0, -4.2, 4.2...

// You have to handle these pseudo literals as well (you know, for fun):
// -inf, +inf and nan.
