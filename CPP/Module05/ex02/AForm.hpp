/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/12 18:37:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class AForm
{
	private :
							AForm();
		std::string const	_name;
		bool				_signed;
		int					_signatureGrade;
		int					_executionGrade;

	public :
				AForm(std::string const name, int signatureGrade, int executionGrade);
				AForm(AForm const& source);
				AForm& operator=(AForm const& source);
		virtual	~AForm();

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

std::ostream& operator<<(std::ostream& out, AForm const& inst);

#endif
