/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:07:29 by algultse          #+#    #+#             */
/*   Updated: 2025/02/23 20:11:32 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm()
					: AForm("ShrubberyCreationForm", gradeToSign, gradeToExecute),
							_target("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
					: AForm("ShrubberyCreationForm", gradeToSign, gradeToExecute),
							_target(target) {
	if (target.empty())
		throw TargetEmptyException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
					: AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form) {
	return (str << form.getName()
				<< " form, signed: " << form.getIsSigned()
				<< ", sign grade: " << form.getGradeToSign()
				<< ", exec grade: " << form.getGradeToExecute());
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void ShrubberyCreationForm::action() const {
	std::ofstream outfile(this->_target + "_shrubbery");

	if (_target.empty())
		throw TargetEmptyException();

	if (!outfile.is_open())
		throw FileOpenException();

	outfile << "       &&& &&  & &&\n";
	outfile << "   && &\\/&\\|& ()|/ @, &&\n";
	outfile << "   &\\/(/&/&||/& /_/)_&/_&\n";
	outfile << " &() &\\/&|()|/&\\/ '%\" & ()\n";
	outfile << " &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	outfile << "&&   && & &| &| /& & % ()& /&&\n";
	outfile << " ()&_---()&\\&\\|&&-&&--%---()~\n";
	outfile << "     &&    ( ͡° ͜ʖ ͡°)    &&\n";
	outfile << "     &&     \\|||\n";
	outfile << "             |||\n";
	outfile << "             |||\n";
	outfile << "             |||\n";
	outfile << "       , -=-~  .-^- _\n";
	outfile.close();
 
	std::cout << "✅ File created: " << this->_target << "_shrubbery" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            EXCEPTION MESSAGES                              */
/* -------------------------------------------------------------------------- */

const char	*ShrubberyCreationForm::FileOpenException::what() const throw() {
	return (UNDERLINE PURPLE "❌ Failed to open file!" RESET);
}

const char	*ShrubberyCreationForm::TargetEmptyException::what() const throw() {
	return (UNDERLINE PURPLE "❌ Target name is empty!" RESET);
}
