/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/14 14:56:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <stdexcept>
# include <fstream>
# include <ios>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
	private :
		std::string	target;
		ShrubberyCreationForm();

	public :
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const& source);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& source);
		~ShrubberyCreationForm();

		std::string const getTarget() const;

		virtual bool	execute(Bureaucrat const & executor) const;

		class UnsignedForm : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm const& inst);

#endif

// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it.
