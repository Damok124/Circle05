/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/16 20:00:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//=-= Coplian form and special constructor =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

AForm::AForm()
{
	_signed = false;
	// std::cout << "--AForm constructor--" << std::endl;
}

AForm::AForm(std::string const name, int signatureGrade, int executionGrade) : _name(name)
{
	if (signatureGrade < 1)
		throw (GradeTooHighException());
	if (signatureGrade > 150)
		throw (GradeTooLowException());
	_signatureGrade = signatureGrade;
	if (executionGrade < 1)
		throw (GradeTooHighException());
	if (executionGrade > 150)
		throw (GradeTooLowException());
	_executionGrade = executionGrade;
	_signed = false;
	// std::cout << "--AForm param constructor--" << std::endl;
}

AForm::AForm(AForm const& source) : _name(source.getName()), _signed(false),
_signatureGrade(source.getSignatureGrade()), _executionGrade(source.getExecutionGrade())
{
	// std::cout << "--AForm copy--" << std::endl;
}

AForm& AForm::operator=(AForm const& source)
{
	(void)source;
	// std::cout << "--AForm assignation--" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	// std::cout << "--AForm destructor--" << std::endl;
}

//=-= Accessors  functions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::string const	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_signed);
}

int	AForm::getSignatureGrade() const
{
	return (_signatureGrade);
}

int	AForm::getExecutionGrade() const
{
	return (_executionGrade);
}

//=-= Methods  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void	AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (getIsSigned() == true)
		return ;
	if (bureaucrat.getGrade() > getSignatureGrade())
		throw (Bureaucrat::GradeTooLowException(bureaucrat.getName()));
	_signed = true;
}

void	AForm::signForm(Bureaucrat const& bureaucrat) const
{
	switch (getIsSigned())
	{
		case true :
			std::cout << bureaucrat.getName() << " signed " << getName() << std::endl;
			break ;
		case false :
			std::cout << bureaucrat.getName() << " couldn't sign " << getName()
			<< " because it needs higher bureaucrat grade to be signed." << std::endl;
			break ;
	}
}

//=-= Exceptions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Error : Grade definition too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Error : Grade definition too low");
}

//=-= Stream =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::ostream& operator<<(std::ostream& out, AForm const& inst)
{
	out << "Form " << inst.getName() << " :"
	<< "\n\t- Signed\t\t: " << std::boolalpha << inst.getIsSigned()
	<< "\n\t- Signature grade\t: " << inst.getSignatureGrade()
	<< "\n\t- Execution grade\t: " << inst.getExecutionGrade() << std::endl;
	return (out);
}
