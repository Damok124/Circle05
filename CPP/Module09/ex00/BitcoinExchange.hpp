/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:42:25 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/13 12:45:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>

class BitcoinExchange
{
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const& source);
	BitcoinExchange& operator=(BitcoinExchange const& source);
	~BitcoinExchange();
};

#endif
