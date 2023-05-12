/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/12 18:27:28 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
	private :
							ShrubberyCreationForm();
		std::string const	_name;
		bool				_signed;
		int					_signatureGrade;
		int					_executionGrade;

	public :
		ShrubberyCreationForm(std::string const name, int signatureGrade, int executionGrade);
		ShrubberyCreationForm(ShrubberyCreationForm const& source);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& source);
		~ShrubberyCreationForm();

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

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm const& inst);

#endif
