/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/12 17:47:41 by zharzi           ###   ########.fr       */
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
		bool				_signed;
		int					_signatureGrade;
		int					_executionGrade;

	public :
		Form(std::string const name, int signatureGrade, int executionGrade);
		Form(Form const& source);
		Form& operator=(Form const& source);
		~Form();

		std::string	const	getName() const;
		bool				getIsSigned() const;
		int					getSignatureGrade() const;
		int					getExecutionGrade() const;

		void	beSigned(Bureaucrat const& bureaucrat);
		void	signForm(Bureaucrat const& bureaucrat) const;

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