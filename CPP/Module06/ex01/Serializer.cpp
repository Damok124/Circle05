/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:02:05 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/31 21:20:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const& source)
{
	(void)source;
}

Serializer& Serializer::operator=(Serializer const& source)
{
	(void)source;
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t ptr2 = reinterpret_cast<uintptr_t>(ptr);
	return (ptr2);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	struct Data* dataptr;
	dataptr = reinterpret_cast<struct Data*>(raw);
	return (dataptr);
}
