/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:40:42 by algultse          #+#    #+#             */
/*   Updated: 2025/01/23 17:30:16 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name),
															_grade(grade) {
	checkGrade(_grade);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :	_name(other._name),
													_grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */


Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &obj) {
	out	<< WHITE_BACKGROUND
		<< obj.getName() << RESET
		<< ", bureaucrat grade "
		<< WHITE_BACKGROUND
		<< obj.getGrade() << RESET
		<< ".";
	return (out);
}

/* -------------------------------------------------------------------------- */
/*                             GETTERS and SETTERS                            */
/* -------------------------------------------------------------------------- */

const std::string	&Bureaucrat::getName(void) const {
	return (_name);
}

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

/* -------------------------------------------------------------------------- */
/*                             PRIVATE FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	Bureaucrat::checkGrade(int gradeValue) const {
	if (gradeValue < HIGHTEST_GRADE) {
		throw GradeTooHighException();
	}
	if (gradeValue > LOWEST_GRADE) {
		throw GradeTooLowException();
	}
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return (UNDERLINE PURPLE "Grade is too high!" RESET " Must be between 1 and 150.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return (UNDERLINE PURPLE "Grade is too low!" RESET " Must be between 1 and 150.");
}

void	Bureaucrat::incrementGrade() {
	checkGrade(_grade - 1);
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	checkGrade(_grade + 1);
	_grade++;
}
