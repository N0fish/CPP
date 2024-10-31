/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:54:46 by algultse          #+#    #+#             */
/*   Updated: 2024/10/29 20:05:04 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cmath>

# define RESET "\e[0m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"
# define CYAN "\e[36m"
# define BLACK "\e[30m"

# define BOLD "\e[1m"

class Fixed {
	private:
		int					_value;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed( int const n );
		Fixed( float const n );
		Fixed( const Fixed &other );

		Fixed	&operator=( const Fixed &rhs );

		~Fixed();

		void	setRawBits( int const raw );
		int		getRawBits( void ) const;

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif