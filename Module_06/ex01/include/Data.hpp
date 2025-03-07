/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:39:54 by algultse          #+#    #+#             */
/*   Updated: 2025/03/06 15:09:08 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include "Colors.hpp"

typedef struct Data {
    int			id;
	std::string	name;
	float		balance;

	Data(int i, const std::string& n, float b);
}				Data;

#endif
