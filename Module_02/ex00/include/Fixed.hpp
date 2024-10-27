/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:54:46 by algultse          #+#    #+#             */
/*   Updated: 2024/10/27 22:35:04 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <string>

# define RESET "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"
# define CYAN "\e[36m"

class Fixed {
	private:
		int					_value;
		static const int	_fractionalBits; /* the number of fractional bits. It will always be 8 */

	public:
		Fixed();
		Fixed( const Fixed &other ); /* copy constructor */

		Fixed	&operator=( const Fixed &rhs ); /* assignment operator, which assign
    	values between two instances of the same class */

		~Fixed();

		void	setRawBits( int const raw );

		int		getRawBits( void ) const;
};

#endif