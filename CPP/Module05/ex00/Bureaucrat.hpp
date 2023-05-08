/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/08 08:43:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat {
	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& source);
		Bureaucrat& operator=(Bureaucrat const& source);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void	upGrade();
		void	downGrade();

		class GradeTooHighException : public std::exception {
			public :
				GradeTooHighException();
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				GradeTooLowException();
				virtual const char* what() const throw();
		};

	private :
		std::string const name;
		int grade;//max = 1 min = 150
};

#endif

// 	Un name (nom) constant
// • Un grade (échelon) pouvant aller de 1 (échelon le plus élevé) à 150 (échelon le
// plus bas).
