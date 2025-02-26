/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:02:21 by algultse          #+#    #+#             */
/*   Updated: 2025/02/22 19:49:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;
	
	protected:
		void	action() const;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		static int const	gradeToSign = 145;
		static int const	gradeToExecute = 137;

		class FileOpenException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class TargetEmptyException : public std::exception {
			public:
				virtual const char* what() const throw();
			};			
};

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form);

#endif