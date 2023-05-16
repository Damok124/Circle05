/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/16 21:09:48 by zharzi           ###   ########.fr       */
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
	std::string tab[3] = {"PresidentialPardonForm.hpp", "RobotomyRequestForm.hpp", "ShrubberyCreationForm.hpp"};
	AForm* ptr = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (formName.compare(tab[i]))
	}
	switch (checkFormName(formName))
	{
		case (1) :
			std::cout << "Intern creates " << formName << std::endl;
			ptr = new ShrubberyCreationForm::ShrubberyCreationForm();
			break ;
		case (2):
			std::cout << "Intern creates " << formName << std::endl;
			ptr = new RobotomyRequestForm::RobotomyRequestForm();
			break ;
		case (3) :
			std::cout << "Intern creates " << formName << std::endl;
			ptr = new PresidentialPardonForm::PresidentialPardonForm();
			break ;
		default :
			std::cout << "Intern doesn't know such form" << std::endl;
			break ;
	}
	// (void)formName;
	// (void)target;
	return ptr;
	//Elle affiche quelque chose comme :Intern creates <form>
	// Si le nom du formulaire passé en paramètre n’existe pas,
	// affichez un message d’erreur explicite.
}
