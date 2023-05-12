/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/12 18:35:53 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//=-= Coplian form and special constructor =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

ShrubberyCreationForm::ShrubberyCreationForm() \
: AForm()
{
	_signed = false;
	// std::cout << "--ShrubberyCreationForm constructor--" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const name, int signatureGrade, int executionGrade) \
: AForm(name, signatureGrade, executionGrade)
{
	if (signatureGrade < 1)
		throw (GradeTooHighException());
	else if (signatureGrade > 150)
		throw (GradeTooLowException());
	_signatureGrade = signatureGrade;
	if (executionGrade < 1)
		throw (GradeTooHighException());
	else if (executionGrade > 150)
		throw (GradeTooLowException());
	_executionGrade = executionGrade;
	_signed = false;
	// std::cout << "--ShrubberyCreationForm param constructor--" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& source) \
: AForm(source.getName(), source.getSignatureGrade(), source.getExecutionGrade())
{
	_signed = false;
	// std::cout << "--ShrubberyCreationForm copy--" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& source)
{
	if (this != &source)
	{
		_signatureGrade = source.getSignatureGrade();
		_executionGrade = source.getExecutionGrade();
		_signed = source.getIsSigned();
	}
	return (*this);
	// std::cout << "--ShrubberyCreationForm assignation--" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "--ShrubberyCreationForm destructor--" << std::endl;
}

//=-= Accessors  functions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::string const	ShrubberyCreationForm::getName() const
{
	return (_name);
}

bool	ShrubberyCreationForm::getIsSigned() const
{
	return (_signed);
}

int	ShrubberyCreationForm::getSignatureGrade() const
{
	return (_signatureGrade);
}

int	ShrubberyCreationForm::getExecutionGrade() const
{
	return (_executionGrade);
}

//=-= Methods  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void	ShrubberyCreationForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (getIsSigned() == false)
	{
		if (bureaucrat.getGrade() <= getSignatureGrade())
			_signed = true;
		else
			throw GradeTooLowException();
	}
}

void	ShrubberyCreationForm::signForm(Bureaucrat const& bureaucrat) const
{
	if (getIsSigned() == true)
		std::cout << bureaucrat.getName() << " signed " << getName() << std::endl;
	else
		std::cout << bureaucrat.getName() << " couldn't sign " << getName() \
		<< " because it needs higher bureaucrat grade to be signed." << std::endl;
}

//=-= Exceptions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return ("Error : Grade definition too high");
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return ("Error : Grade definition too low");
}

//=-= Stream =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm const& inst)
{
	out << "Form " << inst.getName() << " :"
	<< "\n\t- Signed\t\t: " << std::boolalpha << inst.getIsSigned()
	<< "\n\t- Signature grade\t: " << inst.getSignatureGrade()
	<< "\n\t- Execution grade\t: " << inst.getExecutionGrade() << std::endl;
	return (out);
}
