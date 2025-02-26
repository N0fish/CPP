/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:12:49 by algultse          #+#    #+#             */
/*   Updated: 2025/02/25 17:52:08 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;

	protected:
		void	action() const;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		std::string	&getTarget(void);
		
		static int const	gradeToSign = 25;
		static int const	gradeToExecute = 5;

		class TargetEmptyException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form);

#endif