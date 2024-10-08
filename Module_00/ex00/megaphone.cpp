/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:12:49 by algultse          #+#    #+#             */
/*   Updated: 2023/10/01 13:57:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

// namespace STD {
// 	void NewTest2() {

// 	}
// 	class Test2 {
// 		public:
// 		void static Salut() {
// 			std::cout << "salut :)" << std::endl;
// 		}
// 	};
// 	class Test {
// 		public:
// 		void static Salut() {
// 			std::cout << "salut :)" << std::endl;
// 		}
// 	};
// };

// int	main(int argc, char **argv)
// {
// 	if (argc == 1)
// 	{
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
// 		exit(0);
// 	}
// 	// STD::Test::Salut();
// 	// STD::NewTest2();
// 	for (int i = 1; i < argc && argv[i]; i++)
// 	{
// 		std::string str = argv[i];
// 		for (size_t j = 0; j < str.length(); j++)
// 			argv[i][j] = toupper(argv[i][j]);
// 		std::cout << argv[i];
// 		if (i < argc - 1 && str.back() != ' ' && std::string(argv[i + 1]).front() != ' ')
// 			std::cout << " ";
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }


/* first example */

// std::string	louder(std::string str)
// {
// 	for (size_t i = 0; i < str.length(); i++)
// 		str[i] = toupper(str[i]);
// 	return (str);
// }

// void	megaphone(int argc, char **argv)
// {
// 	std::string	str;

// 	for (int i = 1; i < argc && argv[i]; i++)
// 	{
// 		str = louder(std::string(argv[i]));
// 		std::cout << str;
// 		if (i < argc - 1 && str.back() != ' ' && std::string(argv[i + 1]).front() != ' ')
// 			std::cout << " ";
// 	}
// 	std::cout << std::endl;
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 1)
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
// 	else
// 		megaphone(argc, argv);
// 	return (0);
// }

/* second example */

// int	main(int argc, char **argv)
// {
// 	if (argc == 1)
// 	{
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
// 		exit(0);
// 	}
// 	for (int i = 1; i < argc && argv[i]; i++)
// 	{
// 		std::string str = argv[i];
// 		for (size_t j = 0; j < str.length(); j++)
// 			argv[i][j] = toupper(argv[i][j]);
// 		std::cout << argv[i];
// 		if (i < argc - 1 && str.back() != ' ' && std::string(argv[i + 1]).front() != ' ')
// 			std::cout << " ";
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }

/* third example */

#define NO_ARG	"* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << NO_ARG << std::endl;
		exit(0);
	}
	for (int i = 1; i < argc && argv[i]; i++)
	{
		for (size_t j = 0; j < std::string(argv[i]).length(); j++)
			std::cout << (char)std::toupper(argv[i][j]);
		if (i < argc - 1 && std::string(argv[i]).back() != ' ' && std::string(argv[i + 1]).front() != ' ')
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
