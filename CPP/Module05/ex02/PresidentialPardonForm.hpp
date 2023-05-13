/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/13 19:02:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
	private :
		std::string	target;
		PresidentialPardonForm();

	public :
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const& source);
		PresidentialPardonForm& operator=(PresidentialPardonForm const& source);
		~PresidentialPardonForm();

		std::string const getTarget() const;

		virtual void	execute(Bureaucrat const & executor) const;

		class UnsignedForm : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, PresidentialPardonForm const& inst);

#endif

// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.
