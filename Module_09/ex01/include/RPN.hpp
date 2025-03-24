/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:57:05 by algultse          #+#    #+#             */
/*   Updated: 2025/03/24 19:49:33 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_POLISH_NOTATION_HPP
# define REVERSE_POLISH_NOTATION_HPP

# include "Colors.hpp"

class RPN {
	private:
		std::stack<int>	_stack;
		int				_result;

		bool	isOperator(char token) const;
		int		performOperation(char op, int a, int b);
		void	applyOperator(char op);

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int		getResult() const;
		void	processExpression(const std::string& expr);

		class InvalidExpressionException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
			
		class NotEnoughOperandsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class TooManyOperandsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class DivisionByZeroException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
