/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:12:49 by algultse          #+#    #+#             */
/*   Updated: 2025/02/25 17:52:08 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	private:
		std::string	_target;

	protected:
		void	action() const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		
		static int const	gradeToSign = 72;
		static int const	gradeToExecute = 45;

		class TargetEmptyException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form);

#endif