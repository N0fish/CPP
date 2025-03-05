/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:14:09 by algultse          #+#    #+#             */
/*   Updated: 2025/03/03 11:20:30 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include "Colors.hpp"

class ScalarConverter {
	public:
		static void	convert(const std::string &literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();

		ScalarConverter&	operator=(const ScalarConverter&);

		static bool	isChar(const std::string &s);
		static bool	isNumber(const std::string &s);
		static bool	isException(const std::string &s);

		static void	printChar(const std::string &literal);
		static void	printNumber(const std::string &literal);
		static void	printException(const std::string &literal);

		static void	printImpossible();
		static int	countDecimalPlaces(double number);
};

#endif