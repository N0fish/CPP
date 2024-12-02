/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:10:46 by algultse          #+#    #+#             */
/*   Updated: 2024/10/24 22:12:07 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

/* -------------------------------------------------------------------------- */
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/* -------------------------------------------------------------------------- */

Fixed::Fixed() : _value(0) {
	return ;
}

Fixed::Fixed( int const n ) : _value(n << _fractionalBits) {
	return ;
}

Fixed::Fixed( float const n ) : _value(roundf(n * (1 << _fractionalBits))) {
	return ;
}

Fixed::Fixed( const Fixed &other ) {
	*this = other;
	return ;
}

Fixed::~Fixed() {
	return ;
}

/* -------------------------------------------------------------------------- */
/*                                 OPERATORS                                  */
/* -------------------------------------------------------------------------- */

Fixed	&Fixed::operator=( const Fixed &rhs ) {
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &rhs) const {
	return (this->_value > rhs._value);
}

bool	Fixed::operator<(const Fixed &rhs) const {
	return (this->_value < rhs._value);
}

bool	Fixed::operator>=( const Fixed &rhs ) const {
	return (this->_value >= rhs._value);
}

bool	Fixed::operator<=( const Fixed &rhs ) const {
	return (this->_value <= rhs._value);
}

bool	Fixed::operator==( const Fixed &rhs ) const {
	return (this->_value == rhs._value);
}

bool	Fixed::operator!=( const Fixed &rhs ) const {
	return (this->_value != rhs._value);
}

/* -------------------------------------------------------------------------- */

Fixed	Fixed::operator+( Fixed const &rhs ) const {
	return ( Fixed( this->toFloat() + rhs.toFloat() ) );
}
Fixed	Fixed::operator-( Fixed const &rhs ) const {
	return ( Fixed( this->toFloat() - rhs.toFloat() ) );
}
Fixed	Fixed::operator*( Fixed const &rhs ) const {
	return ( Fixed( this->toFloat() * rhs.toFloat() ) );

}
Fixed	Fixed::operator/( Fixed const &rhs ) const {
		if (rhs._value == 0)
		{
			std::cerr	<< RED "Error: Division by zero!" RESET
						<< std::endl;
			return ( Fixed() );
		}
	return ( Fixed( this->toFloat() / rhs.toFloat() ) );
}

/* -------------------------------------------------------------------------- */

Fixed	&Fixed::operator++( void ) {
	this->_value++;
	return ( *this );
}

Fixed	Fixed::operator++( int	) {
	Fixed	temp( *this );

	++(*this);
	return ( temp );
}

Fixed	&Fixed::operator--( void ) {
	this->_value--;
	return ( *this );
}

Fixed	Fixed::operator--( int ) {
	Fixed	temp( *this );

	--(*this);
	return ( temp );
}

/* -------------------------------------------------------------------------- */
/*                             GETTERS and SETTERS                            */
/* -------------------------------------------------------------------------- */

int	Fixed::getRawBits( void ) const {
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

/* -------------------------------------------------------------------------- */
/*                              PUBLIC FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

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

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
	 	return ( a );
	return ( b );
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return ( (a < b) ? a : b );
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
	 	return ( a );
	return ( b );
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return ( (a > b) ? a : b );
}

std::ostream&	operator<<( std::ostream& out, const Fixed& number )
{
	out << number.toFloat();
	return ( out );
}
