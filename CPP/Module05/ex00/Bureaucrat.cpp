/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/08 08:42:41 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//=-= The rule of four =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Bureaucrat::Bureaucrat() : name("NoName"), grade(150)
{
	std::cout << "--Bureaucrat constructor--" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	// Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException
	this->grade = grade;//a gerer avec try catch
}

Bureaucrat::Bureaucrat(Bureaucrat const& source) : name(source.getName()), grade(source.getGrade())
{
	std::cout << "--Bureaucrat copy--" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& source)
{
	std::cout << "--Bureaucrat assignation--" << std::endl;
	if (this != &source)
	{
		this->grade = source.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "--Bureaucrat destructor--" << std::endl;
}

//=-= Accessors  functions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

//=-= Methods  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void	Bureaucrat::upGrade()
{
	// Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException
	try
	{
		grade -= 1;
		if (grade < 1)
			throw (GradeTooHighException());
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{

	}
}

void	Bureaucrat::downGrade()
{
	try
	{

	}
	catch (Bureaucrat::GradeTooLowException& e)
	{

	}
	// Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException
}

//=-= Exceptions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high to upgrade");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low to upgrade");///////////////voir pour pimper message
}

