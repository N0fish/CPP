/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:41:46 by algultse          #+#    #+#             */
/*   Updated: 2025/02/26 21:30:43 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	createTestBureaucrat(Bureaucrat *&bureaucrat, const std::string& name, int grade) {
	std::cout	<< YELLOW << "Creating bureaucrat \"" << RESET << name << YELLOW
				<< "\" with grade " << grade << ":" << RESET << std::endl;
	try {
		bureaucrat = new Bureaucrat(name, grade);
		std::cout	<< GREEN << "✅ Successfully created: "
					<< RESET << *bureaucrat << std::endl;
	} catch (const std::exception& e) {
		std::cerr	<< RED << "⛔ Exception: "
					<< RESET << e.what() << std::endl;
	}
}

void	createTestForm(AForm *&form, const std::string &type, const std::string &target) {
	std::cout << CYAN << "Creating form \"" << RESET << type << CYAN
			  << "\" (Target: " << target << ")" << RESET << std::endl;
	try {
		if (type == "Shrubbery")
			form = new ShrubberyCreationForm(target);
		else if (type == "Robotomy")
			form = new RobotomyRequestForm(target);
		else if (type == "Pardon")
			form = new PresidentialPardonForm(target);
		std::cout	<< GREEN << "✅ Successfully created: "
					<< RESET << *form << std::endl;
	} catch (const std::exception &e) {
		std::cerr	<< RED << "⛔ Exception: "
					<< RESET << e.what() << std::endl;
	}
}

void testSignForm(Bureaucrat &bureaucrat, AForm &form) {
	std::cout	<< BLUE << "📌 " << BOLD << bureaucrat.getName() << RESET PURPLE
				<< " attempts to sign " << form.getName()
				<< " (Required: " << form.getGradeToSign()
				<< ", Bureaucrat's grade: " << bureaucrat.getGrade() << ")"
				<< RESET << std::endl;

	bureaucrat.signForm(form);
}

void	testExecuteForm(Bureaucrat &bureaucrat, AForm &form) {
	std::cout	<< PURPLE << "📌 " << BOLD << bureaucrat.getName() << RESET BLUE
				<< " attempts to execute " << form.getName()
				<< " (Required: " << form.getGradeToExecute()
				<< ", Bureaucrat's grade: " << bureaucrat.getGrade() << ")"
				<< RESET << std::endl;
	
	bureaucrat.executeForm(form);
}

int main() {
	std::srand(static_cast<unsigned>(std::time(0)));

	std::cout << BOLD INVERSE << "\n\t=== Running All Tests ===\n" << RESET << std::endl;
	Bureaucrat	*intern = NULL;
	Bureaucrat	*manager = NULL;
	Bureaucrat	*director = NULL;

	std::cout << CYAN INVERSE << "\n\t--- Creating Bureaucrat ---" << RESET << std::endl;
	createTestBureaucrat(intern, "Trainee", 150);
	createTestBureaucrat(manager, "Manager", 50);
	createTestBureaucrat(director, "Director", 1);

	std::cout << BLUE << "\n📌 Bureaucrats created:" << RESET << std::endl;
	if (intern)
		std::cout << "🔹 " << *intern << std::endl;
	if (manager)
		std::cout << "🔹 " << *manager << std::endl;
	if (director)
		std::cout << "🔹 " << *director << std::endl;
	std::cout << CYAN INVERSE << "\t--- End of Bureaucrat Creation Test ---\n" << RESET << std::endl;

	std::cout << GREEN INVERSE << "\n\t--- Creating form ---" << RESET;
	AForm *shrubbery = NULL;
	AForm *robotomy = NULL;
	AForm *pardon = NULL;
	AForm *emptyTarget = NULL;

	std::cout << CYAN INVERSE << "\n\t--- Testing Forms Creation ---" << RESET << std::endl;
	createTestForm(shrubbery, "Shrubbery", "Office_Yard");
	// createTestForm(emptyTarget, "Shrubbery", "");
	createTestForm(robotomy, "Robotomy", "Failed_Employee");
	// createTestForm(emptyTarget, "Robotomy", "");
	createTestForm(pardon, "Pardon", "Convicted_CEO");
	// createTestForm(emptyTarget, "Pardon", "");
	std::cout << GREEN INVERSE << "\t--- End of Forms Creation Test ---\n" << RESET << std::endl;

	std::cout << YELLOW INVERSE << "\n\t--- Testing Signing Forms ---" << RESET << std::endl;
	std::cout << "- intern -" << std::endl;
	if (intern) {
		if (shrubbery) testSignForm(*intern, *shrubbery);
		if (robotomy) testSignForm(*intern, *robotomy);
		if (pardon) testSignForm(*intern, *pardon);
	}
	std::cout << "\n- manager -" << std::endl;
	if (manager) {
		if (shrubbery) testSignForm(*manager, *shrubbery);
		if (robotomy) testSignForm(*manager, *robotomy);
		if (pardon) testSignForm(*manager, *pardon);
	}
	std::cout << "\n- director -" << std::endl;
	if (director) {
		if (shrubbery) testSignForm(*director, *shrubbery);
		if (robotomy) testSignForm(*director, *robotomy);
		if (pardon) testSignForm(*director, *pardon);
	}

	std::cout << YELLOW << "\n📌 Forms status after signing:" << RESET << std::endl;
	if (shrubbery)	
		std::cout << "📄 " << *shrubbery << std::endl;
	if (robotomy)
		std::cout << "📄 " << *robotomy << std::endl;
	if (pardon)
		std::cout << "📄 " << *pardon << std::endl;
	std::cout << YELLOW INVERSE << "\t--- End Testing Signing Forms ---\n" << RESET << std::endl;
	

	std::cout << PURPLE INVERSE << "\n\t--- Testing Executing Forms ---" << RESET << std::endl;
	std::cout << "- intern -" << std::endl;
	if (intern) {
		if (shrubbery) testExecuteForm(*intern, *shrubbery);
		if (robotomy) testExecuteForm(*intern, *robotomy);
		if (pardon) testExecuteForm(*intern, *pardon);
	}
	std::cout << "\n- manager -" << std::endl;
	if (manager) {
		if (shrubbery) testExecuteForm(*manager, *shrubbery);
		if (robotomy) testExecuteForm(*manager, *robotomy);
		if (pardon) testExecuteForm(*manager, *pardon);
	}
	std::cout << "\n- director -" << std::endl;
	if (director) {
		if (shrubbery) testExecuteForm(*director, *shrubbery);
		if (robotomy) testExecuteForm(*director, *robotomy);
		if (pardon) testExecuteForm(*director, *pardon);
	}

	std::cout << CYAN INVERSE << "\n\t🛠 Testing Randomness of RobotomyRequestForm" << RESET << std::endl;
	for (int i = 0; i < 5; ++i) {
		if (director && robotomy) testExecuteForm(*director, *robotomy);
	}
	delete intern;
	delete manager;
	delete director;
	delete shrubbery;
	delete robotomy;
	delete pardon;
	delete emptyTarget;
	std::cout << PURPLE INVERSE << "\t--- End Testing Executing Forms ---\n" << RESET << std::endl;

	std::cout << BOLD INVERSE << "\n\t=== All Tests Completed ===\n" << RESET << std::endl;
	return (0);
}
