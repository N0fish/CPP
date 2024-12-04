/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:04:32 by algultse          #+#    #+#             */
/*   Updated: 2024/12/03 20:12:17 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cmath>
# include <climits>
# include "Colors.hpp"

class Fixed {
	private:
		int					_value;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed( int const n );
		Fixed( float const n );
		Fixed( const Fixed &other );
		~Fixed();

		Fixed	&operator=( const Fixed &rhs );

		bool	operator>( const Fixed &rhs ) const;
		bool	operator<( const Fixed &rhs ) const;
		bool	operator>=( const Fixed &rhs ) const;
		bool	operator<=( const Fixed &rhs ) const;
		bool	operator==( const Fixed &rhs ) const;
		bool	operator!=( const Fixed &rhs ) const;

		Fixed	operator+( Fixed const &rhs ) const;
		Fixed	operator-( Fixed const &rhs ) const;
		Fixed	operator*( Fixed const &rhs ) const;
		Fixed	operator/( Fixed const &rhs ) const;

		Fixed	&operator++( void );
		Fixed	operator++( int	);
		Fixed	&operator--( void );
		Fixed	operator--( int );

		void	setRawBits( int const raw );
		int		getRawBits( void ) const;

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed		&min( Fixed &a, Fixed &b );
		static const Fixed	&min( const Fixed &a, const Fixed &b );
		static Fixed		&max( Fixed &a, Fixed &b );
		static const Fixed	&max( const Fixed &a, const Fixed &b );
};

std::ostream	&operator<<( std::ostream &out, const Fixed &fixed );

#endif