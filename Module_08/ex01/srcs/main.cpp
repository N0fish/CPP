/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:15:40 by algultse          #+#    #+#             */
/*   Updated: 2025/03/18 00:32:53 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	printHeader(const std::string &title) {
	std::cout << CYAN "\n🔹 " << title << RESET << std::endl;
}

void	printSuccess(const std::string &msg) {
	std::cout << GREEN "✔️ " << msg << RESET << std::endl;
}

void	printError(const std::string &msg) {
	std::cerr << RED "✖️ " << msg << RESET << std::endl;
}

void	testBasicSpan() {
	printHeader("Basic test: code from the task");

	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest interval: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest interval: " << sp.longestSpan() << std::endl;
}

void	testEdgeCases() {
	printHeader("Testing edge cases");

	Span emptySpan(0);
	try {
		emptySpan.addNumber(42);
		printError("Error: Failed to add number to Span(0)!");
	} catch (const std::exception &e) {
		printSuccess("The exception was thrown correctly: " + std::string(e.what()));
	}

	Span singleSpan(1);
	singleSpan.addNumber(10);
	try {
		singleSpan.shortestSpan();
		printError("Error: shortestSpan() did not throw an exception!");
	} catch (const std::exception &e) {
		printSuccess("The exception was thrown correctly: " + std::string(e.what()));
	}
}

void	testCopyAndAssign() {
	printHeader("Copy and Assignment Test");

	Span sp1(5);
	sp1.addNumber(10);
	sp1.addNumber(20);

	Span sp2(sp1);
	Span sp3(5);
	sp3 = sp1;

	sp2.addNumber(30);
	if (sp1.shortestSpan() != sp2.shortestSpan()) {
		printSuccess("The copy was created correctly!");
	} else {
		printError("Error: copy has modified original!");
	}

	if (sp1.shortestSpan() == sp3.shortestSpan()) {
		printSuccess("The assignment works correctly!");
	} else {
		printError("Error: assignment does not work correctly!");
	}
}

void	testRangeAddition() {
	printHeader("Adding ranges of elements");

	Span sp(10);
	std::vector<int> numbers;
	for (int i = 1; i <= 5; i++) numbers.push_back(i);
	
	sp.addNumbers(numbers.begin(), numbers.end());

	if (sp.shortestSpan() == 1) {
		printSuccess("The range has been added correctly!");
	} else {
		printError("Error adding range!");
	}
}

void	testPerformance() {
	printHeader("Performance testing");

	Span bigSpan(100000);
	std::vector<int> bigNumbers;
	for (int i = 0; i < 100000; i++) {
		bigNumbers.push_back(std::rand() % 1000000);
	}

	try {
		bigSpan.addNumbers(bigNumbers.begin(), bigNumbers.end());
		printSuccess("Adding 100000 numbers was successful!");
	} catch (const std::exception &e) {
		printError("Error adding 100000 numbers: " + std::string(e.what()));
	}
}

void	testMinMaxSpan() {
	printHeader("Test INT_MIN и INT_MAX");

	Span sp(2);
	sp.addNumber(-2147483648);
	sp.addNumber(2147483647);

	std::cout << "Shortest interval: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest interval: " << sp.longestSpan() << std::endl;
}

int	main()
{
	std::srand(std::time(0));

	std::cout << YELLOW "\tRunning tests for Span" << RESET << std::endl;

	testBasicSpan();
	testEdgeCases();
	testCopyAndAssign();
	testRangeAddition();
	testPerformance();
	testMinMaxSpan();

	std::cout << YELLOW "\n\tALL TESTS COMPLETED!" << RESET << std::endl;
	return (0);
}


// void	testSpan() {
// 	printHeader("[Test: Basic Span]");
// 	Span sp(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	try {
// 		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
// 		printSuccess("shortestSpan() passed!");
// 	} catch (const std::exception &e) {
// 		printError(e.what());
// 	}

// 	try {
// 		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
// 		printSuccess("longestSpan() passed!");
// 	} catch (const std::exception &e) {
// 		printError(e.what());
// 	}
// }

// void	testAddRange() {
// 	printHeader("[Test: Add Range]");
// 	Span sp(10);
	
// 	std::vector<int> numbers;
// 	numbers.push_back(1);
// 	numbers.push_back(2);
// 	numbers.push_back(3);
// 	numbers.push_back(4);
// 	numbers.push_back(5);

// 	try {
// 		sp.addNumbers(numbers.begin(), numbers.end());
// 		printSuccess("addRange() passed!");

// 		std::cout << "Contents of Span: ";
// 		for (size_t i = 0; i < numbers.size(); i++)
// 			std::cout << numbers[i] << " ";
// 		std::cout << std::endl;

// 	} catch (const std::exception &e) {
// 		printError(e.what());
// 	}
// }

// void	testExceptions() {
// 	printHeader("[Test: Exceptions]");

// 	Span sp(1);
// 	sp.addNumber(10);

// 	try {
// 		sp.addNumber(20);
// 		printError("addNumber() should have thrown an exception!");
// 	} catch (const std::exception &e) {
// 		printSuccess("Exception caught: " + std::string(e.what()));
// 	}

// 	try {
// 		sp.shortestSpan();
// 		printError("shortestSpan() should have thrown an exception!");
// 	} catch (const std::exception &e) {
// 		printSuccess("Exception caught: " + std::string(e.what()));
// 	}
// }

// int	main()
// {
// 	std::cout << YELLOW "\tRunning tests for Span" << RESET << std::endl;

// 	testSpan();
// 	testAddRange();
// 	testExceptions();

// 	std::cout << YELLOW "\n\tALL TESTS COMPLETED!" << RESET << std::endl;
// 	return (0);
// }
