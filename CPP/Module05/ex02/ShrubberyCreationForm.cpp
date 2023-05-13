/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/13 19:16:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//=-= Coplian form and special constructor =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery Creation Form", 145, 137)
{
	this->target = "[unknown]";
	// std::cout << "--ShrubberyCreationForm default constructor--" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
: AForm("Shrubbery Creation Form", 145, 137)
{
	this->target = target;
	// std::cout << "--ShrubberyCreationForm param constructor--" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& source)
: AForm(source.getName(), source.getSignatureGrade(), source.getExecutionGrade())
{
	// std::cout << "--ShrubberyCreationForm copy--" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& source)
{
	(void)source;
	// std::cout << "--ShrubberyCreationForm assignation--" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "--ShrubberyCreationForm destructor--" << std::endl;
}

//=-= Accessors  functions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::string const	ShrubberyCreationForm::getTarget() const
{
	return (target);
}

//=-= Methods  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (getIsSigned() == false)
			throw (UnsignedForm());
		if (executor.getGrade() < getExecutionGrade())
			throw (GradeTooLowException());/////////////////////////////////////////////good?

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

//=-= Exception -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

const char*	ShrubberyCreationForm::UnsignedForm::what() const throw()
{
	return ("This form is not signed. Impossible to execute it.");
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
