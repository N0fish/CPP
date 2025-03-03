/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:00:43 by algultse          #+#    #+#             */
/*   Updated: 2025/01/23 19:59:20 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

# include <string>
# include <iostream>
# include <limits>
# include <cfloat>
# include <cstdlib>
# include <cmath>
# include <iomanip>
# include <cctype> 
// # include <exception>

# define RESET "\e[0m"

# define BOLD "\e[1m"
# define DIM "\e[2m"
# define ITALIC "\e[3m"
# define UNDERLINE "\e[4m"
# define BLKS "\e[5m"
# define BLKF "\e[6m"
# define INVERSE "\e[7m"
# define BARR "\e[9m"

# define REDD "\e[0;38;2;255;0;0m"       // Rouge
# define RED1 "\e[0;38;2;210;10;10m"     // Rouge
# define ORNG "\e[0;38;2;205;105;0m"     // Orange
# define GOLD "\e[0;38;2;255;215;0m"     // Or
# define YLLW "\e[0;38;2;255;255;0m"     // Jaune
# define GRNN "\e[0;38;2;0;128;0m"       // Vert foncé
# define LIME "\033[0;38;2;0;255;0m"       // Vert lime
# define CYAN "\033[0;38;2;0;255;255m"     // Cyan
# define BLUE "\033[0;38;2;80;80;220m"     // Bleu
# define INDI "\033[0;38;2;75;0;130m"      // Indigo
# define PURP "\033[0;38;2;238;130;238m"   // Violet
# define MAGN "\033[0;38;2;255;0;255m"     // Magenta
# define PINK "\033[0;38;2;255;192;203m"   // Rose
# define BROW "\033[0;38;2;165;42;42m"     // Brun
# define IVRY "\033[0;38;2;255;255;240m"   // Ivoire
# define GRY1 "\033[0;38;2;128;128;128m"   // Gris moyen
# define GRY2 "\033[0;38;2;170;170;170m"   // Gris moyen
# define SLVR "\033[0;38;2;192;192;192m"   // Argent
# define TURQ "\033[0;38;2;64;224;208m"    // Turquoise
# define CORL "\033[0;38;2;255;127;80m"    // Corail
# define SALM "\033[0;38;2;250;128;114m"   // Saumon
# define PLUM "\033[0;38;2;221;160;221m"   // Prune
# define TEAL "\033[0;38;2;0;128;128m"     // Sarcelle
# define OLIV "\033[0;38;2;128;128;0m"     // Olive
# define MINT "\033[0;38;2;189;252;201m"   // Menthe
# define NAVY "\033[0;38;2;0;0;128m"       // Marine
# define PEAC "\033[0;38;2;175;238;238m"   // Pêche
# define LAVN "\033[0;38;2;230;230;250m"   // Lavande
# define EMRD "\033[0;38;2;80;200;120m"    // Émeraude
# define RUBY "\033[0;38;2;224;17;95m"     // Rubis
# define CLRALL "\033[2J\033[3J\033[H"     // Clear terminal (supprime historique)
# define CLR "\033c"                       // Clear terminal (garde historique)
# define CLRL "\033[2K"                    // Clear ligne terminal


// # define BOLD "\e[1m"
// # define DIM "\e[2m"
// # define ITALIC "\e[3m"
// # define UNDERLINE "\e[4m"
// # define INVERSE "\e[7m"
// # define STRIKETHROUGH "\e[9m"

// # define RESET "\e[0m"
// # define BLACK "\e[30m"
// # define RED "\e[31m"
// # define GREEN "\e[32m"
// # define YELLOW "\e[33m"
// # define BLUE "\e[34m"
// # define PURPLE "\e[35m"
// # define CYAN "\e[36m"
// # define GRAY "\e[37m"

// # define BLACK_BACKGROUND "\e[40m"
// # define RED_BACKGROUND "\e[41m"
// # define GREEN_BACKGROUND "\e[42m"
// # define YELLOW_BACKGROUND "\e[43m"
// # define BLUE_BACKGROUND "\e[44m"
// # define PURPLE_BACKGROUND "\e[45m"
// # define CYAN_BACKGROUND "\e[46m"
// # define WHITE_BACKGROUND "\e[47m"

// # define BRIGHT_RED "\e[91m"
// # define BRIGHT_GREEN "\e[92m"
// # define BRIGHT_YELLOW "\e[93m"
// # define BRIGHT_BLUE "\e[94m"
// # define BRIGHT_PURPLE "\e[95m"
// # define BRIGHT_CYAN "\e[96m"
// # define BRIGHT_WHITE "\e[97m"

#endif