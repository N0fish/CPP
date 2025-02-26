/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:50:32 by algultse          #+#    #+#             */
/*   Updated: 2025/02/20 17:59:45 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Colors.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		int	checkGrade(int grade) const;

	protected:
		virtual void action() const = 0;

	public:
		AForm();
		AForm(const AForm &other);
		AForm(const std::string	&name, const int gradeToSign, const int gradeToExecute);
		virtual ~AForm();

		AForm&	operator=(const AForm& other);

		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		// class AlreadySignedException : public std::exception {
		// 	public:
		// 		virtual const char* what() const throw();
		// 	};	
		
		virtual void execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& out, const AForm& form);

#endif