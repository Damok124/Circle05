/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:15:31 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/12 15:12:17 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
}

Span::Span(unsigned int const N) : N(N)
{
}

Span::Span(Span const& source) : N(source.N)
{
	this->vec = source.vec;
}

Span& Span::operator=(Span const& source)
{
	if (this != &source)
	{
		this->N = source.N;
		this->vec = source.vec;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int const n)
{
	if (vec.size() < N)
		vec.push_back(n);
	else
		throw (std::out_of_range("Error : container full capacity reached. Cannot add any value."));
}

void	Span::addRandomNumbers(unsigned int n)
{
	if (n > 0)
	{
		srand(clock());
		unsigned int remaining = N - vec.size();
		if (n > remaining)
			n = remaining;
		if (n == 0)
			throw (std::out_of_range("Error : container full capacity reached. Cannot add any value."));
		while (n)
		{
			this->addNumber(rand());
			n--;
		}
	}
}

long int	Span::shortestSpan() const
{
	if (vec.size() < 2)
		throw (std::logic_error("Error : you need at least two value to check the shortest span between."));
	std::vector<int> copy = vec;
	std::sort(copy.begin(), copy.end());
	long int span = std::abs(static_cast<long int>(*(copy.begin() + 1)) - static_cast<long int>(*copy.begin()));
	for (std::vector<int>::const_iterator it = copy.begin(); (it + 1) != copy.end(); it++)
	{
		if (std::abs(static_cast<long int>(*(it + 1)) - static_cast<long int>(*it)) < span)
			span = std::abs(*(it + 1) - *it);
	}
	return (span);
}

long int	Span::longestSpan() const
{
	if (vec.size() < 2)
		throw (std::logic_error("Error : you need at least two value to check the longest span between."));
	std::vector<int> copy = vec;
	std::sort(copy.begin(), copy.end());
	return (static_cast<long int>(*(copy.end() - 1)) - static_cast<long int>(*copy.begin()));
}

std::vector<int>::iterator	Span::getBegin(void)
{
	return vec.begin();
}

std::vector<int>::iterator	Span::getEnd(void)
{
	return vec.end();
}

std::ostream& operator<<(std::ostream& out, Span& source)
{
	std::vector<int>::iterator ite = source.getEnd();
	for (std::vector<int>::iterator it = source.getBegin(); it != ite; it++)
	{
		out << "[" << *it << "]";
		if (it + 1 != ite)
			out << std::endl;
	}
	return (out);
}
