/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:17:51 by algultse          #+#    #+#             */
/*   Updated: 2025/03/03 14:06:36 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* -------------------------------------------------------------------------- */
/*                              STATIC FUNCTION                               */
/* -------------------------------------------------------------------------- */

void	ScalarConverter::convert(const std::string &literal) {
	if (isChar(literal)) {
		printChar(literal);
	} else if (isNumber(literal)) {
		printNumber(literal);
	} else if (isException(literal)) {
		printException(literal);
	} else {
		std::cout << "Invalid Type!" << std::endl;
	}
}

/* -------------------------------------------------------------------------- */
/*                             PRIVATE FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return (*this); }

bool ScalarConverter::isChar(const std::string &s) {
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'' && std::isprint(s[1]));
}

bool ScalarConverter::isNumber(const std::string &s) {
	if (s.empty() || isException(s))
		return (false);

	if (s[s.length() - 1] == 'f' && s.length() > 1) {
		std::string withoutF = s.substr(0, s.length() - 1);
		char *end;
		double floatValue = std::strtod(withoutF.c_str(), &end);
		if (*end == '\0') {
			if (floatValue > FLT_MAX || floatValue < -FLT_MAX)
				return false;
			return true;
		}
	}

	// char *end;
	// double value = std::strtod(s.c_str(), &end);
	// if (value > FLT_MAX || value < -FLT_MAX)
	// 	return false;
	// if (*end != '\0') {
	// 	return false;
	// }
	// return true;

	char *end;
	errno = 0;
	double value = std::strtod(s.c_str(), &end);

	if (errno == ERANGE || value == HUGE_VAL || value == -HUGE_VAL) {
		return false;
	}
	if (*end != '\0') {
		return false;
	}
	return true;


}

bool ScalarConverter::isException(const std::string &s) {
	return (s == "nan" || s == "nanf" ||
			s == "+inf" || s == "-inf" ||
			s == "+inff" || s == "-inff");
}

void ScalarConverter::printChar(const std::string &literal) {
	char c = literal[1]; // Используем второй символ в строке (между кавычками)
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printNumber(const std::string &literal) {
	bool isFloat = (literal.back() == 'f');
	std::string number = literal;
	if (isFloat) number = literal.substr(0, literal.size() - 1);

	// if (number.length() > 309) {  // Максимальная длина DBL_MAX ≈ 1.79e308 (309 символов)
	// 	std::cout << "char: impossible" << std::endl;
	// 	std::cout << "int: impossible" << std::endl;
	// 	std::cout << "float: impossible" << std::endl;
	// 	std::cout << "double: impossible" << std::endl;
	// 	return;
	// }

	char	*end;
	errno = 0;
	double	valueDouble = std::strtod(number.c_str(), &end);

	if (errno == ERANGE || valueDouble == HUGE_VAL || valueDouble == -HUGE_VAL || number.length() > 17) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	// if (*end != '\0') {
	// 	std::cout << "Invalid Type!" << std::endl;
	// 	return;
	// }

	if (valueDouble == 0.0 && (literal.find('.') != std::string::npos || isFloat)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: 0.0f" << std::endl;
		std::cout << "double: 0.0" << std::endl;
		return ;
	}

	int valueInt = static_cast<int>(valueDouble);

	std::cout << "char: ";
	if (valueDouble < 0 || valueDouble > 127 || valueInt != valueDouble)
		std::cout << "impossible";
	else if (std::isprint(valueInt))
		std::cout << "'" << static_cast<char>(valueInt) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	std::cout << "int: ";
	if (valueDouble > INT_MAX || valueDouble < INT_MIN || valueInt != valueDouble)
		std::cout << "impossible";
	else
		std::cout << valueInt;
	std::cout << std::endl;

	std::cout << "float: ";
	if (valueDouble > FLT_MAX || valueDouble < -FLT_MAX)
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(valueDouble) << "f";
	std::cout << std::endl;


	std::cout << "double: " << std::fixed << std::setprecision(1) << valueDouble << std::endl;
	// std::cout << "double: ";
	// if (errno == ERANGE || valueDouble == HUGE_VAL || valueDouble == -HUGE_VAL) {
	// 	std::cout << "impossible";
	// } else {
	// 	std::cout << std::fixed << std::setprecision(1) << valueDouble;
	// }
	// std::cout << std::endl;
}

void ScalarConverter::printException(const std::string &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal == "nan" || literal == "nanf")
		std::cout << "float: nanf" << std::endl;
	else if (literal == "+inf" || literal == "+inff")
		std::cout << "float: +inff" << std::endl;
	else if (literal == "-inf" || literal == "-inff")
		std::cout << "float: -inff" << std::endl;

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
	else
		std::cout << "double: " << literal << std::endl;
}
