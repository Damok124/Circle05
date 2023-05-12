/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/12 18:26:13 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
	private :
							RobotomyRequestForm();
		std::string const	_name;
		bool				_signed;
		int					_signatureGrade;
		int					_executionGrade;

	public :
		RobotomyRequestForm(std::string const name, int signatureGrade, int executionGrade);
		RobotomyRequestForm(RobotomyRequestForm const& source);
		RobotomyRequestForm& operator=(RobotomyRequestForm const& source);
		~RobotomyRequestForm();

		std::string	const	getName() const;
		bool				getIsSigned() const;
		int					getSignatureGrade() const;
		int					getExecutionGrade() const;

		void			beSigned(Bureaucrat const& bureaucrat);
		void			signForm(Bureaucrat const& bureaucrat) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, RobotomyRequestForm const& inst);

#endif
