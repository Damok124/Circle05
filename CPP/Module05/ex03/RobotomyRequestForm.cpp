/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/16 20:03:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//=-= Coplian form and special constructor =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy Request Form", 72, 45)
{
	this->target = "[unknown]";
	// std::cout << "--RobotomyRequestForm default constructor--" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
: AForm("Robotomy Request Form", 72, 45)
{
	this->target = target;
	// std::cout << "--RobotomyRequestForm param constructor--" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& source)
: AForm(source.getName(), source.getSignatureGrade(), source.getExecutionGrade())
{
	// std::cout << "--RobotomyRequestForm copy--" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& source)
{
	(void)source;
	// std::cout << "--RobotomyRequestForm assignation--" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "--RobotomyRequestForm destructor--" << std::endl;
}

//=-= Accessors  functions =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

std::string const	RobotomyRequestForm::getTarget() const
{
	return (target);
}


//=-= Functions  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

static void	robotomy(std::string const target)
{
	static int attemptNb;
	std::cout << "* BzzZZRRRRRRRrrrwiiiiiii *" << std::endl;
	switch (attemptNb % 2)
	{
		case 0 :
			std::cout << target << " has been robotomized." << std::endl;
			break ;
		case 1 :
			std::cout << "Robotomy failed." << std::endl;
			break ;
	}
	attemptNb += 1;
}

//=-= Methods  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

bool	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (getIsSigned() == false)
			throw (UnsignedForm());
		if (executor.getGrade() > getExecutionGrade())
			throw (Bureaucrat::GradeTooLowException(executor.getName()));
		robotomy(getTarget());
		return (true);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (false);
}

//=-= Exception -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

const char*	RobotomyRequestForm::UnsignedForm::what() const throw()
{
	return ("This form is not signed. Impossible to execute it.");
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
