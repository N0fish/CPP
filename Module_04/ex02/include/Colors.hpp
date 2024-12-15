/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:10:32 by algultse          #+#    #+#             */
/*   Updated: 2024/12/14 20:18:38 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

# define BOLD "\e[1m"
# define DIM "\e[2m"
# define ITALIC "\e[3m"
# define UNDERLINE "\e[4m"
# define INVERSE "\e[7m"
# define STRIKETHROUGH "\e[9m"

# define RESET "\e[0m"
# define BLACK "\e[30m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"
# define CYAN "\e[36m"
# define GRAY "\e[37m"

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

//test
void	testSubject(void);
void	testDeepCopy(void);
void	testAnimalArray(void);
void	testWrongAnimals(void);

#endif