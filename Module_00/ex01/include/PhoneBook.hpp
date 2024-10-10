/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:06:44 by algultse          #+#    #+#             */
/*   Updated: 2024/10/10 17:37:03 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <sstream>
# include "Contact.hpp"
# include "utils.hpp"

class PhoneBook {
	private:
		Contact	contactList[8];
		int		contactIndex;
		int		contactLen;

	public:
		PhoneBook();

		void	addContact(void);
		void	searchContacts(void) const;

		void	incrementIndex(void);

		void	displayContacts(void) const;
		void	displayContactDetails(int index) const;
};

#endif