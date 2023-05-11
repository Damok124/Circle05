/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/11 20:39:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form
{
	private :
							Form();
		std::string const	_name;
		boolean				_signed;
		int			_signatureGrade;
		int			_executionGrade;

	public :
							Form(std::string const name, int const signatureGrade, int const executionGrade);
							Form(Form const& source);
							Form& operator=(Form const& source);
							~Form();

		std::string	const	getName() const;
		bool const			getIsSigned() const;
		int	const			getSignatureGrade() const;
		int	const			getExecutionGrade() const;

		void				beSigned(Bureaucrat const& bureaucrat);
		//It changes the form status to signed if the bureaucrat’s grade is high enough
		// (higher or egal to the required one). Remember, grade 1 is higher than grade 2.
		// If the grade is too low, throw a Form::GradeTooLowException.

		void				signForm();
		// If the form got signed,
		// it will print something like:
		// <bureaucrat> signed <form>
		// Otherwise, it will print something like:
		// <bureaucrat> couldn’t sign <form> because <reason>.

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

std::ostream& operator<<(std::ostream& out, Form const& inst);

#endif
