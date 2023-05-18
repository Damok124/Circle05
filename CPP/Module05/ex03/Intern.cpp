/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/17 12:45:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//=-= The rule of four =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Intern::Intern()
{
	// std::cout << "--Intern constructor--" << std::endl;
}

Intern::Intern(Intern const& source)
{
	(void)source;
	// std::cout << "--Intern copy--" << std::endl;
}

Intern& Intern::operator=(Intern const& source)
{
	(void)source;
	// std::cout << "--Intern assignation--" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	// std::cout << "--Intern destructor--" << std::endl;
}

//=-= Methods  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

AForm* Intern::makeForm(std::string const formName, std::string const target)
{
	std::string tab[3] = {"Shrubbery Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};
	int i = 0;
	while (i < 3 && formName.compare(tab[i]))
		i++;
	switch (i)
	{
		case (0) :
			std::cout << "Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(target));
		case (1):
			std::cout << "Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(target));
		case (2) :
			std::cout << "Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm(target));
		default :
			std::cout << "Intern doesn't know such form named " << formName << std::endl;
	}
	return NULL;
}
