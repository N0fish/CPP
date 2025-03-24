/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:59:44 by algultse          #+#    #+#             */
/*   Updated: 2025/03/24 20:01:07 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _result(0) {}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->_stack = other._stack;
		this->_result = other._result;
	}
	return (*this);
}

RPN::~RPN() {}

int	RPN::getResult() const {
	return (this->_result);
}

bool	RPN::isOperator(char token) const {
	return (token == '+' || token == '-' || token == '*' || token == '/');
}

int	RPN::performOperation(char op, int a, int b) {
	switch (op) {
		case '+': 
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw DivisionByZeroException();
			return (a / b);
		default:
			throw InvalidExpressionException();
	}
}

void	RPN::applyOperator(char op) {
	if (_stack.size() < 2) {
		throw NotEnoughOperandsException();
	}

	int b = _stack.top();
	_stack.pop();
	int a = _stack.top();
	_stack.pop();

	// std::cerr << "DEBUG: " << a << " " << op << " " << b << std::endl;

	if (op == '/' && b == 0) {
		throw DivisionByZeroException();
	}
	_stack.push(performOperation(op, a, b));
}

void	RPN::processExpression(const std::string& expr) {
	if (expr.empty()) {
		throw InvalidExpressionException();
	}

	std::istringstream	iss(expr);
	std::string			token;

	while (iss >> token) {
		if (token.length() == 1 && std::isdigit(token[0])) {
			_stack.push(token[0] - '0');
		}
		else if (token.length() == 1 && isOperator(token[0])) {
			applyOperator(token[0]);
		}
		else {
			throw InvalidExpressionException();
		}
	}
	if (_stack.size() > 1) {
		throw TooManyOperandsException();
	}
	_result = _stack.top();
}

const char*	RPN::InvalidExpressionException::what() const throw() {
	return ("✖️ Error: Invalid expression");
}

const char*	RPN::NotEnoughOperandsException::what() const throw() {
	return ("✖️ Error: Not enough operands");
}

const char*	RPN::TooManyOperandsException::what() const throw() {
	return ("✖️ Error: Too many operands");
}

const char*	RPN::DivisionByZeroException::what() const throw() {
	return ("✖️ Error: Division by zero");
}
