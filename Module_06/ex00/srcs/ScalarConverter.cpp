/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:17:51 by algultse          #+#    #+#             */
/*   Updated: 2025/03/18 13:37:46 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* -------------------------------------------------------------------------- */
/*                        PUBLIC STATIC FUNCTION                              */
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
/*               PRIVATE COPLIEN'S FUNCTIONS (not instanciable)               */
/* -------------------------------------------------------------------------- */

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return (*this); }

/* -------------------------------------------------------------------------- */
/*                        PRIVATE STATIC FUNCTIONS                            */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                        TYPE CHECKING FUNCTIONS                             */
/* -------------------------------------------------------------------------- */

bool	ScalarConverter::isChar(const std::string &s) {
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'' && std::isprint(s[1]));
}

bool	ScalarConverter::isNumber(const std::string &s) {
	if (s.empty() || isException(s))
		return (false);

	if (s[s.length() - 1] == 'f' && s.length() > 1) {
		std::string	withoutF = s.substr(0, s.length() - 1);
		size_t		dotPos = withoutF.find('.');
	
		if (dotPos != std::string::npos && dotPos == withoutF.length() - 1)
			return (false);
		if (withoutF.find('.') == std::string::npos)
			return (false);
		
		char	*end;
		errno = 0;
		double	floatValue = std::strtod(withoutF.c_str(), &end);
		if (errno == ERANGE || *end != '\0'
			|| floatValue > FLT_MAX || floatValue < -FLT_MAX)
			return (false);
		return (true);
	}

	char	*end;
	errno = 0;
	double	value = std::strtod(s.c_str(), &end);
	if (errno == ERANGE || value == HUGE_VAL || value == -HUGE_VAL) 
		return (true);
	if (*end != '\0')
		return (false);
	return (true);
}

bool	ScalarConverter::isException(const std::string &s) {
	return (s == "nan" || s == "nanf" ||
			s == "+inf" || s == "-inf" ||
			s == "+inff" || s == "-inff" ||
			s == "inf" || s == "inff");
}

/* -------------------------------------------------------------------------- */
/*                              OUTPUT FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	ScalarConverter::printChar(const std::string &literal) {
	char	c = literal[1];
	std::cout	<< "char: '" << static_cast<char>(c) << "'"
				<< std::endl;

	std::cout	<< "int: " << static_cast<int>(c)
				<< std::endl;

	std::cout	<< "float: " << std::fixed
				<< std::setprecision(1) << static_cast<float>(c) << "f"
				<< std::endl;

	std::cout	<< "double: " << std::fixed
				<< std::setprecision(1) << static_cast<double>(c)
				<< std::endl;
}

void	ScalarConverter::printNumber(const std::string &literal) {
	bool		isFloat = (literal[literal.size() - 1] == 'f');
	std::string	number = literal;

	if (isFloat)
		number = literal.substr(0, literal.size() - 1);

	std::string	dblMaxStr = "1.7976931348623157e+308";
	if (number.length() > dblMaxStr.length() + 2) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
		
	char	*end;
	double	valueDouble = std::strtod(number.c_str(), &end);

	if (std::isnan(valueDouble)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << std::sqrt(-1) << "f" << std::endl; //nanf
		std::cout << "double: " << (0.0 / 0.0) << std::endl; //nan
		return ;
	}
	
	if (std::isinf(valueDouble)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (valueDouble > 0) {
			std::cout << "float: +" << (1.0 / 0.0) << "f" << std::endl; //+inff
			std::cout << "double: +" << std::exp(1000) << std::endl; //+inf
		} else {
			std::cout << "float: " << (-1.0 / 0.0) << "f" <<std::endl; //-inff
			std::cout << "double: " << std::log(0.0) << std::endl; //-inf
		}
		return ;
	}

	if ((std::atof(literal.c_str()) == 0.0) && (literal.find('.') != std::string::npos || isFloat)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: 0.0f" << std::endl;
		std::cout << "double: 0.0" << std::endl;
		return ;
	}

	int	valueInt = static_cast<int>(valueDouble);

	std::cout << "char: ";
	if (valueDouble < 0 || valueDouble > 127 || valueInt != valueDouble) {
		std::cout << "impossible";
	} else if (std::isprint(valueInt)) {
		std::cout << "'" << static_cast<char>(valueInt) << "'";
	} else {
		std::cout << "Non displayable";
	}
	std::cout << std::endl;

	std::cout << "int: ";
	if (valueDouble > INT_MAX || valueDouble < INT_MIN || std::floor(valueDouble) != valueDouble) {
		std::cout << "impossible";
	} else {
		std::cout << valueInt;
	}
	std::cout << std::endl;

	std::cout << "float: ";
	float floatValue = static_cast<float>(valueDouble);

	if (valueDouble > FLT_MAX || valueDouble < -FLT_MAX) {
		std::cout << "impossible";
	} else if (floatValue == 0.0f && valueDouble != 0.0) {
		std::cout << "0.0f";
	} else if (std::abs(floatValue) < 1e-6) {  
		std::cout << "0.0f";
	} else if ((std::abs(floatValue) >= 1e+7 && (floatValue > static_cast<float>(INT_MAX) || floatValue < static_cast<float>(INT_MIN))) ||
		std::abs(floatValue) < 1e-5) {
		std::cout << std::scientific << std::setprecision(6) << floatValue << "f";
	} else {
		int precision = std::min(countDecimalPlaces(valueDouble), 6); 
		std::cout << std::fixed << std::setprecision(precision) << floatValue << "f";
	}
	std::cout << std::endl;

	std::cout << "double: ";
	double doubleValue = static_cast<double>(valueDouble);

	if (doubleValue > DBL_MAX || doubleValue < -DBL_MAX) {
		std::cout << "impossible";
	} else if (doubleValue == 0.0) { 
		std::cout << "0.0";
	} else if (std::abs(doubleValue) < 4.9406564584124654e-324) { 
		std::cout << "impossible";
	} else if (std::abs(doubleValue - DBL_MAX) < 1e+292 || std::abs(doubleValue + DBL_MAX) < 1e+292) {  
		std::cout << std::scientific << std::setprecision(5) << doubleValue;
	} else if ((std::abs(doubleValue) >= 1e+6 && (doubleValue > INT_MAX || doubleValue < INT_MIN)) ||
			(std::abs(doubleValue) < 1e-5 && doubleValue != 0.0)) {  
		std::cout << std::scientific << std::setprecision(5) << doubleValue;
	} else if (std::abs(doubleValue) < DBL_MIN) {
		std::cout << std::scientific << std::setprecision(6) << doubleValue;
	} else {
		int precision = countDecimalPlaces(doubleValue);
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(precision) << doubleValue;
		std::string result = oss.str();

		result.erase(result.find_last_not_of('0') + 1, std::string::npos);
		if (!result.empty() && result[result.size() - 1] == '.')
			result.resize(result.size() - 1);
		if (doubleValue == static_cast<int>(doubleValue))
			result += ".0";
		std::cout << result;
	}
	std::cout << std::endl;
}

void	ScalarConverter::printException(const std::string &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal == "nan" || literal == "nanf")
		std::cout << "float: nanf" << std::endl;
	else if (literal == "inf" || literal == "+inf" || literal == "+inff")
		std::cout << "float: +inff" << std::endl;
	else if (literal == "-inf" || literal == "-inff")
		std::cout << "float: -inff" << std::endl;
	else
		std::cout << literal << "f" << std::endl;

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
	else if (literal == "inf")
		std::cout << "double: +" << literal.substr(0, literal.size()) << std::endl;
	else
		std::cout << "double: " << literal << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                              HELPER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

int	ScalarConverter::countDecimalPlaces(double number) {
	std::ostringstream	oss;

	oss.precision(15);
	oss << number;
	std::string	str = oss.str();

	size_t		dotPos = str.find('.');
	if (dotPos == std::string::npos)
		return (1);

	return (str.length() - dotPos - 1);
}
