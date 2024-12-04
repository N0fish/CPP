/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:07:01 by algultse          #+#    #+#             */
/*   Updated: 2024/12/04 12:01:30 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void	checkArguments(int argc, char **argv)
{
	if (argc == 1)
		return ;
	std::cerr	<< PURPLE "Error: " << std::string(argv[0])
				<< " needs no arguments from you" RESET
				<< std::endl;
	exit(EXIT_FAILURE);
}

void	testPointInsideTriangle(Point const &a, Point const &b, Point const &c, Point const &p, bool expected) 
{
	bool	result;

	std::cout	<< "  Testing point (" BOLD BLUE
				<< p.getX() << ", " << p.getY() << RESET 
				<< ") \n\tin triangle " 
				<< PURPLE "a" RESET "(" << a.getX() << ", " << a.getY() << ") -> " 
				<< PURPLE "b" RESET "(" << b.getX() << ", " << b.getY() << ") -> "
				<< PURPLE "c" RESET "(" << c.getX() << ", " << c.getY() << "): ";

	result = bsp(a, b, c, p);
	if (result == expected)
		std::cout	<< GREEN "PASSED" RESET	
					<< std::endl;
	else
		std::cout	<< RED "FAILED" RESET	
					<< std::endl;
}

int main(int argc, char **argv)
{
	checkArguments(argc, argv);

	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	std::cout	<< INVERSE CYAN "\n\t\t--- Testing Points ---\n" RESET	<< std::endl;

	std::cout	<< INVERSE BLACK "Inside" RESET GREEN " inside" RESET
				<< std::endl;
	testPointInsideTriangle(a, b, c, Point(1, 1), true);
	std::cout	<< INVERSE BLACK "Outside" RESET RED " outside" RESET
				<< std::endl;
	testPointInsideTriangle(a, b, c, Point(10, 10), false);
	std::cout	<< INVERSE BLACK "On edge" RESET RED " outside" RESET
				<< std::endl;
	testPointInsideTriangle(a, b, c, Point(0, 5), false);
	std::cout	<< INVERSE BLACK "Lies on the edge AB" RESET RED " outside" RESET
				<< std::endl;
	testPointInsideTriangle(a, b, c, Point(5, 0), false);
	std::cout	<< INVERSE BLACK "Coincides with vertex A" RESET RED " outside" RESET
				<< std::endl;
	testPointInsideTriangle(a, b, c, Point(0, 0), false);
	std::cout	<< INVERSE BLACK "Outside the triangle" RESET RED " outside" RESET
				<< std::endl;
	testPointInsideTriangle(a, b, c, Point(-1, -1), false);

	return (0);
}
