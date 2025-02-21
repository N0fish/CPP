/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:52:03 by algultse          #+#    #+#             */
/*   Updated: 2025/02/20 17:58:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Form::Form() :	_name("Default"),
				_isSigned(false),
				_gradeToSign(LOWEST_GRADE),
				_gradeToExecute(LOWEST_GRADE) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) 
				:	_name(name),
					_isSigned(false),
					_gradeToSign(checkGrade(gradeToSign)),
					_gradeToExecute(checkGrade(gradeToExecute)) {}

Form::Form(const Form& other) 
				:	_name(other._name),
					_isSigned(other._isSigned), 
					_gradeToSign(other._gradeToSign),
					_gradeToExecute(other._gradeToExecute) {}


Form::~Form() {}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Form&	Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Form& form) {
	out	<< "Form: " << form.getName()
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Required Grade to Sign: " << WHITE_BACKGROUND << form.getGradeToSign() << RESET
		<< ", Required Grade to Execute: " << WHITE_BACKGROUND << form.getGradeToExecute() << RESET;
	return (out);
}

/* -------------------------------------------------------------------------- */
/*                             GETTERS and SETTERS                            */
/* -------------------------------------------------------------------------- */

const std::string&	Form::getName() const {
	return (_name);
}

bool	Form::getIsSigned() const {
	return (_isSigned);
}

int	Form::getGradeToSign() const {
	return (_gradeToSign);
}
int	Form::getGradeToExecute() const {
	return (_gradeToExecute);
}

/* -------------------------------------------------------------------------- */
/*                             PRIVATE FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

int Form::checkGrade(int grade) const {
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	return (grade);
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

/* -------------------------------------------------------------------------- */
/*                            EXCEPTION MESSAGES                              */
/* -------------------------------------------------------------------------- */

const char* Form::GradeTooHighException::what() const throw() {
	return (UNDERLINE YELLOW "Grade is too high!" RESET);
}

const char* Form::GradeTooLowException::what() const throw() {
	return (UNDERLINE YELLOW "Grade is too low!" RESET);
}
