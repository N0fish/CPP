/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:50:32 by algultse          #+#    #+#             */
/*   Updated: 2025/01/24 01:42:45 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		
	public:
		Form();
		Form(const std::string	&name, bool isSigned, const int gradeToSign, const int gradeToExecute);
		Form(const Form &other);
		~Form();

		Form&	operator=(const Form& other);

		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		const int			getGradeToSign(void) const;
		const int			getGradeToExecute(void) const;

};

#endif