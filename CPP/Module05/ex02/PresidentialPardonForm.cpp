/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/12 20:50:42 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//=-= Coplian form and special constructor =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

PresidentialPardonForm::PresidentialPardonForm() \
: AForm()
{
	_signed = false;
	// std::cout << "--PresidentialPardonForm constructor--" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const name, int signatureGrade, int executionGrade) \
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
	// std::cout << "--PresidentialPardonForm param constructor--" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& source) \
: AForm(source.getName(), source.getSignatureGrade(), source.getExecutionGrade())
{
	// std::cout << "--PresidentialPardonForm copy--" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& source)
{
	if (this != &source)
	{
		_signatureGrade = source.getSignatureGrade();
		_executionGrade = source.getExecutionGrade();
		_signed = source.getIsSigned();
	}
	return (*this);
	// std::cout << "--PresidentialPardonForm assignation--" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "--PresidentialPardonForm destructor--" << std::endl;
}

//=-= Accessors  functions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::string const	PresidentialPardonForm::getName() const
{
	return (_name);
}

bool	PresidentialPardonForm::getIsSigned() const
{
	return (_signed);
}

int	PresidentialPardonForm::getSignatureGrade() const
{
	return (_signatureGrade);
}

int	PresidentialPardonForm::getExecutionGrade() const
{
	return (_executionGrade);
}

//=-= Methods  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void	PresidentialPardonForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (getIsSigned() == false)
	{
		if (bureaucrat.getGrade() <= getSignatureGrade())
			_signed = true;
		else
			throw GradeTooLowException();
	}
}

void	PresidentialPardonForm::signForm(Bureaucrat const& bureaucrat) const
{
	if (getIsSigned() == true)
		std::cout << bureaucrat.getName() << " signed " << getName() << std::endl;
	else
		std::cout << bureaucrat.getName() << " couldn't sign " << getName() \
		<< " because it needs higher bureaucrat grade to be signed." << std::endl;
}

//=-= Exceptions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

const char* PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return ("Error : Grade definition too high");
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return ("Error : Grade definition too low");
}

//=-= Stream =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::ostream& operator<<(std::ostream& out, PresidentialPardonForm const& inst)
{
	out << "Form " << inst.getName() << " :"
	<< "\n\t- Signed\t\t: " << std::boolalpha << inst.getIsSigned()
	<< "\n\t- Signature grade\t: " << inst.getSignatureGrade()
	<< "\n\t- Execution grade\t: " << inst.getExecutionGrade() << std::endl;
	return (out);
}
