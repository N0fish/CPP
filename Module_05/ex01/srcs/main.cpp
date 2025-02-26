/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:41:46 by algultse          #+#    #+#             */
/*   Updated: 2025/02/22 17:01:43 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	createTestBureaucrat(const std::string& name, int grade) {
	std::cout	<< YELLOW << "\nCreating bureaucrat \"" << RESET << name << YELLOW
				<< "\" with grade " << grade << ":" << RESET << std::endl;
	try {
		Bureaucrat	bureaucrat(name, grade);

		std::cout	<< GREEN << "✅ Successfully created: "
					<< RESET << bureaucrat << std::endl;
	} catch (const std::exception& e) {
		std::cerr	<< RED << "⛔ Exception: "
					<< RESET << e.what() << std::endl;
	}
}

void	createTestForm(const std::string& name, int gradeToSign, int gradeToExecute) {
	std::cout	<< CYAN << "\nCreating form \"" << RESET << name << CYAN
				<< "\" with sign grade " << gradeToSign
				<< " and execute grade " << gradeToExecute << ":"
				<< RESET << std::endl;
	try {
		Form	form(name, gradeToSign, gradeToExecute);

		std::cout	<< GREEN << "✅ Successfully created: "
					<< RESET << form << std::endl;
	} catch (const std::exception& e) {
		std::cerr	<< RED << "⛔ Exception: "
					<< RESET << e.what() << std::endl;
	}
}

void	testSignForm(Bureaucrat& bureaucrat, Form& form) {
	std::cout	<< BLUE << "\nBureaucrat \"" << bureaucrat.getName()
				<< "\" attempts to sign form \"" << form.getName()
				<< "\"..." << RESET << std::endl;

	bureaucrat.signForm(form);
	if (form.getIsSigned())
		std::cout	<< GREEN << "✅ " << bureaucrat.getName()
					<< " successfully signed " << form.getName()
					<< RESET << std::endl;
	else
		std::cerr	<< RED << "❌ " << bureaucrat.getName()
					<< " failed to sign " << form.getName()
					<< RESET << std::endl;
}

void	testCopyAndAssignment() {
	std::cout << CYAN INVERSE << "\n\t--- Testing Copy and Assignment ---" << RESET;

	try {
		std::cout << YELLOW << "\nTesting Bureaucrat Copy and Assignment" << RESET << std::endl;

		Bureaucrat*	original = NULL;
		Bureaucrat*	copy = NULL;
		Bureaucrat*	assigned = NULL;

		try { original = new Bureaucrat("Original", 42); }
		catch (const std::exception &e) {
			std::cerr	<< RED << "⛔ Bureaucrat Original creation failed: "
						<< RESET << e.what() << std::endl;
		}
		try { if (original) copy = new Bureaucrat(*original); }
		catch (const std::exception &e) {
			std::cerr	<< RED << "⛔ Bureaucrat Copy creation failed: "
						<< RESET << e.what() << std::endl;
		}
		try { if (original) assigned = new Bureaucrat(*original); }
		catch (const std::exception &e) {
			std::cerr	<< RED << "⛔ Bureaucrat Assignment failed: "
						<< RESET << e.what() << std::endl;
		}

		if (original)
			std::cout << GREEN << "Original: " << RESET << *original << std::endl;
		if (copy)
			std::cout << GREEN << "Copy: " << RESET << *copy << std::endl;
		if (assigned)
			std::cout << GREEN << "Assigned: " << RESET << *assigned << std::endl;

		delete original;
		delete copy;
		delete assigned;

	} catch (const std::exception& e) {
		std::cerr	<< RED << "⛔ Exception during Bureaucrat copy or assignment: "
					<< RESET << e.what() << std::endl;
	}

	try {
		std::cout	<< YELLOW << "\nTesting Form Copy and Assignment" << RESET << std::endl;

		Form*	formOriginal = NULL;
		Form*	formCopy = NULL;
		Form*	formAssigned = NULL;

		try { formOriginal = new Form("Contract", 50, 20); }
		catch (const std::exception &e) {
			std::cerr	<< RED << "⛔ Form Original creation failed: "
						<< RESET << e.what() << std::endl;
		}
		try { if (formOriginal) formCopy = new Form(*formOriginal); }
		catch (const std::exception &e) {
			std::cerr	<< RED << "⛔ Form Copy creation failed: "
						<< RESET << e.what() << std::endl;
		}
		try { if (formOriginal) formAssigned = new Form(*formOriginal); }
		catch (const std::exception &e) {
			std::cerr	<< RED << "⛔ Form Assignment failed: "
						<< RESET << e.what() << std::endl;
		}

		if (formOriginal)
			std::cout << GREEN << "Original Form: " << RESET << *formOriginal << std::endl;
		if (formCopy)
			std::cout << GREEN << "Copy Form: " << RESET << *formCopy << std::endl;
		if (formAssigned)
			std::cout << GREEN << "Assigned Form: " << RESET << *formAssigned << std::endl;

		delete formOriginal;
		delete formCopy;
		delete formAssigned;

	} catch (const std::exception& e) {
		std::cerr	<< RED << "⛔ Exception during Form copy or assignment: "
					<< RESET << e.what() << std::endl;
	}

	std::cout << CYAN INVERSE << "\t--- End of Copy and Assignment Test ---\n" << RESET << std::endl;
}

void	testFormSigning(Bureaucrat* lowRank, Bureaucrat* midRank, Bureaucrat* highRank, \
						Form* f1, Form* f2, Form* f3) {
	if (lowRank && f1) {
		testSignForm(*lowRank, *f1);
		std::cout << "📄 " << *f1 << std::endl;
		// if (f1->getIsSigned())
		// 	std::cout << GREEN << "✅ Form is signed!" << RESET << std::endl;
		// else
		// 	std::cout << RED << "❌ Form is NOT signed!" << RESET << std::endl;
	}
	if (midRank && f1) {
		testSignForm(*midRank, *f1);
		std::cout << "📄 " << *f1 << std::endl;
	}
	if (highRank && f1) {
		testSignForm(*highRank, *f1);
		std::cout << "📄 " << *f1 << std::endl;
	}
	std::cout << "-----" << std::endl;

	if (lowRank && f2)
	testSignForm(*lowRank, *f2);
	if (midRank && f2)
		testSignForm(*midRank, *f2);
	if (highRank && f2)
		testSignForm(*highRank, *f2);
	std::cout << "-----" << std::endl;

	if (lowRank && f3)
		testSignForm(*lowRank, *f3);
	if (midRank && f3)
		testSignForm(*midRank, *f3);
	if (highRank && f3)
		testSignForm(*highRank, *f3);
}

void	setupBureaucratsAndForms() {
	std::cout << GREEN INVERSE << "\n\t--- Signing Forms Tests ---" << RESET;

	Bureaucrat*	lowRank = NULL;
	Bureaucrat*	midRank = NULL;
	Bureaucrat*	highRank = NULL;

	try { lowRank = new Bureaucrat("Trainee", 140); }
	catch (const std::exception &e) {
		std::cerr	<< RED << "\n⛔ Bureaucrat Trainee creation failed: "
					<< RESET << e.what() << std::endl;
	}
	try { midRank = new Bureaucrat("Manager", 50); }
	catch (const std::exception &e) {
		std::cerr	<< RED << "\n⛔ Bureaucrat Manager creation failed: "
					<< RESET << e.what() << std::endl;
	}
	try { highRank = new Bureaucrat("Director", 1); }
	catch (const std::exception &e) {
		std::cerr	<< RED << "\n⛔ Bureaucrat Director creation failed: "
					<< RESET << e.what() << std::endl;
	}
	std::cout << BLUE << "\n📌 Bureaucrats:" << RESET << std::endl;
	if (lowRank)
		std::cout << "🔹 " << *lowRank << std::endl;
	if (midRank)
		std::cout << "🔹 " << *midRank << std::endl;
	if (highRank)
		std::cout << "🔹 " << *highRank << std::endl;

	Form*	easyForm = NULL;
	Form*	mediumForm = NULL;
	Form*	hardForm = NULL;

	try { easyForm = new Form("Vacation Request", 130, 100); }
	catch (const std::exception &e) {
		std::cerr	<< RED << "\n⛔ Form Vacation Request creation failed: "
					<< RESET << e.what() << std::endl;
	}
	try { mediumForm = new Form("Budget Approval", 50, 25); }
	catch (const std::exception &e) {
		std::cerr	<< RED << "\n⛔ Form Budget Approval creation failed: "
					<< RESET << e.what() << std::endl;
	}
	try { hardForm = new Form("Top Secret Document", 10, 5); }
	catch (const std::exception &e) {
		std::cerr	<< RED << "\n⛔ Form Top Secret Document creation failed: "
					<< RESET << e.what() << std::endl;
	}
	std::cout << CYAN << "📌 Forms and Requirements:" << RESET << std::endl;
	if (easyForm)
		std::cout << "📄 " << *easyForm << std::endl;
	if (mediumForm)
		std::cout << "📄 " << *mediumForm << std::endl;
	if (hardForm)
		std::cout << "📄 " << *hardForm << std::endl;

	testFormSigning(lowRank, midRank, highRank, easyForm, mediumForm, hardForm);

	delete lowRank;
	delete midRank;
	delete highRank;
	delete easyForm;
	delete mediumForm;
	delete hardForm;

	std::cout << GREEN INVERSE << "\t--- End of Signing Forms Tests ---\n" << RESET << std::endl;
}

int main() {
	std::cout << BOLD INVERSE << "\n\t=== Running All Tests ===\n" << RESET << std::endl;

	std::cout << CYAN INVERSE << "\n\t--- Creating Bureaucrat ---" << RESET;
	createTestBureaucrat("Director", 1);
	createTestBureaucrat("Trainee", 150);
	createTestBureaucrat("InvalidLow", 0);
	createTestBureaucrat("InvalidHigh", 151);
	std::cout << CYAN INVERSE << "\t--- End of Bureaucrat Creation Test ---\n" << RESET << std::endl;

	std::cout << PURPLE INVERSE << "\n\t--- Creating Form ---" << RESET;
	createTestForm("Form A", 50, 20);
	createTestForm("Form B", 1, 1);
	createTestForm("Form C", 150, 150);
	createTestForm("InvalidForm1", 151, 20);
	createTestForm("InvalidForm2", 20, 0);
	std::cout << PURPLE INVERSE << "\t--- End of Form Creation Test ---\n" << RESET << std::endl;

	setupBureaucratsAndForms();

	testCopyAndAssignment();

	std::cout << BOLD INVERSE << "\n\t=== All Tests Completed ===\n" << RESET << std::endl;
	return (0);
}
