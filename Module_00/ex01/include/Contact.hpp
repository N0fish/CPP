/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:55 by algultse          #+#    #+#             */
/*   Updated: 2023/10/01 14:24:36 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		// поля класса
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		// constructor
		// Contact();
		// Сеттеры (методы для установки значений)
		void	setFirstName(const std::string& value);
		void	setLastName(const std::string& value);
		void	setNickname(const std::string& value);
		void	setPhoneNumber(const std::string& value);
		void	setDarkestSecret(const std::string& value);

		// Геттеры (методы для получения значений)
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
};

#endif