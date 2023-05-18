/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/17 11:30:22 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Intern
{
	public :
		Intern();
		Intern(Intern const& source);
		Intern& operator=(Intern const& source);
		~Intern();

		AForm*	makeForm(std::string const formName, std::string const target);
};

#endif
