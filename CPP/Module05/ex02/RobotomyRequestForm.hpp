/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/17 14:44:33 by zharzi           ###   ########.fr       */
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
		std::string	target;
		RobotomyRequestForm();

	public :
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const& source);
		RobotomyRequestForm& operator=(RobotomyRequestForm const& source);
		~RobotomyRequestForm();

		std::string const getTarget() const;

		virtual bool	execute(Bureaucrat const & executor) const;

		class UnsignedForm : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, RobotomyRequestForm const& inst);

#endif
