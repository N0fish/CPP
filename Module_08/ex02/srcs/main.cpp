
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:51:46 by algultse          #+#    #+#             */
/*   Updated: 2025/03/20 22:57:00 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	printHeader(const std::string &title) {
	std::cout << CYAN "\n🔹 " << title << RESET << std::endl;
}

void	printSuccess(const std::string &msg) {
	std::cout << GREEN "✔️ " << msg << RESET << std::endl;
}

void	printError(const std::string &msg) {
	std::cerr << RED "✖️ " << msg << RESET << std::endl;
}

void	testSubject() {
	printHeader("[Subject Test]");

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "All elements: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::stack<int> s(mstack);
	
	std::cout << std::endl;
}

void	testCopyAndAssign() {
	printHeader("[Copy and Assignment Test]");

	MutantStack<int> original;
	original.push(42);
	original.push(52);

	MutantStack<int> copy(original);
	MutantStack<int> assigned;
	assigned = original;

	copy.push(62);

	if (original.size() == copy.size() - 1) {
		printSuccess("Copy was created correctly!");
	} else {
		printError("Copy modified the original!");
	}

	if (original.size() == assigned.size()) {
		printSuccess("Assignment works correctly!");
	} else {
		printError("Assignment does not work correctly!");
	}
}

void	testIterators() {
	printHeader("[Iterator Tests]");

	MutantStack<int> stack;

	for (int i = 1; i <= 5; ++i) {
		stack.push(i);
	}

	std::cout << "Forward iteration: ";
	for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it) {
		std::cout << *it << " ";
	}

	std::cout << "\nReverse iteration: ";
	for (MutantStack<int>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	testEdgeCases() {
	printHeader("[Edge Cases]");

	MutantStack<int> emptyStack;

	std::cout << "Trying to pop from empty stack..." << std::endl;
	if (emptyStack.empty()) {
		printSuccess("Pop operation skipped (stack is empty)");
	} else {
		emptyStack.pop();
		printError("Pop operation did not check for empty stack!");
	}

	std::cout << "Trying to get top of empty stack..." << std::endl;
	if (emptyStack.empty()) {
		printSuccess("Top operation skipped (stack is empty)");
	} else {
		std::cout << "Top: " << emptyStack.top() << std::endl;
		printError("Top operation did not check for empty stack!");
	}
}

void	testComparison() {
	printHeader("[Comparison Test: MutantStack vs. std::list]");

	MutantStack<int> mstack;
	mstack.push(42);
	mstack.push(43);
	std::cout << "MutantStack Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "MutantStack Size: " << mstack.size() << std::endl;
	mstack.push(21);
	mstack.push(12);
	mstack.push(424);
	mstack.push(-100);

	std::cout << "MutantStack Elements (forward): ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "MutantStack Elements (reverse): ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << std::endl;

	std::list<int> lst;
	lst.push_back(42);
	lst.push_back(43);
	std::cout << "std::list Back: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "std::list Size: " << lst.size() << std::endl;
	lst.push_back(21);
	lst.push_back(12);
	lst.push_back(424);
	lst.push_back(-100);

	std::cout << "std::list Elements (forward): ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "std::list Elements (reverse): ";
	for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << std::endl;
}

void	testComparisonConst() {
	printHeader("[Comparison Test: const MutantStack vs. const std::list]");

	MutantStack<int> tempStack;
	tempStack.push(10);
	tempStack.push(20);
	tempStack.push(30);
	tempStack.push(40);

	const MutantStack<int> mstack(tempStack);

	std::cout << "Const MutantStack Top: " << mstack.top() << std::endl;
	std::cout << "Const MutantStack Size: " << mstack.size() << std::endl;

	std::cout << "Const MutantStack Elements (forward): ";
	for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Const MutantStack Elements (reverse): ";
	for (MutantStack<int>::const_reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << std::endl;

	std::list<int> tempList;
	tempList.push_back(10);
	tempList.push_back(20);
	tempList.push_back(30);
	tempList.push_back(40);

	const std::list<int> lst(tempList);

	std::cout << "Const std::list Back: " << lst.back() << std::endl;
	std::cout << "Const std::list Size: " << lst.size() << std::endl;

	std::cout << "Const std::list Elements (forward): ";
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Const std::list Elements (reverse): ";
	for (std::list<int>::const_reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << std::endl;
}

int	main()
{
	std::cout << YELLOW "\tRunning tests for MutantStack" << RESET << std::endl;

	testSubject();
	testCopyAndAssign();
	testIterators();
	testEdgeCases();
	testComparison();
	testComparisonConst();

	std::cout << YELLOW "\n\tALL TESTS COMPLETED!" << RESET << std::endl;
	return (0);
}
