/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:12:49 by algultse          #+#    #+#             */
/*   Updated: 2024/10/25 10:18:00 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

#define NO_ARG	"* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << NO_ARG << std::endl;
		exit(0);
	}
	for (int i = 1; i < argc && argv[i]; i++)
	{
		std::string	str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
			std::cout << (char)std::toupper(str[j]);
		if (i < argc - 1 && str[str.length() -1] != ' ' && std::string(argv[i + 1])[0] != ' ')
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
