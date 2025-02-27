/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:04:40 by algultse          #+#    #+#             */
/*   Updated: 2025/02/27 00:50:23 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		typedef struct FormType {
			std::string _name;
			AForm* (*create)(const std::string&);
		}				formList;;

	public:
		Intern();
		Intern(Intern const &other);
		~Intern();

		Intern	&operator=(Intern const &other);

		AForm	*makeForm(const std::string& formName, const std::string& target);

		class InvalidFormName : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
};

#endif