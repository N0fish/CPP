/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:40:42 by algultse          #+#    #+#             */
/*   Updated: 2025/02/22 16:29:16 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	checkGrade(grade);
	_grade = grade;
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
	out	<< DIM << obj.getName() << RESET
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
	if (gradeValue < HIGHEST_GRADE) {
		throw GradeTooHighException();
	}
	if (gradeValue > LOWEST_GRADE) {
		throw GradeTooLowException();
	}
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	Bureaucrat::incrementGrade() {
	checkGrade(_grade - 1);
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	checkGrade(_grade + 1);
	_grade++;
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout	<< _name
					<< " signed "
					<< form.getName() <<  " ✔️"
					<< std::endl;
	} catch (const std::exception &e) {
		std::cerr	<< _name
					<< " couldn't sign " << form.getName()
					<< " because " << e.what() <<  " ✖️"
					<< std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout	<< _name
					<< " executed " << form.getName()
					<< std::endl;
	} catch (const std::exception &e) {
		std::cerr	<< _name
					<< " couldn't execute " << form.getName()
					<< " because " << e.what()
					<< std::endl;
	}
}

/* -------------------------------------------------------------------------- */
/*                            EXCEPTION MESSAGES                              */
/* -------------------------------------------------------------------------- */

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return (UNDERLINE PURPLE "grade is too high!" RESET " Must be between 1 and 150.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return (UNDERLINE PURPLE "grade is too low!" RESET " Must be between 1 and 150.");
}
