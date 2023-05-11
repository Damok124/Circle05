/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/11 16:12:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
	private :
							Bureaucrat();

		std::string const	name;
		int					grade;

	public :
					Bureaucrat(std::string name, int grade);
					Bureaucrat(Bureaucrat const& source);
					Bureaucrat& operator=(Bureaucrat const& source);
					~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		void		upGrade();
		void		downGrade();

		class GradeTooHighException : public std::exception
		{
			public :
						GradeTooHighException(std::string const& name) throw();
				virtual	~GradeTooHighException() throw();

				virtual const char*	what() const throw();

			private :
				std::string	message;
		};

		class GradeTooLowException : public std::exception
		{
			public :
						GradeTooLowException(std::string const& name) throw();
				virtual	~GradeTooLowException() throw();

				virtual const char*	what() const throw();

			private :
				std::string	message;
		};
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& inst);

#endif
