/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:32:33 by algultse          #+#    #+#             */
/*   Updated: 2023/10/08 22:56:03 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string stripWhitespace(const std::string& str)
{
	size_t	start = 0;
	size_t	end = str.size();

	while (start < end && std::isspace(str[start]))
		++start;
	while (end > start && std::isspace(str[end - 1]))
		--end;
	return (str.substr(start, end - start));
}

bool	isAlpha(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
		if (!std::isalpha(str[i]))
			return (false);
	return (true);
}

bool	isValidPhoneNumber(const std::string& str)
{
	if (str.empty())
		return (false);

	if (!std::isdigit(str[0]) && str[0] != '+')
		return (false);

	for (size_t i = 1; i < str.length(); ++i)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

std::string	formatField(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (std::string(10 - str.length(), ' ') + str);
}

bool	isValidNumber(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}
