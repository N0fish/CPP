/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:52:03 by algultse          #+#    #+#             */
/*   Updated: 2025/02/26 17:58:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

AForm::AForm() :	_name("Default"),
				_isSigned(false),
				_gradeToSign(LOWEST_GRADE),
				_gradeToExecute(LOWEST_GRADE) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) 
				:	_name(name),
					_isSigned(false),
					_gradeToSign(checkGrade(gradeToSign)),
					_gradeToExecute(checkGrade(gradeToExecute)) {}

AForm::AForm(const AForm& other) 
				:	_name(other._name),
					_isSigned(false), 
					_gradeToSign(other._gradeToSign),
					_gradeToExecute(other._gradeToExecute) {}


AForm::~AForm() {}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = false;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const AForm& form) {
	out	<< "Form: " DIM << form.getName() << RESET
		<< ", Signed: " DIM << (form.getIsSigned() ? "Yes" : "No") << RESET
		<< ", Required Grade to Sign: " << WHITE_BACKGROUND << form.getGradeToSign() << RESET
		<< ", Required Grade to Execute: " << WHITE_BACKGROUND << form.getGradeToExecute() << RESET;
	return (out);
}

/* -------------------------------------------------------------------------- */
/*                             GETTERS and SETTERS                            */
/* -------------------------------------------------------------------------- */

const std::string&	AForm::getName() const {
	return (_name);
}

bool	AForm::getIsSigned() const {
	return (_isSigned);
}

int	AForm::getGradeToSign() const {
	return (_gradeToSign);
}
int	AForm::getGradeToExecute() const {
	return (_gradeToExecute);
}

/* -------------------------------------------------------------------------- */
/*                             PRIVATE FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

int	AForm::checkGrade(int grade) const {
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	return (grade);
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	// if (_isSigned) {
	// 	throw AlreadySignedException();
	// }
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const {
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();

	this->action();
}

/* -------------------------------------------------------------------------- */
/*                            EXCEPTION MESSAGES                              */
/* -------------------------------------------------------------------------- */

const char	*AForm::GradeTooHighException::what() const throw() {
	return (UNDERLINE YELLOW "grade is too high!" RESET);
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return (UNDERLINE YELLOW "grade is too low!" RESET);
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return (UNDERLINE RED "form is not signed!" RESET);
}

// const char* AForm::AlreadySignedException::what() const throw() {
// 	return (UNDERLINE GREEN "form is already signed!" RESET);
// }
