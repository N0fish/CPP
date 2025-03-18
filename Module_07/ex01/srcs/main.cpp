/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:12:50 by algultse          #+#    #+#             */
/*   Updated: 2025/03/18 16:49:31 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "test.hpp"

class Awesome {
	private:
		int _n;
	public:
		Awesome(void) : _n(42) {}
		int get(void) const {
			return (this->_n);
		}
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {
	o << rhs.get();
	return (o);
}

// template <typename T>
// void	print(T const &x)
// {
// 	std::cout << x << std::endl;
// 	return ;
// }

// int main() {
// 	int tab[] = {0, 1, 2, 3, 4};
// 	Awesome tab2[5];
// 	iter(tab, 5, print);
// 	iter(tab2, 5, print);
// 	return (0);
// }

void	printHeader(const std::string& title) {
	std::cout << BOLD << CYAN << "\n🔹 " << title << RESET << std::endl;
}

int main() {
	printHeader("[Test with int array]");
	int intArray[] = {0, 1, 2, 3, 4};
	iter(intArray, 5, printElement);
	std::cout << std::endl;

	iter(intArray, 5, addOne);
	iter(intArray, 5, printElement);
	std::cout << std::endl;

	printHeader("[Test with double array]");
	double doubleArray[] = {0.2, 1.5, 20.5, 11.0};
	iter(doubleArray, 4, printElement);
	std::cout << std::endl;

	iter(doubleArray, 4, roundDouble);
	iter(doubleArray, 4, printElement);
	std::cout << std::endl;

	printHeader("[Test with char array]");
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	iter(charArray, 5, printElement);
	std::cout << std::endl;

	iter(charArray, 5, toUpperCase);
	iter(charArray, 5, printElement);
	std::cout << std::endl;

	printHeader("[Test with string array]");
	std::string strArray[] = {"hello", "world", "!"};
	iter(strArray, 3, printElement);
	std::cout << std::endl;

	iter(strArray, 3, capitalizeString);
	iter(strArray, 3, printElement);
	std::cout << std::endl;

	iter(strArray, 3, appendSuffix);
	iter(strArray, 3, printElement);
	std::cout << std::endl;

	printHeader("[Test with Awesome class array]");
	Awesome awesomeArray[5];
	iter(awesomeArray, 5, printElement);
	std::cout << std::endl;

	printHeader("[Test with empty array]");
	int emptyArray[0];
	iter(emptyArray, 0, printElement);
	std::cout << std::endl;

	printHeader("[Test with nullptr]");
	int* nullArray = NULL;
	iter(nullArray, 5, printElement);

	std::cout << BOLD << YELLOW << "\n\tALL TESTS PASSED!" << RESET << std::endl;
	return (0);
}
