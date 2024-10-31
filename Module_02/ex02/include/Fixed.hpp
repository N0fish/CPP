/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:12:40 by algultse          #+#    #+#             */
/*   Updated: 2024/10/24 22:13:04 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cmath>
# include <climits>

# define RESET "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"
# define CYAN "\e[36m"
# define BLACK "\e[30m"

# define BOLD "\e[1m"
# define UNDERLINE "\e[4m"
# define INVERSE "\e[7m"

# define BG_BLACK "\e[40m"
# define BG_RED "\e[41m"
# define BG_GREEN "\e[42m"
# define BG_YELLOW "\e[43m"
# define BG_BLUE "\e[44m"
# define BG_PURPLE "\e[45m"
# define BG_CYAN "\e[46m"
# define BG_WHITE "\e[47m"

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