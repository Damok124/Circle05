/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:09:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/24 21:08:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdexcept>

enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
};

struct s_datas
{
	type		type;
	char		c;
	int			i;
	float		f;
	double		d;
}	typedef		t_datas;

class ScalarConverter
{
	private :
		ScalarConverter();
		ScalarConverter(ScalarConverter const& source);
		ScalarConverter& operator=(ScalarConverter const& source);

		static t_datas source;

	public :

		virtual	~ScalarConverter();

		static void	convert(std::string const literal);
		static type	label(std::string const literal);

		static bool	isChar(std::string const input);
		static bool	isInt(std::string const input);
		static bool	isFloat(std::string const input);
		static bool	isDouble(std::string const input);

		static void	fromChar(char const c);
		static void	fromInt(int const i);
		static void	fromFloat(float const f);
		static void	fromDouble(double const d);

		class ConverterException : public std::exception
		{
			private :
				std::string _message;
			public :
						ConverterException(std::string const& message) throw();
				virtual	~ConverterException() throw();

				virtual const char*	what() const throw();
		};

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

// To make things simple, please note that non displayable characters shouldn’t be used as inputs.

// If a conversion to char is not displayable, prints an informative message.



// You have to handle these pseudo literals as well (you know, for science):
// You have to handle these pseudo literals as well (you know, for fun):
// -inff, +inff and nanf.
// -inf, +inf and nan.


// Examples of char literals: ’c’, ’a’, ...
// Examples of int literals: 0, -42, 42...
// Examples of float literals: 0.0f, -4.2f, 4.2f...
// Examples of double literals: 0.0, -4.2, 4.2...

