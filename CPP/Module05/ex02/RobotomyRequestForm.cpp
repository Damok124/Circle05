/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/12 20:48:20 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//=-= Coplian form and special constructor =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

RobotomyRequestForm::RobotomyRequestForm() \
: AForm()
{
	_signed = false;
	// std::cout << "--RobotomyRequestForm constructor--" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const name, int signatureGrade, int executionGrade) \
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
	// std::cout << "--RobotomyRequestForm param constructor--" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& source) \
: AForm(source.getName(), source.getSignatureGrade(), source.getExecutionGrade())
{
	// std::cout << "--RobotomyRequestForm copy--" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& source)
{
	if (this != &source)
	{
		_signatureGrade = source.getSignatureGrade();
		_executionGrade = source.getExecutionGrade();
		_signed = source.getIsSigned();
	}
	return (*this);
	// std::cout << "--RobotomyRequestForm assignation--" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "--RobotomyRequestForm destructor--" << std::endl;
}

//=-= Accessors  functions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::string const	RobotomyRequestForm::getName() const
{
	return (_name);
}

bool	RobotomyRequestForm::getIsSigned() const
{
	return (_signed);
}

int	RobotomyRequestForm::getSignatureGrade() const
{
	return (_signatureGrade);
}

int	RobotomyRequestForm::getExecutionGrade() const
{
	return (_executionGrade);
}

//=-= Methods  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void	RobotomyRequestForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (getIsSigned() == false)
	{
		if (bureaucrat.getGrade() <= getSignatureGrade())
			_signed = true;
		else
			throw GradeTooLowException();
	}
}

void	RobotomyRequestForm::signForm(Bureaucrat const& bureaucrat) const
{
	if (getIsSigned() == true)
		std::cout << bureaucrat.getName() << " signed " << getName() << std::endl;
	else
		std::cout << bureaucrat.getName() << " couldn't sign " << getName() \
		<< " because it needs higher bureaucrat grade to be signed." << std::endl;
}

//=-= Exceptions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

const char* RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return ("Error : Grade definition too high");
}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return ("Error : Grade definition too low");
}

//=-= Stream =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::ostream& operator<<(std::ostream& out, RobotomyRequestForm const& inst)
{
	out << "Form " << inst.getName() << " :"
	<< "\n\t- Signed\t\t: " << std::boolalpha << inst.getIsSigned()
	<< "\n\t- Signature grade\t: " << inst.getSignatureGrade()
	<< "\n\t- Execution grade\t: " << inst.getExecutionGrade() << std::endl;
	return (out);
}
