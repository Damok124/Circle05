/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:42:27 by zharzi            #+#    #+#             */
/*   Updated: 2023/06/15 17:17:58 by zharzi           ###   ########.fr       */
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

static int dateToInt(std::string const& date)
{
	std::string number = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);
	return (atoi(number.c_str()));
}

// static std::string intToDate(int number)
// {
// 	std::stringstream str;
// 	int year = number / 10000;
// 	int month = (number / 100) % 100;
// 	int day = number % 100;
// 	str << year << '-';
// 	if (month < 10)
// 		str << '0' << month << '-';
// 	else
// 		str << month << '-';
// 	if (day < 10)
// 		str << '0' << day;
// 	else
// 		str << day;
// 	return (str.str());
// }

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

static bool isDate(int year, int month, int day)
{
	int daysMax[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year < 1 || month < 1 || day < 1)
		return (0);
	if (year > 9999 || month > 12 || day > 31)
		return (0);
	if (year % 4 == 0)
		daysMax[2] = daysMax[0];
	if (day > daysMax[month])
		return (0);
	return (1);
}

static std::string	extractDate(std::string const& line)
{
	if (line.size() < 10 || line[4] != '-' || line[7] != '-')
		return ("invalid date");
	std::string year = line.substr(0, 4);
	std::string month = line.substr(5, 2);
	std::string day = line.substr(8, 2);
	std::string pure = year + month + day;
	for (long unsigned int i = 0; i < pure.size(); i++)
	{
		if (std::strchr("0123456789", pure[i]) == NULL)
			return ("invalid date");
	}
	if (!isDate(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str())))
		return ("invalid date");
	return (line.substr(0, 10));
}

static float	extractExchangeRate(std::string line)
{
	size_t pos = 0;
	pos = line.find('.', pos);
	if (pos != std::string::npos)
	{
		pos = line.find('.', pos + 1);
		if (pos != std::string::npos)
			return (-1.0f);
	}
	if (line[0] == '.')
		return (-1.0f);
	for (long unsigned int i = 0; i < line.size(); i++)
	{
		if (std::strchr("0123456789.", line[i]) == NULL)
			return (-1.0f);
	}
	return (strtof(line.c_str(), NULL));
}

static bool	checkDatabaseFormat(char const* filename)
{
	std::ifstream	file(filename);
	std::string		line;
	int	i = 0;
	int prev = 0;

	try
	{
		std::getline(file, line);
		i++;
		if (line.empty() || line.compare("date,exchange_rate"))
			throw (std::exception());
		while (std::getline(file, line))
		{
			if (extractDate(line) == "invalid date")
				throw (std::exception());
			if (dateToInt(extractDate(line)) < prev)
				throw (std::exception());
			prev = dateToInt(extractDate(line));
			if (line[10] != ',')
				throw (std::exception());
			line = line.substr(11);
			if (extractExchangeRate(line) < 0)
				throw (std::exception());
			i++;
		}
		if (i == 1)
			throw (std::exception());
	}
	catch(...)
	{
		file.close();
		return (0);
	}
	file.close();
	return (1);
}

static bool	checkInputFormat(char const* filename)
{
	std::ifstream	file(filename);
	std::string		line;

	std::getline(file, line);
	if (line.empty() || line.compare("date | value"))
	{
		file.close();
		return (0);
	}
	file.close();
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
		throw (std::invalid_argument("Error : incorrect database content."));
	if (!checkInputFormat(_inputName.c_str()))
		throw (std::invalid_argument("Error : incorrect input content."));
}

void	BitcoinExchange::buildMap(void)
{
	std::ifstream	file(_databaseName.c_str());
	std::string		line;

	std::getline(file, line);
	while (std::getline(file, line))
		_map.insert(std::map<std::string, float>::value_type(extractDate(line), extractExchangeRate(line.substr(11))));
	file.close();
}

double	BitcoinExchange::useMap(std::string const& line) const
{
	std::map<std::string, float>::const_iterator it = _map.begin();
	std::map<std::string, float>::const_iterator ite = _map.end();
	float value = 0;
	double result = 0;
	ite--;
	int date = dateToInt(line.substr(0, 10));
	int begin = dateToInt(it->first);
	int end = dateToInt(ite->first);
	if (date < begin)
		return (value);
	if (date > end)
		return (static_cast<double>(ite->second) * static_cast<double>(extractExchangeRate(line.substr(13))));
	ite++;
	while (it != ite)
	{
		if (date >= dateToInt(it->first))
			value = it->second;
		if (date < dateToInt(it->first))
			break ;
		it++;
	}
	result = static_cast<double>(value) * static_cast<double>(extractExchangeRate(line.substr(13)));
	return (result);
}

void	BitcoinExchange::displayResults(void) const
{
	std::ifstream	file(_inputName.c_str());
	std::string		line;

	std::getline(file, line);
	int valid = 1;
	while (std::getline(file, line))
	{
		valid = 1;
		try
		{
			if (line.size() < 14 || extractDate(line) == "invalid date")
				throw (std::invalid_argument("Error : bad input => "));
			if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
				throw (std::invalid_argument("Error : bad input => "));
			if (line[13] == '-' && extractExchangeRate(line.substr(14)) > 0)
				throw (std::invalid_argument("Error : not a positive number."));
			if ((line[13] == '-' && extractExchangeRate(line.substr(14)) <= 0)
			|| (line[13] != '-' && extractExchangeRate(line.substr(13)) < 0))
				throw (std::invalid_argument("Error : bad input => "));
			if ((line[13] == '-' && extractExchangeRate(line.substr(14)) > 1000)
			|| (line[13] != '-' && extractExchangeRate(line.substr(13)) > 1000))
				throw (std::invalid_argument("Error : too large number."));
		}
		catch(const std::exception& e)
		{
			valid = 0;
			std::string str = e.what();
			if (str != "Error : bad input => ")
				std::cout << str << std::endl;
			else
				std::cout << str << line << std::endl;
		}
		if (valid)
			std::cout << extractDate(line) << " => " << extractExchangeRate(line.substr(13))
			<< " = " << useMap(line) << std::endl;
	}
	file.close();
}
//format content check	• Each line in this file must use the following format: "date | value".
//						• A valid date will always be in the following format: Year-Month-Day.
//						• A valid value must be either a float or a positive integer between 0 and 1000.
