/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:36:25 by algultse          #+#    #+#             */
/*   Updated: 2023/10/08 22:58:04 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>

std::string stripWhitespace(const std::string& str);
bool		isAlpha(const std::string& str);
bool		isValidPhoneNumber(const std::string& str);
std::string	formatField(const std::string& str);
bool		isValidNumber(const std::string& str);

#endif