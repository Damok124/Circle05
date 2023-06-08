/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:58:27 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/08 12:28:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include <cstdlib>

template<typename T>
class Array
{
	private :
		int const	_size;
		T			*_array;

	public :
		Array() : _size(0)
		{
			_array = new T[0];
		}

		Array(int n) : _size(n)
		{
			if (n < 0)
				throw (std::exception());
			_array = new T[n];
			for (int i = 0; i < n; i++)
				_array[i] = 0;
		}

		Array(Array const& source) : _size(source.size())
		{
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

		T& operator[](int i)
		{
			if (i < 0 || i >= _size)
				throw (std::exception());
			return (_array[i]);
		}

		~Array()
		{
			if (this->_array)
				delete[] _array;
		}

		int	size(void) const
		{
			return (_size);
		}

};

#endif
