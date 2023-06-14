/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:42:27 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/14 13:28:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string arg)
: _inputName(arg), _databaseName("data.csv")
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& source)
: _inputName(source._inputName), _databaseName(source._databaseName), _map(source._map)
{
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& source)
{
	if (this == &source)
		return (*this);
	_map = source._map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

static bool isFile(char const *filename)
{
	struct stat info;
	if (stat(filename, &info) != 0)
		return (0);
	if (!S_ISREG(info.st_mode))
		return (0);
	return (1);
}

static bool	isReadable(char const* filename)
{
	std::ifstream file(filename);
	if (!file)
		return (0);
	else
		file.close();
	return (1);
}

static std::string	extractDate(std::string const line)
{
	if (line.size() >= 10 && line[4] == '-' && line[7] == '-'
	&& (line.find_first_not_of("0123456789", 0, 4) == std::string::npos)
	&& (line.find_first_not_of("0123456789", 5, 2) == std::string::npos)
	&& (line.find_first_not_of("0123456789", 8, 2) == std::string::npos))
		return (line.substr(0, 10));
	return ("invalid date");
	// long unsigned int i = 0;
	// while (i < line.size())
	// {
	// 	if (line.find_first_not_of("0123456789", 0, 4) != std::string::npos)
	// 		{
	// 			std::cout << line << " " << line.find_first_not_of("0123456789", 0, 4) << std::endl;
	// 			return ("invalid date");
	// 		}
	// 	if (i >= 5 && i < 7)
	// 		if (line.find_first_not_of("0123456789", 5, 2) != std::string::npos)
	// 			return ("invalid date");
	// 	if (i >= 8 && i < 10)
	// 		if (line.find_first_not_of("0123456789", 8, 2) != std::string::npos)
	// 			return ("invalid date");
	// 	if (i == 4 || i == 7)
	// 		if (line[i] != '-')
	// 			return ("invalid date");
	// 	i++;
	// }
	// if (i != 10 || line[10] != ',')
	// 	return ("invalid date");
	// return (line.substr(0, 10));
}

static float	extractValue(std::string line)
{
	size_t pos = 0;
	if (line.find_first_not_of("0123456789.") != std::string::npos)
		return (-1.0f);
	if (line.find_first_of('.', pos) != std::string::npos && line.find_first_of('.', pos) != std::string::npos)
		return (-1.0f);
	if (line[0] == '.')
		return (-1.0f);
	return (strtof(line.c_str(), NULL));
}

static bool	checkDatabaseFormat(char const* filename)
{
	std::ifstream	file(filename);
	std::string		line;
	int	i = 0;

	try
	{
		std::getline(file, line);
		i++;
		if (line.empty() || line.compare("date,exchange_rate"))
			throw (std::invalid_argument("pop1"));
		while (std::getline(file, line) && line.size() > 11)
		{
			if (extractDate(line) == "invalid date")
				throw (std::invalid_argument("pop2"));
			line = line.substr(11);
			if (extractValue(line) < 0)
				throw (std::invalid_argument("pop3"));
			i++;
		}
		if (i == 1)
			throw (std::invalid_argument("pop4"));
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
		file.close();
		return (0);
	}
	return (1);
}

void	BitcoinExchange::checkFiles(void) const
{
	if (!_inputName[0])
		throw (std::invalid_argument("Error : could not open file."));
	if (!isFile(_inputName.c_str()) || !isFile(_databaseName.c_str()))
		throw (std::invalid_argument("Error : could not open file."));
	if (!isReadable(_inputName.c_str()) || !isReadable(_databaseName.c_str()))
		throw (std::invalid_argument("Error : could not open file."));
	if (!checkDatabaseFormat(_databaseName.c_str()))
		throw (std::invalid_argument("Error : wrong or empty database."));
}

void	BitcoinExchange::buildMap(void)
{

}

void	BitcoinExchange::displayResults(void) const
{

}
//format content check	• Each line in this file must use the following format: "date | value".
//						• A valid date will always be in the following format: Year-Month-Day.
//						• A valid value must be either a float or a positive integer between 0 and 1000.
