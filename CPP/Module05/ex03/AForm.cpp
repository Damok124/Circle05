/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/19 15:54:53 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//=-= Coplian form and special constructor =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

AForm::AForm() : _signatureGrade(1), _executionGrade(1)
{
	_signed = false;
	// std::cout << "--AForm constructor--" << std::endl;
}

AForm::AForm(std::string const name, int signatureGrade, int executionGrade)
: _name(name), _signatureGrade(signatureGrade), _executionGrade(executionGrade)
{
	if (signatureGrade < 1 || executionGrade < 1)
		throw (GradeTooHighException());
	else if (signatureGrade > 150 || executionGrade > 150)
		throw (GradeTooLowException());
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
