/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:22:31 by algultse          #+#    #+#             */
/*   Updated: 2025/02/25 20:30:01 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

PresidentialPardonForm::PresidentialPardonForm()
					: AForm("PresidentialPardonForm", gradeToSign, gradeToExecute),
							_target("default_target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
					: AForm("PresidentialPardonForm", gradeToSign, gradeToExecute),
							_target(target) {
	if (target.empty())
		throw TargetEmptyException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
					: AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form) {
	return (str << form.getName()
				<< " form, signed: " << form.getIsSigned()
				<< ", sign grade: " << form.getGradeToSign()
				<< ", exec grade: " << form.getGradeToExecute());
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	PresidentialPardonForm::action() const {
	std::cout << "🏛️  Informs that " << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            EXCEPTION MESSAGES                              */
/* -------------------------------------------------------------------------- */

const char	*PresidentialPardonForm::TargetEmptyException::what() const throw() {
	return (UNDERLINE GREEN "❌ Target name is empty!" RESET);
}
