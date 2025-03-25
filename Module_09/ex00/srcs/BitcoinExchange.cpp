/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:46:31 by algultse          #+#    #+#             */
/*   Updated: 2025/03/24 18:30:51 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	this->_rates = other._rates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this != &rhs)
		this->_rates = rhs._rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw FileOpenException();
	}

	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		throw BadDatabaseFormatException();
	}

	while (std::getline(file, line)) {
		if (line.empty()) {
			continue ;
		}

		std::istringstream	ss(line);
		std::string			date;
		std::string			rateStr;

		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr)) {
			throw BadDatabaseFormatException();
		}
		if (!isValidDate(date)) {
			throw BadDatabaseFormatException();
		}
		for (size_t i = 0; i < rateStr.size(); ++i) {
			if (!isdigit(rateStr[i]) && rateStr[i] != '.' && rateStr[i] != '-') {
				throw BadDatabaseFormatException();
			}
		}
		double rate = static_cast<float>(std::atof(rateStr.c_str()));
		if (rate < 0.0f || rate > 1000000.0f || rate > FLT_MAX) {
			throw BadDatabaseFormatException();
		}
		if (_rates.find(date) != _rates.end()) {
			throw DuplicateDateException();
		}

		_rates[date] = rate;
	}
	if (_rates.empty()) {
		throw EmptyDatabaseException();
	}
}

double	BitcoinExchange::getRateForDate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);

	if (it != _rates.end() && it->first == date) {
		return (it->second);
	}
	if (it == _rates.begin()) {
		return (-1.0f);
	}
	--it;
	return (it->second);
}

bool	isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool	BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	for (size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7)
			continue ;
		if (!isdigit(date[i]))
			return (false);
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2100)
		return (false);
	if (month < 1 || month > 12)
		return (false);

	int maxDay;
	if (month == 2)
		maxDay = isLeapYear(year) ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDay = 30;
	else
		maxDay = 31;

	if (day < 1 || day > maxDay)
		return (false);

	std::time_t now = std::time(NULL);
	std::tm* t = std::localtime(&now);
	int currentYear = t->tm_year + 1900;
	int currentMonth = t->tm_mon + 1;
	int currentDay = t->tm_mday;

	if (year > currentYear ||
		(year == currentYear && month > currentMonth) ||
		(year == currentYear && month == currentMonth && day > currentDay))
		return (false);

	return (true);
}

std::string	BitcoinExchange::removeTrailingZeros(double number) {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << number;
	std::string str = oss.str();

	size_t dot = str.find('.');
	if (dot != std::string::npos) {
		size_t lastNonZero = str.find_last_not_of('0');
		if (lastNonZero != std::string::npos) {
			str.erase(lastNonZero + 1);
			if (str[str.length() - 1] == '.') {
				str.erase(str.length() - 1);
			}
		}
	}
	return (str);
}

const char*	BitcoinExchange::FileOpenException::what() const throw() {
	return ("Error: could not open data file.");
}

const char*	BitcoinExchange::EmptyDatabaseException::what() const throw() {
	return ("Error: database is empty.");
}

const char*	BitcoinExchange::BadDatabaseFormatException::what() const throw() {
	return ("Error: bad format in database.");
}

const char*	BitcoinExchange::DateNotFoundException::what() const throw() {
	return ("Error: no available data for this date.");
}

const char*	BitcoinExchange::DuplicateDateException::what() const throw() {
	return ("Error: duplicate date in database.");
}
