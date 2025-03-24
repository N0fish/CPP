/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:43:38 by algultse          #+#    #+#             */
/*   Updated: 2025/03/24 18:26:33 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include "Colors.hpp"

class BitcoinExchange {
	private:
		std::map<std::string, double>	_rates;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void		loadDatabase(const std::string& filename);
		bool		isValidDate(const std::string& date) const;
		double		getRateForDate(const std::string& date) const;
		std::string	removeTrailingZeros(double number);

		class FileOpenException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	
		class EmptyDatabaseException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	
		class BadDatabaseFormatException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	
		class DateNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class DuplicateDateException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif