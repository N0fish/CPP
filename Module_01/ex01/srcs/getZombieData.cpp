/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getZombieData.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:16:04 by algultse          #+#    #+#             */
/*   Updated: 2024/10/20 21:29:22 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static std::string stripWhitespace(const std::string& str)
{
	size_t	start = 0;
	size_t	end = str.size();

	while (start < end && std::isspace(str[start]))
		++start;
	while (end > start && std::isspace(str[end - 1]))
		--end;
	return (str.substr(start, end - start));
}

static std::string	getInput(std::string request)
{
	std::string	cmd;

	std::cout << request << std::flush;
	if (!std::getline(std::cin, cmd))
	{
		if (cmd.empty() && std::cin.eof())
			exit(0);
		std::cin.clear();
	}
	return (stripWhitespace(cmd));
}

static bool	isValidNumber(const std::string& str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); ++i)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

static int	getValidatedNumber(const std::string& request)
{
	while(true)
	{
		std::string input = getInput(request);
		if (isValidNumber(input))
		{
			long long			N;
			std::istringstream	iss(input);
			iss >> N;
			if (N >= 0 && N <= 500000)
				return ((int)N);
		}
	}
}

void	getZombieData(int& N, std::string& name)
{
	std::cout	<< PURPLE << "Hello!" << NC << std::endl;

	N = getValidatedNumber("Enter the number of zombies > ");
	std::cout << std::endl;

	while (true)
	{
		name = getInput("Enter the zombie's name > ");
		if (!name.empty())
			break ;
	}
}
