/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:22:09 by algultse          #+#    #+#             */
/*   Updated: 2025/02/25 20:20:06 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm()
					: AForm("RobotomyRequestForm", gradeToSign, gradeToExecute),
							_target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
					: AForm("RobotomyRequestForm", gradeToSign, gradeToExecute),
							_target(target) {
	if (target.empty())
		throw TargetEmptyException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
					: AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form) {
	return (str << form.getName()
				<< " form, signed: " << form.getIsSigned()
				<< ", sign grade: " << form.getGradeToSign()
				<< ", exec grade: " << form.getGradeToExecute());
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	RobotomyRequestForm::action() const {
	std::cout << "🤖 Drilling noises... ";
	if (rand() % 2) {
		std::cout << _target << " has been successfully robotomized!" << std::endl;
	} else {
		std::cerr << "❌ Robotomy failed for " << _target << "..." << std::endl;
	}
}

/* -------------------------------------------------------------------------- */
/*                            EXCEPTION MESSAGES                              */
/* -------------------------------------------------------------------------- */

const char	*RobotomyRequestForm::TargetEmptyException::what() const throw() {
	return (UNDERLINE BLUE "❌ Target name is empty!" RESET);
}
