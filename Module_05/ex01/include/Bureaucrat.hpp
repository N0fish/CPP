/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:33:24 by algultse          #+#    #+#             */
/*   Updated: 2025/01/23 14:25:08 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include <cstdlib>
# include "Colors.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

		void	checkGrade(int gradeValue) const;
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat&	operator=(const Bureaucrat& other);

		const std::string	&getName(void) const;
		int					getGrade(void) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void	incrementGrade();
		void	decrementGrade();

		void	signForm(Form &form);
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &obj);

#endif