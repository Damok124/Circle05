/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/19 09:15:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//=-= Coplian form and special constructor =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Form::Form() : _signatureGrade(1), _executionGrade(1)
{
	_signed = false;
	// std::cout << "--Form constructor--" << std::endl;
}

Form::Form(std::string const name, int signatureGrade, int executionGrade)
: _name(name), _signatureGrade(signatureGrade), _executionGrade(executionGrade)
{
	if (signatureGrade < 1 || executionGrade < 1)
		throw (GradeTooHighException());
	else if (signatureGrade > 150 || executionGrade > 150)
		throw (GradeTooLowException());
	_signed = false;
	// std::cout << "--Form param constructor--" << std::endl;
}

Form::Form(Form const& source) : _name(source.getName()), _signed(false),
_signatureGrade(source.getSignatureGrade()), _executionGrade(source.getExecutionGrade())
{
	// std::cout << "--Form copy--" << std::endl;
}

Form& Form::operator=(Form const& source)
{
	(void)source;
	// std::cout << "--Form assignation--" << std::endl;
	return (*this);
}

Form::~Form()
{
	// std::cout << "--Form destructor--" << std::endl;
}

//=-= Accessors  functions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::string const	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_signed);
}

int	Form::getSignatureGrade() const
{
	return (_signatureGrade);
}

int	Form::getExecutionGrade() const
{
	return (_executionGrade);
}

//=-= Methods  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void	Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (getIsSigned() == false)
	{
		if (bureaucrat.getGrade() <= getSignatureGrade())
			_signed = true;
		else
			throw GradeTooLowException();
	}
}

//=-= Exceptions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Error : Grade definition too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Error : Grade definition too low");
}

//=-= Stream =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::ostream& operator<<(std::ostream& out, Form const& inst)
{
	out << "Form " << inst.getName() << " :"
	<< "\n\t- Signed\t\t: " << std::boolalpha << inst.getIsSigned()
	<< "\n\t- Signature grade\t: " << inst.getSignatureGrade()
	<< "\n\t- Execution grade\t: " << inst.getExecutionGrade() << std::endl;
	return (out);
}
