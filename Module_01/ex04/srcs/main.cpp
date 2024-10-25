/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:31:34 by algultse          #+#    #+#             */
/*   Updated: 2024/10/25 10:44:31 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define RED "\e[31m"
#define YELLOW "\e[33m"
#define RESET "\e[0m"

static std::string	replaceInLine(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string	resLine = line;
	size_t		pos = 0;

	while ((pos = resLine.find(s1, pos)) != std::string::npos)
	{
		resLine.erase(pos, s1.length());
		resLine.insert(pos, s2);
		pos += s2.length();
	}
	return (resLine);
}

static bool	processFile(const std::string& inFilename, const std::string& s1, const std::string& s2)
{
	bool	status = true;

	std::string		outFilename = inFilename + ".replace";
	std::ofstream	outFile(outFilename.c_str());
	if (!outFile.is_open()) {
		std::cerr	<< RED
					<< "Error: Cannot not create file " << outFilename
					<< RESET << std::endl;
		exit(EXIT_FAILURE);
	}

	std::ifstream	inFile(inFilename.c_str());
	if (!inFile.is_open()) {
		std::cerr	<< RED
					<< "Error: Cannot not open file " << inFilename
					<< RESET << std::endl;
		status = false;
	}
	if (inFile.peek() == std::ifstream::traits_type::eof() && status)
		std::cout	<< YELLOW
					<< "The " << inFilename << " is empty. Nothing to replace"
					<< RESET << std::endl;

	if (s1.empty() && status) {
		std::cout	<< RED 
					<< "Error: first Regular Expression may not be empty" 
					<< RESET << std::endl;
		status = false;
	}

	std::string	line;
	while (std::getline(inFile, line) && status)
	{
		std::string	newLine = replaceInLine(line, s1, s2);
		outFile << newLine;
		if (!inFile.eof())
			outFile << std::endl;
	}
	
	inFile.close();
	outFile.close();
	return (status);
}

static void	checkArguments(int argc, char **argv)
{
	if (argc == 4)
		return ;
	std::cerr	<< RED
				<< "Utilisation: " << std::string(argv[0])
				<< " <nom_fichier> <sous_chaine_a_remplacer> <remplacement>"
				<< RESET << std::endl;
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	checkArguments(argc, argv);

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	if (!processFile(filename, s1, s2))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
