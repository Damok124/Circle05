/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:50:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/31 21:24:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	struct Data data = {19, 74, "ALM"};
	std::cout << "Initial check :" << std::endl;
	std::cout << "Data i : " << data.i << std::endl;
	std::cout << "Data c : " << data.c << std::endl;
	std::cout << "Data s : " << data.s << std::endl;
	uintptr_t step = Serializer::serialize(&data);
	struct Data* ptr = Serializer::deserialize(step);
	std::cout << "Final check :" << std::endl;
	std::cout << "Ptr i : " << ptr->i << std::endl;
	std::cout << "Ptr c : " << ptr->c << std::endl;
	std::cout << "Ptr s : " << ptr->s << std::endl << std::endl;
	std::cout << "Adress check :" << std::endl;
	std::cout << "Data address :" << &data << std::endl;
	std::cout << "Ptr  address :" << ptr << std::endl;
	return (0);
}
