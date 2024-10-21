/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:30:03 by algultse          #+#    #+#             */
/*   Updated: 2024/10/14 19:38:06 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define RED "\e[31m"

void	checkArguments(int argc, char **argv)
{
	if (argc != 4)
		return ;
	std::cerr	<< RED
				<< "Utilisation : " << std::string(argv[0])
				<< " <nom_fichier> <sous_chaine_a_remplacer> <remplacement>"
				<< std::endl;
	exit(1);
}

int	main(int argc, char **argv)
{
	checkArguments(argc, argv);

	return (0);
}
