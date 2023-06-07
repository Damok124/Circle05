/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:58:27 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/07 19:25:07 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
	private :
		unsigned int	_size;
		T				*_array;

	public :
		Array()
		{
			_array = new T[0];
			_size = 0;
		}

		Array(unsigned int n)
		{
			_array = new T[n];
			for (int i = 0; i < n; i++)
				_array[i] = 0;
			_size = n;
		}

		Array(Array const& source)
		{
			_size = source.size();
			_array = new T[_size];
			for (int i = 0; i < _size; i++)
				this->_array[i] = source._array[i];
		}

		Array& operator=(Array const& source)
		{
			if (*this != source)
			{
				delete[] _array;
				return (Array(source));
			}
			return (*this);
		}

		~Array()
		{
			delete[] _array;
		}

		unsigned int	size(void) const
		{
			return (_size);
		}

// • You MUST use the operator new[] to allocate memory. Preventive allocation (al-
// locating memory in advance) is forbidden. Your program must never access non-
// allocated memory.

// • Elements can be accessed through the subscript operator: [ ].

// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.

};

#endif

/*
Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
• Construction with no parameter: Creates an empty array.
• Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a.
• Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
• You MUST use the operator new[] to allocate memory. Preventive allocation (al-
locating memory in advance) is forbidden. Your program must never access non-
allocated memory.
• Elements can be accessed through the subscript operator: [ ].
• When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
• A member function size() that returns the number of elements in the array. This
member function takes no parameter and musn’t modify the current instance.
As usual, ensure everything works as expected and turn in a main.cpp file that con-
tains your tests.
*/
