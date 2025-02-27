/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:10:45 by algultse          #+#    #+#             */
/*   Updated: 2025/02/26 00:30:32 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern::~Intern() {}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Intern	&Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

AForm*	Intern::makeForm(const std::string &formName, const std::string &target) {
	static formList formTypes[3] = {
		{"shrubbery creation", &ShrubberyCreationForm::create},
		{"robotomy request", &RobotomyRequestForm::create},
		{"presidential pardon", &PresidentialPardonForm::create}
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formTypes[i]._name) {
			std::cout << "Intern creates " << formName << std::endl;
			return (formTypes[i].create(target));
		}
	}

	throw InvalidFormName();
}

/* -------------------------------------------------------------------------- */
/*                            EXCEPTION MESSAGES                              */
/* -------------------------------------------------------------------------- */

const char	*Intern::InvalidFormName::what(void) const throw() {
	return (UNDERLINE GREEN "❌ Invalid form name" RESET);
}
