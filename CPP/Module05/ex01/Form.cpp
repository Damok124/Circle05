/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/11 19:25:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//=-= Coplian form and special constructor =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Form::Form()
{
	_signed = false;
	// std::cout << "--Form constructor--" << std::endl;
}

Form::Form(std::string const name, int signatureGrade, int executionGrade) : _name(name)
{
	if (signatureGrade < 1)
		throw (GradeTooHighException(getName()));
	else if (signatureGrade > 150)
		throw (GradeTooLowException(getName()));
	_signatureGrade = signatureGrade;
	if (executionGrade < 1)
		throw (GradeTooHighException(getName()));
	else if (executionGrade > 150)
		throw (GradeTooLowException(getName()));
	_executionGrade = executionGrade;
	_signed = false;
	// std::cout << "--Form param constructor--" << std::endl;
}

Form::Form(Form const& source) : name(source.getName()), _signatureGrade(source.getSignatureGrade()), _executionGrade(source.getExecutionGrade())
{
	// std::cout << "--Form copy--" << std::endl;
}

Form& Form::operator=(Form const& source)
{
	if (this != &source)
	{
		_signatureGrade = source.getSignatureGrade();
		_executionGrade = source.getExecutionGrade();
		_signed = source.getIsSigned();
	}
	return (*this);
	// std::cout << "--Form assignation--" << std::endl;
}

Form::~Form()
{
	// std::cout << "--Form destructor--" << std::endl;
}

//=-= Accessors  functions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::string Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const
{
	return (_signed);
}

int Form::getSignatureGrade() const
{
	return (_signatureGrade);
}

int Form::getExecutionGrade() const
{
	return (_executionGrade);
}

//=-= Methods  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void	beSigned(Bureaucrat const& bureaucrat);
		//It changes the form status to signed if the bureaucrat’s grade is high enough
		// (higher or egal to the required one). Remember, grade 1 is higher than grade 2.
		// If the grade is too low, throw a Form::GradeTooLowException.

void	signForm();
		// If the form got signed,
		// it will print something like:
		// <bureaucrat> signed <form>
		// Otherwise, it will print something like:
		// <bureaucrat> couldn’t sign <form> because <reason>.

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
	out << "Form :\n\t- Name : " << inst.getName()
	<< "\n\t- Signed : " << inst.getIsSigned()
	<< "\n\t- Signature grade : " << inst.getSignatureGrade()
	<< "\n\t- Execution grade : " << inst.getExecutionGrade();
	return (out);
}
