/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:42:25 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/15 17:09:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstdlib>
# include <cstring>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <sys/stat.h>
# include <sstream>
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
		double	useMap(std::string const& line) const;
		void	displayResults(void) const;
};

#endif
