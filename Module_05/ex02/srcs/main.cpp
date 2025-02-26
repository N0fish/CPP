/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:41:46 by algultse          #+#    #+#             */
/*   Updated: 2025/02/25 17:01:43 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	createTestBureaucrat(Bureaucrat *&bureaucrat, const std::string& name, int grade) {
	std::cout	<< YELLOW << "\n📌 Creating Bureaucrat \"" << RESET << name << YELLOW
				<< "\" with grade " << grade << ":" << RESET << std::endl;
	try {
		bureaucrat = new Bureaucrat(name, grade);
		std::cout	<< GREEN << "✅ Successfully created: "
					<< RESET << *bureaucrat << std::endl;
	} catch (const std::exception& e) {
		std::cerr	<< RED << "⛔ Exception: " << RESET << e.what() << std::endl;
	}
}

void	createTestForm(AForm *&form, const std::string &type, const std::string &target) {
	std::cout << CYAN << "\n📌 Creating form: " << RESET << type << CYAN
			  << " (Target: " << target << ")" << RESET << std::endl;
	try {
		if (type == "Shrubbery") form = new ShrubberyCreationForm(target);
		else if (type == "Robotomy") form = new RobotomyRequestForm(target);
		else if (type == "Pardon") form = new PresidentialPardonForm(target);
		std::cout	<< GREEN << "✅ Successfully created: "
					<< RESET << *form << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "⛔ Exception: " << RESET << e.what() << std::endl;
	}
}


// Тест подписания формы
void testSignForm(Bureaucrat &bureaucrat, AForm &form) {
	std::cout	<< BLUE << "\n📌 " << bureaucrat.getName()
				<< " attempts to sign " << form.getName()
				<< " (Required: " << form.getGradeToSign()
				<< ", Bureaucrat's grade: " << bureaucrat.getGrade() << ")" << RESET << std::endl;

	bool wasSigned = form.getIsSigned();
    try {
        // До вызова signForm() запоминаем, была ли форма подписана
        bureaucrat.signForm(form);
        // Если после вызова signForm() форма подписалась – значит, всё ок
        if (!wasSigned && form.getIsSigned()) { 
            std::cout << GREEN << "✔️ " << bureaucrat.getName() << " successfully signed " << form.getName() << "!" << RESET << std::endl;
        } else if (wasSigned) {
            std::cout << BLUE << "ℹ️ " << form.getName() << " was already signed." << RESET << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << RED << "✖️ " << bureaucrat.getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}

// void	testSignForm(Bureaucrat &bureaucrat, AForm &form) {
// 	std::cout	<< BLUE << "\n📌 " << bureaucrat.getName()
// 				<< " attempts to sign " << form.getName()
// 				<< " (Required: " << form.getGradeToSign()
// 				<< ", Bureaucrat's grade: " << bureaucrat.getGrade() << ")" << RESET << std::endl;
// 	if (form.getIsSigned()) {
// 		std::cout << BLUE << "ℹ️ " << form.getName() << " is already signed. Skipping..." << RESET << std::endl;
// 		return;
// 	}
// 	try {
// 		bureaucrat.signForm(form);
// 		std::cout	<< GREEN << "✔️ " << bureaucrat.getName()
// 					<< " successfully signed " << form.getName() << "!" << RESET << std::endl;
// 	} catch (const std::exception &e) {
// 		std::cerr << RED << "✖️ " << bureaucrat.getName()
// 				  << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
// 	}
// }

// void	testExecuteForm(Bureaucrat &bureaucrat, AForm &form) {
// 	std::cout	<< PURPLE << "\n📌 " << bureaucrat.getName()
// 				<< " attempts to execute " << form.getName()
// 				<< " (Required: " << form.getGradeToExecute()
// 				<< ", Bureaucrat's grade: " << bureaucrat.getGrade() << ")" << RESET << std::endl;
// 	try {
// 		bureaucrat.executeForm(form);
// 		std::cout	<< GREEN << "✔️ " << bureaucrat.getName()
// 					<< " successfully executed " << form.getName() << "!" << RESET << std::endl;
// 	} catch (const std::exception &e) {
// 		std::cerr << RED << "✖️ " << bureaucrat.getName()
// 				  << " couldn't execute " << form.getName() << " because " << e.what() << RESET << std::endl;
// 	}
// }

void testExecuteForm(Bureaucrat &bureaucrat, AForm &form) {
	std::cout	<< PURPLE << "\n📌 " << bureaucrat.getName()
				<< " attempts to execute " << form.getName()
				<< " (Required: " << form.getGradeToExecute()
				<< ", Bureaucrat's grade: " << bureaucrat.getGrade() << ")" << RESET << std::endl;
    try {
        bureaucrat.executeForm(form);
    } catch (const std::exception &e) {
        std::cerr << RED << "✖️ " << bureaucrat.getName() << " couldn't execute " << form.getName() << " because " << e.what() << RESET << std::endl;
        return;
	}
}

int main() {
	std::srand(static_cast<unsigned>(std::time(0))); // Инициализация srand

	std::cout << BOLD INVERSE << "\n\t=== Running All Tests ===\n" << RESET << std::endl;

	// Создаем бюрократов
	Bureaucrat *intern = NULL;
	Bureaucrat *manager = NULL;
	Bureaucrat *director = NULL;

	createTestBureaucrat(intern, "Trainee", 150);
	createTestBureaucrat(manager, "Manager", 50);
	createTestBureaucrat(director, "Director", 1);

	std::cout << BLUE << "\n📌 Bureaucrats created:" << RESET << std::endl;
	if (intern) std::cout << "🔹 " << *intern << std::endl;
	if (manager) std::cout << "🔹 " << *manager << std::endl;
	if (director) std::cout << "🔹 " << *director << std::endl;

	// Создаем формы
	AForm *shrubbery = NULL;
	AForm *robotomy = NULL;
	AForm *pardon = NULL;
	AForm *emptyTarget = NULL;

	std::cout << CYAN INVERSE << "\n\t=== Testing Forms Creation ===\n" << RESET << std::endl;
	createTestForm(shrubbery, "Shrubbery", "Office Yard");
	// createTestForm(shrubbery, "Shrubbery", "");
	createTestForm(robotomy, "Robotomy", "Failed Employee");
	// createTestForm(robotomy, "Robotomy", "");
	createTestForm(pardon, "Pardon", "Convicted CEO");
	// createTestForm(emptyTarget, "Pardon", ""); // Должна вызвать исключение

	std::cout << YELLOW INVERSE << "\n\t=== Testing Signing Forms ===\n" << RESET << std::endl;
	std::cout << "intern" << std::endl;
	if (intern) {
		if (shrubbery) testSignForm(*intern, *shrubbery);
		if (robotomy) testSignForm(*intern, *robotomy);
		if (pardon) testSignForm(*intern, *pardon);
	}
	std::cout << "manager" << std::endl;
	if (manager) {
		if (shrubbery) testSignForm(*manager, *shrubbery);
		if (robotomy) testSignForm(*manager, *robotomy);
		if (pardon) testSignForm(*manager, *pardon);
	}
	std::cout << "director" << std::endl;
	if (director) {
		if (shrubbery) testSignForm(*director, *shrubbery);
		if (robotomy) testSignForm(*director, *robotomy);
		if (pardon) testSignForm(*director, *pardon);
	}

	std::cout << YELLOW << "\n📌 Forms status after signing:" << RESET << std::endl;
	if (shrubbery) std::cout << "📄 " << *shrubbery << std::endl;
	if (robotomy) std::cout << "📄 " << *robotomy << std::endl;
	if (pardon) std::cout << "📄 " << *pardon << std::endl;

	std::cout << PURPLE INVERSE << "\n\t=== Testing Executing Forms ===\n" << RESET << std::endl;
	std::cout << "intern" << std::endl;
	if (intern) {
		if (shrubbery) testExecuteForm(*intern, *shrubbery);
		if (robotomy) testExecuteForm(*intern, *robotomy);
		if (pardon) testExecuteForm(*intern, *pardon);
	}
	std::cout << "manager" << std::endl;
	if (manager) {
		if (shrubbery) testExecuteForm(*manager, *shrubbery);
		if (robotomy) testExecuteForm(*manager, *robotomy);
		if (pardon) testExecuteForm(*manager, *pardon);
	}
	std::cout << "director" << std::endl;
	if (director) {
		if (shrubbery) testExecuteForm(*director, *shrubbery);
		if (robotomy) testExecuteForm(*director, *robotomy);
		if (pardon) testExecuteForm(*director, *pardon);
	}

	std::cout << CYAN INVERSE << "\n\t🛠 Testing Randomness of RobotomyRequestForm\n" << RESET << std::endl;
	for (int i = 0; i < 5; ++i) {
		if (director && robotomy) testExecuteForm(*director, *robotomy);
	}

	std::cout << GREEN INVERSE << "\n✅ All Tests Completed!\n" << RESET << std::endl;

	// Чистим память
	delete intern;
	delete manager;
	delete director;
	delete shrubbery;
	delete robotomy;
	delete pardon;
	delete emptyTarget;

	return 0;
}




// test 03
// // Функция для создания форм с обработкой исключений
// void createTestForm(AForm *&form, const std::string &type, const std::string &target) {
//     std::cout << "📌 Creating form: " << type << " (Target: " << target << ")" << std::endl;
//     try {
//         if (type == "Shrubbery") form = new ShrubberyCreationForm(target);
//         else if (type == "Robotomy") form = new RobotomyRequestForm(target);
//         else if (type == "Pardon") form = new PresidentialPardonForm(target);
//         std::cout << "✅ Successfully created: " << *form << std::endl;
//     } catch (const std::exception &e) {
//         std::cerr << "⛔ Exception: " << e.what() << std::endl;
//     }
// }

// // Тест подписания формы
// void testSignForm(Bureaucrat &bureaucrat, AForm &form) {
//     std::cout << "\n📌 " << bureaucrat.getName() << " attempts to sign " << form.getName()
//               << " (Required: " << form.getGradeToSign() << ", Bureaucrat's grade: " << bureaucrat.getGrade() << ")" << std::endl;
//     try {
//         bureaucrat.signForm(form);
//         std::cout << "✔️ " << bureaucrat.getName() << " signed " << form.getName() << "!" << std::endl;
//     } catch (const std::exception &e) {
//         std::cerr << "✖️ " << bureaucrat.getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
//     }
// }

// // Тест выполнения формы
// void testExecuteForm(Bureaucrat &bureaucrat, AForm &form) {
//     std::cout << "\n📌 " << bureaucrat.getName() << " attempts to execute " << form.getName()
//               << " (Required: " << form.getGradeToExecute() << ", Bureaucrat's grade: " << bureaucrat.getGrade() << ")" << std::endl;
//     try {
//         bureaucrat.executeForm(form);
//         std::cout << "✔️ " << bureaucrat.getName() << " executed " << form.getName() << std::endl;
//     } catch (const std::exception &e) {
//         std::cerr << "✖️ " << bureaucrat.getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
//     }
// }

// int main() {
//     std::srand(static_cast<unsigned>(std::time(0))); // Инициализация srand

//     std::cout << "\n=== Running All Tests ===\n" << std::endl;

//     // Создаем бюрократов
//     Bureaucrat *intern = NULL;
//     Bureaucrat *manager = NULL;
//     Bureaucrat *president = NULL;

//     try { intern = new Bureaucrat("Intern", 150); }
//     catch (const std::exception &e) { std::cerr << "⛔ Intern creation failed: " << e.what() << std::endl; }
    
//     try { manager = new Bureaucrat("Manager", 50); }
//     catch (const std::exception &e) { std::cerr << "⛔ Manager creation failed: " << e.what() << std::endl; }
    
//     try { president = new Bureaucrat("President", 1); }
//     catch (const std::exception &e) { std::cerr << "⛔ President creation failed: " << e.what() << std::endl; }

//     std::cout << "\n📌 Bureaucrats created:" << std::endl;
//     if (intern) std::cout << "🔹 " << *intern << std::endl;
//     if (manager) std::cout << "🔹 " << *manager << std::endl;
//     if (president) std::cout << "🔹 " << *president << std::endl;

//     // Создаем формы
//     AForm *shrubbery = NULL;
//     AForm *robotomy = NULL;
//     AForm *pardon = NULL;
//     AForm *emptyTarget = NULL;

//     std::cout << "\n=== Testing Forms ===\n" << std::endl;

//     createTestForm(shrubbery, "Shrubbery", "Garden");
//     createTestForm(robotomy, "Robotomy", "TestSubject");
//     createTestForm(pardon, "Pardon", "Alice");
//     createTestForm(emptyTarget, "Pardon", ""); // Должна вызвать исключение

//     std::cout << "\n=== Testing Signing Forms ===\n" << std::endl;

//     if (intern && shrubbery) testSignForm(*intern, *shrubbery);
//     if (manager && robotomy) testSignForm(*manager, *robotomy);
//     if (president && pardon) testSignForm(*president, *pardon);

//     std::cout << "\n📌 Forms status after signing:" << std::endl;
//     if (shrubbery) std::cout << "📄 " << *shrubbery << std::endl;
//     if (robotomy) std::cout << "📄 " << *robotomy << std::endl;
//     if (pardon) std::cout << "📄 " << *pardon << std::endl;

//     std::cout << "\n=== Testing Executing Forms ===\n" << std::endl;

//     if (intern && shrubbery) testExecuteForm(*intern, *shrubbery);
//     if (manager && robotomy) testExecuteForm(*manager, *robotomy);
//     if (president && pardon) testExecuteForm(*president, *pardon);

//     std::cout << "\n🛠 Testing Randomness of RobotomyRequestForm\n" << std::endl;
//     for (int i = 0; i < 5; ++i) {
//         if (manager && robotomy) testExecuteForm(*manager, *robotomy);
//     }

//     std::cout << "\n✅ All Tests Completed!\n" << std::endl;

//     // Чистим память
//     delete intern;
//     delete manager;
//     delete president;
//     delete shrubbery;
//     delete robotomy;
//     delete pardon;
//     delete emptyTarget;

//     return 0;
// }


// test 02
// void createTestForm(const std::string& name) {
//     std::cout << CYAN << "\n📌 Creating form: " << name << RESET << std::endl;
//     try {
//         if (name == "Shrubbery") ShrubberyCreationForm form("Garden");
//         else if (name == "Robotomy") RobotomyRequestForm form("Target");
//         else if (name == "Pardon") PresidentialPardonForm form("Alice");
//         else if (name == "EmptyTarget") PresidentialPardonForm form("");
//         std::cout << GREEN << "✅ Successfully created " << name << RESET << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << RED << "⛔ Exception: " << e.what() << RESET << std::endl;
//     }
// }

// void testSigningExecution(Bureaucrat& bureaucrat, AForm& form) {
//     std::cout << BLUE << "\n📌 " << bureaucrat.getName() << " attempts to sign " << form.getName() << RESET << std::endl;
//     bureaucrat.signForm(form);
    
//     std::cout << BLUE << "\n📌 " << bureaucrat.getName() << " attempts to execute " << form.getName() << RESET << std::endl;
//     bureaucrat.executeForm(form);
// }

// void testCopyAndAssignment() {
//     std::cout << CYAN << "\n🛠 Testing Copy and Assignment" << RESET << std::endl;
//     try {
//         RobotomyRequestForm original("OriginalTarget");
//         RobotomyRequestForm copy(original);
//         RobotomyRequestForm assigned = original;
//         std::cout << GREEN << "✅ Copy and Assignment Passed" << RESET << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << RED << "⛔ Exception: " << e.what() << RESET << std::endl;
//     }
// }

// void testRobotomyRandomness() {
//     std::cout << CYAN << "\n🛠 Testing Randomness of RobotomyRequestForm" << RESET << std::endl;
//     RobotomyRequestForm robotForm("TestSubject");
//     Bureaucrat doctor("Doctor", 1);
//     doctor.signForm(robotForm);
//     for (int i = 0; i < 5; ++i) {
//         doctor.executeForm(robotForm);
//     }
// }

// int main() {
//     std::srand(static_cast<unsigned>(std::time(0)));
//     std::cout << BOLD << "\n=== Running All Tests ===\n" << RESET << std::endl;

//     // Проверка создания форм
//     createTestForm("Shrubbery");
//     createTestForm("Robotomy");
//     createTestForm("Pardon");
//     createTestForm("EmptyTarget");

//     // Создание бюрократов
//     Bureaucrat intern("Intern", 150);
//     Bureaucrat manager("Manager", 50);
//     Bureaucrat president("President", 1);
    
//     // Создание форм
//     ShrubberyCreationForm shrubForm("Garden");
//     RobotomyRequestForm robotForm("CEO");
//     PresidentialPardonForm pardonForm("Alice");
    
//     // Проверка подписания и выполнения
//     testSigningExecution(intern, shrubForm);
//     testSigningExecution(manager, robotForm);
//     testSigningExecution(president, pardonForm);
    
//     // Проверка копирования и присваивания
//     testCopyAndAssignment();

//     // Проверка рандома Robotomy
//     testRobotomyRandomness();

//     std::cout << BOLD << "\n✅ All Tests Completed!" << RESET << std::endl;
//     return 0;
// }

// test 01
// void createTestBureaucrat(const std::string &name, int grade) {
//     std::cout << YELLOW << "\n📌 Creating Bureaucrat: " << name << " (grade " << grade << ")" << RESET << std::endl;
//     try {
//         Bureaucrat bureaucrat(name, grade);
//         std::cout << GREEN << "✅ Successfully created: " << RESET << bureaucrat << std::endl;
//     } catch (const std::exception &e) {
//         std::cerr << RED << "⛔ Exception: " << e.what() << RESET << std::endl;
//     }
// }

// void createTestForm(AForm &form) {
//     std::cout << CYAN << "\n📌 Creating Form: " << form.getName() << " (Sign " << form.getGradeToSign()
//               << ", Execute " << form.getGradeToExecute() << ")" << RESET << std::endl;
//     std::cout << GREEN << "✅ Successfully created: " << RESET << form << std::endl;
// }

// void testSignForm(Bureaucrat &bureaucrat, AForm &form) {
//     std::cout << BLUE << "\n📌 " << bureaucrat.getName() << " attempts to sign " << form.getName() << RESET << std::endl;
//     bureaucrat.signForm(form);
// }

// void testExecuteForm(Bureaucrat &bureaucrat, AForm &form) {
//     std::cout << BLUE << "\n📌 " << bureaucrat.getName() << " attempts to execute " << form.getName() << RESET << std::endl;
//     bureaucrat.executeForm(form);
// }

// void testCopyAndAssignment() {
//     std::cout << CYAN << "\n🛠 Testing Copy and Assignment" << RESET << std::endl;

//     Bureaucrat original("Original", 42);
//     Bureaucrat copy(original);
//     Bureaucrat assigned = original;

//     std::cout << GREEN << "✅ Original: " << RESET << original << std::endl;
//     std::cout << GREEN << "✅ Copy: " << RESET << copy << std::endl;
//     std::cout << GREEN << "✅ Assigned: " << RESET << assigned << std::endl;

//     ShrubberyCreationForm formOriginal("Garden");
//     ShrubberyCreationForm formCopy(formOriginal);
//     ShrubberyCreationForm formAssigned = formOriginal;

//     std::cout << GREEN << "✅ Original Form: " << RESET << formOriginal << std::endl;
//     std::cout << GREEN << "✅ Copy Form: " << RESET << formCopy << std::endl;
//     std::cout << GREEN << "✅ Assigned Form: " << RESET << formAssigned << std::endl;
// }

// void testRobotomyRandomness() {
//     std::cout << CYAN << "\n🛠 Testing Randomness of RobotomyRequestForm" << RESET << std::endl;

//     RobotomyRequestForm robotForm("TestSubject");
//     Bureaucrat doctor("Doctor", 1);

//     doctor.signForm(robotForm);

//     std::cout << "🔄 Running multiple robotomy attempts:\n";
//     for (int i = 0; i < 5; i++) {
//         std::cout << "⚙ Attempt " << i + 1 << ": ";
//         doctor.executeForm(robotForm);
//     }
// }

// int main() {
//     std::srand(static_cast<unsigned>(std::time(0))); // Seed random number generator

//     std::cout << CYAN << "\n=== Testing Bureaucrats ===" << RESET << std::endl;
//     createTestBureaucrat("Director", 1);
//     createTestBureaucrat("Intern", 150);
//     createTestBureaucrat("Invalid Low", 0);
//     createTestBureaucrat("Invalid High", 151);

//     std::cout << CYAN << "\n=== Testing Forms ===" << RESET << std::endl;
// 	// std::cout << RED << "\n📌 Attempting to create invalid forms" << RESET << std::endl;
// 	// try {
// 	// 	ShrubberyCreationForm invalidForm("Invalid", 0, 150);
// 	// } catch (const std::exception &e) {
// 	// 	std::cerr << RED << "⛔ Exception: " << e.what() << RESET << std::endl;
// 	// }

// 	// try {
// 	// 	RobotomyRequestForm invalidForm("Invalid", 200, 10);
// 	// } catch (const std::exception &e) {
// 	// 	std::cerr << RED << "⛔ Exception: " << e.what() << RESET << std::endl;
// 	// }

// 	// std::cout << GREEN << "\n📌 Attempting to create valid forms" << RESET << std::endl;
//     ShrubberyCreationForm shrubForm("Park");
//     RobotomyRequestForm robotForm("AI Bot");
//     PresidentialPardonForm pardonForm("Prisoner");

//     createTestForm(shrubForm);
//     createTestForm(robotForm);
//     createTestForm(pardonForm);

//     Bureaucrat lowBureaucrat("Low Bureaucrat", 140);
//     Bureaucrat midBureaucrat("Mid Bureaucrat", 50);
//     Bureaucrat highBureaucrat("High Bureaucrat", 1);

//     std::cout << CYAN << "\n=== Testing Signing and Execution ===" << RESET << std::endl;
    
//     // Low-level bureaucrat cannot sign or execute
//     testSignForm(lowBureaucrat, shrubForm);
//     testExecuteForm(lowBureaucrat, shrubForm);

//     // Mid-level bureaucrat signs but cannot execute
//     testSignForm(midBureaucrat, robotForm);
//     testExecuteForm(midBureaucrat, robotForm);

//     // High-level bureaucrat signs and executes
//     testSignForm(highBureaucrat, pardonForm);
//     testExecuteForm(highBureaucrat, pardonForm);

//     std::cout << CYAN << "\n=== Testing Copy and Assignment ===" << RESET << std::endl;
//     testCopyAndAssignment();

//     std::cout << CYAN << "\n=== Testing Randomness of Robotomy ===" << RESET << std::endl;
//     testRobotomyRandomness();

//     std::cout << GREEN << "\n✅ All Tests Completed!" << RESET << std::endl;
//     return 0;
// }
