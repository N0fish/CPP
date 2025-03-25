/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:49:21 by algultse          #+#    #+#             */
/*   Updated: 2025/03/18 00:25:10 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	printHeader(const std::string &title) {
	std::cout << CYAN "\n🔹 " << title << RESET << std::endl;
}

void	printSuccess(const std::string &msg) {
	std::cout << GREEN "✔️ " << msg << RESET << std::endl;
}

void	printError(const std::string &msg) {
	std::cerr << RED "✖️ " << msg << RESET << std::endl;
}

template <typename T>
void	testContainer(const std::string &name, T &container, int value) {
	printHeader("[Container test: " + name + "]");

	std::cout << "Content: ";
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	try {
		typename T::iterator result = easyfind(container, value);
		std::cout << "We are looking for: " << value << " → ";
		std::stringstream	ss;
		ss << *result;
		printSuccess("Found: " + ss.str());
	} catch (const std::exception &e) {
		std::cerr << "We are looking for: " << value << " → ";
		printError(e.what());
	}
}

int	main()
{
	std::cout << YELLOW "\tRunning tests for easyfind" << RESET << std::endl;

	std::vector<int> vec;
	for (int i = 1; i <= 10; i++)
		vec.push_back(i);
	testContainer("Vector", vec, 5);
	testContainer("Vector", vec, 42);

	std::list<int> lst;
	for (int i = -5; i <= 5; i++)
		lst.push_back(i);
	testContainer("List", lst, -3);
	testContainer("List", lst, 10);

	std::deque<int> deq;
	for (int i = 140; i <= 145; i++)
		deq.push_back(i);
	testContainer("Deque", deq, 142);
	testContainer("Deque", deq, 424);

	std::set<int> st;
	for (int i = 1; i <= 10; i++)
		st.insert(i * 10);
	testContainer("Set", st, 40);
	testContainer("Set", st, 21);

	std::vector<int> emptyVec;
	testContainer("empty Vector", emptyVec, 42);

	std::multiset<int> ms;
	for (int i = 1; i <= 4; i++)
		ms.insert(i * 10);
	ms.insert(20);
	ms.insert(40);
	ms.insert(40);
	testContainer("MultiSet", ms, 20);
	testContainer("MultiSet", ms, 99);

	std::cout << YELLOW "\n\tALL TESTS COMPLETED!" << RESET << std::endl;
	return (0);
}
