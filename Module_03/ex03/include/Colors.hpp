/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:10:32 by algultse          #+#    #+#             */
/*   Updated: 2024/12/08 23:28:51 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

# define RESET "\e[0m"
# define BLACK "\e[30m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"
# define CYAN "\e[36m"
# define GRAY "\e[37m"

# define BOLD "\e[1m"
# define DIM "\e[2m"
# define ITALIC "\e[3m"
# define UNDERLINE "\e[4m"
# define INVERSE "\e[7m"
# define STRIKETHROUGH "\e[9m"

# define BLACK_BACKGROUND "\e[40m"
# define RED_BACKGROUND "\e[41m"
# define GREEN_BACKGROUND "\e[42m"
# define YELLOW_BACKGROUND "\e[43m"
# define BLUE_BACKGROUND "\e[44m"
# define PURPLE_BACKGROUND "\e[45m"
# define CYAN_BACKGROUND "\e[46m"
# define WHITE_BACKGROUND "\e[47m"

# define BRIGHT_RED "\e[91m"
# define BRIGHT_GREEN "\e[92m"
# define BRIGHT_YELLOW "\e[93m"
# define BRIGHT_BLUE "\e[94m"
# define BRIGHT_PURPLE "\e[95m"
# define BRIGHT_CYAN "\e[96m"
# define BRIGHT_WHITE "\e[97m"

# define ITALIC_RED_ON_BLACK "\e[3;2;31;40m"
# define GREEN_BLACK "\e[32;40m"
# define BLUE_BLACK "\e[34;40m"
# define ITALIC_BLUE_BLACK "\e[3;34;40m"
# define ITALIC_YELLOW_ON_BLACK "\e[3;33;40m"
# define ITALIC_PURPLE_ON_BLACK "\e[3;35;40m"
# define ITALIC_CYAN_BLACK "\e[3;36;40m"
# define INVERSE_BLACK_WHITE "\e[3;40;97m"
# define INVERSE_BLUE_ON_WHILE "\e[7;97;34m"

# define GRAY_ON_WHITE "\e[2;37;47m"
# define BOLD_GRAY_ON_WHITE "\e[1;2;37;47m"
# define ITALIC_GRAY_ON_WHITE "\e[3;2;37;47m"
# define INVERSE_GRAY_ON_WHITE "\e[7;2;37;47m"

# define GREEN_ON_WHITE "\e[32;47m"
# define BLUE_ON_WHITE "\e[34;47m"
# define YELLOW_ON_WHITE "\e[33;47m"
# define PURPLE_ON_WHITE "\e[35;47m"
# define BRIGHT_BLACK_ON_BLUE "\e[90;44m"
# define YELLOW_ON_BLUE "\e[33;44m"
# define BOLD_YELLOW_ON_BLUE "\e[1;33;44m"

//test
void	testDiamondTrap();
void	testMixedTraps();

#endif