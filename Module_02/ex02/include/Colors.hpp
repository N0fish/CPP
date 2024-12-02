/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:12:40 by algultse          #+#    #+#             */
/*   Updated: 2024/10/24 22:13:04 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

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

class Fixed;

//test
void	testComparisonOperators(const Fixed &a, const Fixed &b);
void	testArithmeticOperators(const Fixed &a, const Fixed &b);
void	testIncrementDecrement(Fixed &a);
void	testIncrementDecrement(const Fixed &b);
void	testMinMax(const Fixed &a, const Fixed &b);

#endif