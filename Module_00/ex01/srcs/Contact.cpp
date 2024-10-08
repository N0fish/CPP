/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:13:35 by algultse          #+#    #+#             */
/*   Updated: 2023/10/08 15:44:36 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(const std::string& value)
{
	firstName = value;
}

void	Contact::setLastName(const std::string& value)
{
	lastName = value;
}

void	Contact::setNickname(const std::string& value)
{
	nickname = value;
}

void	Contact::setPhoneNumber(const std::string& value)
{
	phoneNumber = value;
}

void	Contact::setDarkestSecret(const std::string& value)
{
	darkestSecret = value;
}

std::string	Contact::getFirstName(void) const
{
	return (firstName);
}

std::string	Contact::getLastName(void) const
{
	return (lastName);
}

std::string	Contact::getNickname(void) const
{
	return (nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (darkestSecret);
}
