/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:59:07 by algultse          #+#    #+#             */
/*   Updated: 2025/01/23 18:12:11 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	createTestBureaucrat(const std::string& name, int grade)
{
	std::cout	<< YELLOW
				<< "\nCreating bureaucrat \"" 
				<< RESET << name << YELLOW
				<< "\" with grade " << grade << ":"
				<< RESET << std::endl;
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout	<< GREEN
					<< "✅ Successfully created: "
					<< RESET << bureaucrat << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr	<< RED << "⛔ GradeTooHighException: "
					<< RESET << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr	<< RED << "⛔ GradeTooLowException: "
					<< RESET << e.what() << std::endl;
	}
}

void	testIncrementDecrement(Bureaucrat& bureaucrat)
{
	std::cout	<< CYAN
				<< "\nTesting grade increment and decrement for: "
				<< RESET << bureaucrat << std::endl;

	// Increment grade
	try {
		std::cout	<< BLUE << "Attempting to increment grade..."
					<< RESET << std::endl;
		bureaucrat.incrementGrade();
		std::cout	<< GREEN << "✅ After increment: "
					<< RESET << bureaucrat << std::endl;
	} catch (const std::exception& e) {
		std::cerr	<< RED << "⛔ Exception during increment: "
					<< RESET << e.what() << std::endl;
	}

	// Decrement grade
	try {
		std::cout	<< BLUE << "Attempting to decrement grade..."
					<< RESET << std::endl;
		bureaucrat.decrementGrade();
		std::cout	<< GREEN << "✅ After decrement: "
					<< RESET << bureaucrat << std::endl;
	} catch (const std::exception& e) {
		std::cerr	<< RED << "⛔ Exception during decrement: "
					<< RESET << e.what() << std::endl;
	}
}

void	subjectTests()
{
	std::cout << CYAN INVERSE << "\n\t--- Subject Tests ---\n" << RESET << std::endl;

	// Test 1: Create bureaucrat with valid grade
	createTestBureaucrat("Octavius", 3);

	// Test 2: Increment grade
	try {
        std::cout	<< YELLOW << "\nIncrementing grade of a bureaucrat:"
				<< RESET << std::endl;
        Bureaucrat aurelius("Aurelius", 2);
        testIncrementDecrement(aurelius);
    } catch (const std::exception& e) {
        std::cerr << RED << "⛔ Exception: " << RESET << e.what() << std::endl;
    }

	// Test 3: Decrement grade
	try {
		std::cout	<< YELLOW << "\nDecrementing grade of a bureaucrat:"
					<< RESET << std::endl;
        Bureaucrat cassian("Cassian", 149);
        testIncrementDecrement(cassian);
    } catch (const std::exception& e) {
        std::cerr << RED << "⛔ Exception: " << RESET << e.what() << std::endl;
    }

	// Test 4: Create bureaucrat with invalid grade
	createTestBureaucrat("Lucina", 151);

	std::cout << CYAN INVERSE << "\n\t--- End of Subject Tests ---\n" << RESET << std::endl;
}

void edgeCaseTests() {
    std::cout << PURPLE INVERSE << "\n\t--- Edge Case Tests ---\n" << RESET << std::endl;

    try {
        Bureaucrat highEdge("Maximus", 1);
        std::cout	<< GREEN << "✅ Successfully created: "
					<< RESET << highEdge << std::endl;
        testIncrementDecrement(highEdge);
    } catch (const std::exception& e) {
        std::cerr	<< RED << "⛔ Exception for HighEdge(Maximus): "
					<< RESET << e.what() << std::endl;
    }

	std::cout << std::endl;

    try {
        Bureaucrat lowEdge("Selene", 150);
        std::cout	<< GREEN << "✅ Successfully created: "
					<< RESET << lowEdge << std::endl;
        testIncrementDecrement(lowEdge);
    } catch (const std::exception& e) {
        std::cerr	<< RED << "⛔ Exception for LowEdge(Selene): "
					<< RESET << e.what() << std::endl;
    }

    std::cout << PURPLE INVERSE << "\n\t--- End of Edge Case Tests ---\n" << RESET << std::endl;
}

void	testCopyAndAssignment()
{
	std::cout << CYAN INVERSE << "\n\t--- Testing Copy and Assignment ---\n" << RESET << std::endl;

	try {
        Bureaucrat original("Original", 50);
        Bureaucrat copy(original);
        Bureaucrat assigned = original;

        std::cout	<< GREEN << "Original: " << RESET << original << std::endl;
        std::cout	<< GREEN << "Copy: " << RESET << copy << std::endl;
        std::cout	<< GREEN << "Assigned: " << RESET << assigned << std::endl;
    } catch (const std::exception& e) {
        std::cerr	<< RED << "⛔ Exception during copy or assignment: "
					<< RESET << e.what() << std::endl;
    }

	std::cout << CYAN INVERSE << "\n\t--- End of Copy and Assignment ---\n" << RESET << std::endl;
}

int	main()
{
	std::cout << BOLD INVERSE << "\n\t=== Running All Tests ===\n" << RESET << std::endl;

	subjectTests();

	std::cout << GREEN INVERSE << "\n\t=== Running Additional tests ===\n" << RESET << std::endl;
	createTestBureaucrat("Theon", 1);
	createTestBureaucrat("Drusus", 150);
	createTestBureaucrat("Eurydice", 0);
	createTestBureaucrat("Valeria", 151);
	createTestBureaucrat("Atticus", -10);
	createTestBureaucrat("Cornelia", 42);
	std::cout << GREEN INVERSE << "\n\t--- End of Additional test ---\n" << RESET << std::endl;

	edgeCaseTests();

	testCopyAndAssignment();

	std::cout << BOLD INVERSE << "\n\t=== All Tests Completed ===\n" << RESET << std::endl;
	return (0);
}
