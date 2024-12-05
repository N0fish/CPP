/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:12:40 by algultse          #+#    #+#             */
/*   Updated: 2024/12/03 22:01:04 by algultse         ###   ########.fr       */
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
# define ITALIC "\e[3m"
# define STRIKETHROUGH "\e[9m"
# define DIM "\e[2m"

# define RED_BACKGROUND "\e[41m"      // Красный фон
# define GREEN_BACKGROUND "\e[42m"    // Зелёный фон
# define YELLOW_BACKGROUND "\e[43m"   // Жёлтый фон
# define BLUE_BACKGROUND "\e[44m"     // Синий фон
# define PURPLE_BACKGROUND "\e[45m"   // Фиолетовый фон
# define CYAN_BACKGROUND "\e[46m"     // Голубой фон
# define BLACK_BACKGROUND "\e[40m"    // Чёрный фон
# define WHITE_BACKGROUND "\e[47m"    // Белый фон

# define BRIGHT_RED "\e[91m"          // Ярко-красный
# define BRIGHT_GREEN "\e[92m"        // Ярко-зелёный
# define BRIGHT_YELLOW "\e[93m"       // Ярко-жёлтый
# define BRIGHT_BLUE "\e[94m"         // Ярко-синий
# define BRIGHT_PURPLE "\e[95m"       // Ярко-фиолетовый
# define BRIGHT_CYAN "\e[96m"         // Ярко-голубой
# define BRIGHT_WHITE "\e[97m"        // Ярко-белый

# define INVERSE_BLACK_WHITE "\e[3;40;97m"
# define ITALIC_BLUE_BLACK "\e[3;34;40m"
# define BLUE_BLACK "\e[34;40m"
# define GREEN_BLACK "\e[32;40m"
# define ITALIC_YELLOW_ON_BLACK "\e[3;33;40m"
# define ITALIC_PURPLE_ON_BLACK "\e[3;35;40m"
# define ITALIC_RED_ON_BLACK "\e[3;2;31;40m"

//test
void	testClapTrap();
void	testScavTrap();
void	testScavTrapGuardGate();

#endif