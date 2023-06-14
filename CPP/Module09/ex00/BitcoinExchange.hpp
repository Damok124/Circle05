/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:42:25 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/14 10:35:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstdlib>
# include <iostream>
# include <fstream>
# include <sys/stat.h>
# include <map>

class BitcoinExchange
{
	private :
		std::string	_inputName;
		std::string	_databaseName;

		std::map<std::string, float>	_map;

		BitcoinExchange();

	public :
		BitcoinExchange(std::string const arg);
		BitcoinExchange(BitcoinExchange const& source);
		BitcoinExchange& operator=(BitcoinExchange const& source);
		~BitcoinExchange();

		void	checkFiles(void) const;
		void	buildMap(void);
		void	displayResults(void) const;
};

#endif
