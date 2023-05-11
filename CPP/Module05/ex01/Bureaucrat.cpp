/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/11 16:12:14 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//=-= The rule of four =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Bureaucrat::Bureaucrat()
{
	// std::cout << "--Bureaucrat constructor--" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw (GradeTooHighException(getName()));
	else if (grade > 150)
		throw (GradeTooLowException(getName()));
	this->grade = grade;
	// std::cout << "--Bureaucrat param constructor--" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& source) : name(source.getName()), grade(source.getGrade())
{
	// std::cout << "--Bureaucrat copy--" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& source)
{
	if (this != &source)
	{
		this->grade = source.getGrade();
	}
	return (*this);
	// std::cout << "--Bureaucrat assignation--" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "--Bureaucrat destructor--" << std::endl;
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
	if (grade == 1)
		throw (GradeTooHighException(this->getName()));
	grade -= 1;
}

void	Bureaucrat::downGrade()
{
	if (grade == 150)
		throw (GradeTooLowException(this->getName()));
	grade += 1;
}

//=-= Exceptions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (message.c_str());
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const& name) throw()
{
	// std::cout << "GradeTooHighException constructor" << std::endl;
	message = name + "'s grade is too high to upgrade";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const& name) throw()
{
	// std::cout << "GradeTooLowException constructor" << std::endl;
	message = name + "'s grade is too low to downgrade";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	// std::cout << "GradeTooHighException destructor" << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	// std::cout << "GradeTooLowException destructor" << std::endl;
}

//=-= Stream =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::ostream& operator<<(std::ostream& out, Bureaucrat const& inst)
{
	out << inst.getName() << ", bureaucrat grade " << inst.getGrade();
	return (out);
}
