/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:49:21 by algultse          #+#    #+#             */
/*   Updated: 2025/03/25 17:08:51 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	isValidValue(const std::string& valueStr, float& value) {
	std::istringstream	ss(valueStr);
	ss >> value;
	return (!(ss.fail() || !ss.eof()));
}

static void	trim(std::string& str) {	
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	str = (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << RED "Usage: ./btc <input_file>" RESET << std::endl;
		return (1);
	}
	std::cout << std::endl;

	BitcoinExchange	btc;
	try {
		btc.loadDatabase("data/data.csv");
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return (1);
	}

	std::ifstream	input(argv[1]);
	if (!input.is_open()) {
		std::cerr << RED BOLD "Error: could not open file." RESET << std::endl;
		return (1);
	}

	std::string	line;
	if (!std::getline(input, line)) {
		return (0);
	}
	trim(line);
	if (line != "date | value") {
		std::cerr << RED "Error: bad header format." RESET << std::endl;
	}

	while (std::getline(input, line)) {
		if (line.empty())
			continue ;

		size_t	sep = line.find('|');
		// if (sep == std::string::npos || (line.find('|', sep + 1) != std::string::npos)) {
		// if (sep == std::string::npos || line[sep + 1] != ' ' || line[sep - 1] != ' ') {
		if (sep == std::string::npos || sep == 0 || sep == line.length() - 1 || line[sep - 1] != ' ' || line[sep + 1] != ' ') {
			std::cerr	<< RED "Error: bad input => " << line
						<< RESET << std::endl;
			continue ;
		}
		if ((sep >= 2 && line[sep - 2] == ' ') || (sep + 2 < line.length() && line[sep + 2] == ' ')) {
			std::cerr	<< RED "Error: bad input => " << line
						<< RESET << std::endl;
			continue ;
		}

		std::string	date = line.substr(0, sep);
		std::string	valueStr = line.substr(sep + 1);
		trim(date);
		trim(valueStr);

		float	value;
		if (!btc.isValidDate(date)) {
			std::cerr << RED "Error: bad input => " << line << RESET << std::endl;
			continue ;
		} else if (!isValidValue(valueStr, value)) {
			std::cerr << RED "Error: not a valid number." RESET << std::endl;
			continue ;
		} else if (value < 0.0f) {
			std::cerr << RED "Error: not a positive number." RESET << std::endl;
			continue ;
		} else if (value > 1000.0f) {
			std::cerr << RED "Error: too large a number." RESET << std::endl;
			continue ;
		}
		if (value == 0.0f && valueStr.find_first_not_of('0') == std::string::npos && valueStr.length() > 64) {
			std::cerr << RED "Error: not a valid number." RESET << std::endl;
			continue ;
		}

		try {
			double rate = btc.getRateForDate(date);
			double result = static_cast<double>(value) * rate;
			std::cout	<< GREEN
						<< date << " => "
						<< btc.removeTrailingZeros(value)
						<< " = "
						<< btc.removeTrailingZeros(result)
						<< RESET << std::endl;
		} catch (const std::exception& e) {
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	input.close();

	std::cout << std::endl;
	return (0);
}
