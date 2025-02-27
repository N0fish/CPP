/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:41:46 by algultse          #+#    #+#             */
/*   Updated: 2025/02/27 02:11:20 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
		bureaucrat = NULL;
	}
}

void	createTestForm(Intern &intern, AForm *&form, const std::string &formName, const std::string &target) {
	std::cout	<< CYAN << "Intern attempts to create: "
				<< formName << " (Target: " << target << ")"
				<< RESET << std::endl;
	try {
		form = intern.makeForm(formName, target);
		std::cout	<< GREEN << "✅ Successfully created: "
					<< RESET << *form << std::endl;
	} catch (const std::exception &e) {
		std::cerr	<< RED << "⛔ Form creation failed: " << e.what()
					<< RESET << std::endl;
		form = NULL;
	}
}

void	testSignAndExecute(Bureaucrat *bureaucrat, AForm *form) {
	if (!bureaucrat || !form) {
		std::cerr << RED << "⛔ Cannot proceed: Bureaucrat or Form is NULL" << RESET << std::endl;
		return;
	}
	std::cout	<< BLUE << "\n📌 " << bureaucrat->getName() << RESET PURPLE
				<< " attempts to sign & execute " << form->getName()
				<< " (Sign: " << form->getGradeToSign()
				<< ", Exec: " << form->getGradeToExecute() << ")"
				<< RESET << std::endl;
	try {
		bureaucrat->signForm(*form);
		if (!form->getIsSigned()) {
			std::cerr	<< RED << "⛔ Cannot execute unsigned form: "
						<< form->getName() << RESET << std::endl;
			// return ;
		}
		bureaucrat->executeForm(*form);
	} catch (const std::exception &e) {
		std::cerr << RED << "⛔ Exception: " << e.what() << RESET << std::endl;
	}
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
	Intern intern;
	Bureaucrat *internBureaucrat = NULL;
	Bureaucrat *manager = NULL;
	Bureaucrat *director = NULL;

	std::cout << CYAN INVERSE << "\n\t--- Creating Bureaucrat ---" << RESET << std::endl;
	createTestBureaucrat(internBureaucrat, "InternBureaucrat", 150);
	createTestBureaucrat(manager, "Manager", 50);
	createTestBureaucrat(director, "Director", 1);

	std::cout << BLUE << "\n📌 Bureaucrats created:" << RESET << std::endl;
	if (internBureaucrat)
		std::cout << "🔹 " << *internBureaucrat << std::endl;
	if (manager)
		std::cout << "🔹 " << *manager << std::endl;
	if (director)
		std::cout << "🔹 " << *director << std::endl;
	std::cout << CYAN INVERSE << "\t--- End of Bureaucrat Creation Test ---\n" << RESET << std::endl;

	std::cout << GREEN INVERSE << "\n\t--- Creating form ---" << RESET;
	AForm *shrubbery = NULL;
	AForm *robotomy = NULL;
	AForm *pardon = NULL;

	std::cout << CYAN INVERSE << "\n\t--- Testing Forms Creation ---" << RESET << std::endl;
	createTestForm(intern, shrubbery, "shrubbery creation", "Office_Yard");
	createTestForm(intern, robotomy, "robotomy request", "Bender");
	createTestForm(intern, pardon, "presidential pardon", "Convicted_CEO");
	AForm *invalidForm = NULL;
	createTestForm(intern, invalidForm, "unknown form", "Mystery");
	std::cout << GREEN INVERSE << "\t--- End of Forms Creation Test ---\n" << RESET << std::endl;

	std::cout << PURPLE INVERSE << "\n\t--- Testing Signing and Executing Forms ---" << RESET;
	testSignAndExecute(internBureaucrat, pardon);
	testSignAndExecute(manager, shrubbery);
	testSignAndExecute(director, robotomy);

	std::cout << RED << "\n--- isolated case ---" << RESET << std::endl;
	std::cout << RED << "🛠 Attempting to execute an unsigned form (should fail)!" << RESET << std::endl;
	AForm *unsignedForm = NULL;
	createTestForm(intern, unsignedForm, "shrubbery creation", "Untouched_Garden");
	if (unsignedForm) {
		std::cout << RED << "📌 Attempting to execute " << unsignedForm->getName() << " without signing it." << RESET << std::endl;
		director->executeForm(*unsignedForm);
	}
	std::cout << GREEN << "\n✅ Now signing and executing the form (should work)" << RESET;
	testSignAndExecute(director, unsignedForm);
	std::cout << PURPLE INVERSE << "\t--- End Testing Signing and Executing Forms ---\n" << RESET << std::endl;

	std::cout << YELLOW << "📌 Forms status after signing:" << RESET << std::endl;
	if (shrubbery)	
		std::cout << "shrubbery    📄 " << *shrubbery << std::endl;
	if (robotomy)
		std::cout << "robotomy     📄 " << *robotomy << std::endl;
	if (pardon)
		std::cout << "pardon       📄 " << *pardon << std::endl;
	if (unsignedForm)
		std::cout << "unsignedForm 📄 " << *unsignedForm << std::endl;

	std::cout << CYAN INVERSE << "\n\t🛠 Testing Randomness of RobotomyRequestForm" << RESET << std::endl;
	for (int i = 0; i < 5; ++i) {
		if (director && robotomy) testExecuteForm(*director, *robotomy);
	}

	delete internBureaucrat;
	delete manager;
	delete director;
	delete shrubbery;
	delete robotomy;
	delete pardon;
	delete unsignedForm;
	delete invalidForm;

	std::cout << BOLD INVERSE << "\n\t=== All Tests Completed ===\n" << RESET << std::endl;
	return (0);
}
