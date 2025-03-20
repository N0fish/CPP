/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:15:40 by algultse          #+#    #+#             */
/*   Updated: 2025/03/20 19:46:53 by algultse         ###   ########.fr       */
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

void	printSpan(const std::string &name, const Span &sp) {
	std::cout << std::left << std::setw(25) << name << ": [ ";
	std::vector<int> numbers = sp.getNumbers();
	for (size_t i = 0; i < numbers.size(); ++i) {
		std::cout << numbers[i] << " ";
	}
	std::cout << "]" << std::endl;
}

void	testBasicSpan() {
	printHeader("[Basic test: code from the task]");

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
	printHeader("[Testing edge cases]");

	Span emptySpan(0);
	try {
		emptySpan.addNumber(42);
		emptySpan.shortestSpan();
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
	printHeader("[Copy and Assignment Test]");

	Span sp1(5);
	sp1.addNumber(10);
	sp1.addNumber(20);
	printSpan("sp1 (before copy)", sp1);

	Span sp2(sp1);
	Span sp3(5);
	sp3 = sp1;
	printSpan(" sp2 (after copy)", sp2);
	printSpan(" sp3 (after assignment)", sp3);

	sp2.addNumber(30);
	printSpan("sp1 (after modifying sp2)", sp1);
	printSpan("sp2 (after adding 30)", sp2);

	if (sp1.shortestSpan() == sp2.shortestSpan()) {
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
	printHeader("[Adding ranges of elements with std::vector]");

	Span sp(10);
	std::vector<int> numbers;
	for (int i = 1; i <= 5; i++) {
		numbers.push_back(i);
	}
	
	sp.addNumbers(numbers.begin(), numbers.end());
	printSpan("After adding the range", sp);

	if (sp.shortestSpan() == 1) {
		printSuccess("The range has been added correctly!");
	} else {
		printError("Error adding range!");
	}
	if (sp.longestSpan() == 4) {
		printSuccess("Longest span is correct!");
	} else {
		printError("Error Longest span is not correct!");
	}
}

void	testListRangeAddition() {
	printHeader("[Adding ranges of elements with std::list]");

	Span sp(10);
	std::list<int> numbers;
	for (int i = 1; i <= 5; i++) {
		numbers.push_back(i);
	}
	
	sp.addNumbers(numbers.begin(), numbers.end());

	printSpan("After adding the range (list)", sp);

	if (sp.shortestSpan() == 1) {
		printSuccess("The range (from list) has been added correctly!");
	} else {
		printError("Error adding range from list!");
	}
	if (sp.longestSpan() == 4) {
		printSuccess("Longest span is correct!");
	} else {
		printError("Error Longest span is not correct!");
	}
}

void	testNegativeNumbers() {
	printHeader("[Test with Negative Numbers]");

	Span sp(5);
	sp.addNumber(-50);
	sp.addNumber(-20);
	sp.addNumber(-10);
	sp.addNumber(-1);
	sp.addNumber(0);

	printSpan("Span with negative numbers", sp);

	std::cout << "Shortest interval: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest interval: " << sp.longestSpan() << std::endl;

	if (sp.shortestSpan() > 0) {
		printSuccess("Shortest span is correct!");
	} else {
		printError("Error: shortestSpan() returned a negative value!");
	}
}

void	testPerformance() {
	printHeader("[Testing 100 000]");

	Span bigSpan(100000);
	std::vector<int> bigNumbers;
	for (int i = 0; i < 100000; i++) {
		bigNumbers.push_back(std::rand() % 1000000);
	}

	try {
		bigSpan.addNumbers(bigNumbers.begin(), bigNumbers.end());
		// printSpan("After adding the range", bigSpan);
		printSuccess("Adding 100 000 numbers was successful!");
	} catch (const std::exception &e) {
		printError("Error adding 100000 numbers: " + std::string(e.what()));
	}
}

void	testMinMaxSpan() {
	printHeader("[Test INT_MIN и INT_MAX]");

	Span sp(2);
	sp.addNumber(-2147483648);
	sp.addNumber(2147483647);
	printSpan("sp (MinMaxSpan)", sp);

	std::cout << "Shortest interval: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest interval: " << sp.longestSpan() << std::endl;
	if (sp.shortestSpan() < 0) {
		printError("Error: shortestSpan() returned a negative value!");
	} else {
		printSuccess("Shortest span is correct!");
	}

	if (sp.longestSpan() < 0) {
		printError("Error: longestSpan() returned a negative value!");
	} else {
		printSuccess("Longest span is correct!");
	}
}

int	main()
{
	std::srand(std::time(0));

	std::cout << YELLOW "\tRunning tests for Span" << RESET << std::endl;

	testBasicSpan();
	testEdgeCases();
	testCopyAndAssign();
	testRangeAddition();
	testListRangeAddition();
	testNegativeNumbers();
	testPerformance();
	testMinMaxSpan();

	std::cout << YELLOW "\n\tALL TESTS COMPLETED!" << RESET << std::endl;
	return (0);
}
