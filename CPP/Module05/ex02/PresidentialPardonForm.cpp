/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/13 19:04:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//=-= Coplian form and special constructor =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential Pardon Form", 25, 5)
{
	this->target = "[unknown]";
	// std::cout << "--PresidentialPardonForm default constructor--" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
: AForm("Presidential Pardon Form", 25, 5)
{
	this->target = target;
	// std::cout << "--PresidentialPardonForm param constructor--" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& source)
: AForm(source.getName(), source.getSignatureGrade(), source.getExecutionGrade())
{
	// std::cout << "--PresidentialPardonForm copy--" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& source)
{
	(void)source;
	// std::cout << "--PresidentialPardonForm assignation--" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "--PresidentialPardonForm destructor--" << std::endl;
}

//=-= Accessors  functions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::string const	PresidentialPardonForm::getTarget() const
{
	return (target);
}

//=-= Methods  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
}

//=-= Exception -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

const char*	PresidentialPardonForm::UnsignedForm::what() const throw()
{
	return ("This form is not signed. Impossible to execute it.");
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
