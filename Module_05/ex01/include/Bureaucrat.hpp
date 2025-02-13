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

# define HIGHTEST_GRADE 1
# define LOWEST_GRADE 150

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

		// Exceptions|nested class
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		// Member
		void	incrementGrade();
		void	decrementGrade();
};

// Overload outstream operator
std::ostream&	operator<<(std::ostream &out, const Bureaucrat &obj);

#endif