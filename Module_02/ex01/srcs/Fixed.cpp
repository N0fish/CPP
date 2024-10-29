/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:52:30 by algultse          #+#    #+#             */
/*   Updated: 2024/10/24 22:01:52 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) {
	std::cout	<< PURPLE "Default"
				BLACK " constructor called" RESET
				<< std::endl;
	return ;
}

Fixed::Fixed( int const n ) : _value(n << _fractionalBits) {
	std::cout	<< BOLD "Int" RESET
				BLACK " constructor called" RESET
				<< std::endl;
	return ;
}

Fixed::Fixed( float const n ) : _value(roundf(n * (1 << _fractionalBits))) {
	std::cout	<< BOLD "Float" RESET
				BLACK " constructor called" RESET
				<< std::endl;
	return ;
}

Fixed::Fixed( const Fixed &other ) {
	std::cout	<< YELLOW "Copy constructor"
					BLACK " called" RESET
				<< std::endl;
	*this = other;
	return ;
}

Fixed::~Fixed() {
	std::cout	<< BLUE "Destructor called" RESET 
				<< std::endl;
	return ;
}

Fixed	&Fixed::operator=( const Fixed &rhs ) {
	std::cout	<< YELLOW "Copy assignment operator"
					BLACK " called." RESET
				<< std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (
		(float)this->_value / (1 << _fractionalBits)
	);
}

int	Fixed::toInt( void ) const {
	return (
		this->_value >> _fractionalBits
	);
}

std::ostream&	operator<<( std::ostream& out, const Fixed& number )
{
	out << number.toFloat();
	return ( out );
}
