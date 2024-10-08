/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:01:12 by algultse          #+#    #+#             */
/*   Updated: 2023/10/08 16:30:22 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactIndex(0), contactLen(0) {}

static std::string	getInput(std::string request)
{
	std::string	cmd;

	std::cout 	<< "Please enter " << request << ": " << std::endl 
				<< "> " << std::flush;
	if (!std::getline(std::cin, cmd))
	{
		if (cmd.empty() && std::cin.eof())
			exit(0);
		else
			std::cin.clear();
	}
	return (stripWhitespace(cmd));
}

static std::string	getInputWithCustomValidation(
	const std::string& request, bool (*validationFunc)(const std::string&), const std::string& errorMessage)
{
	std::string	input;

	do
	{
		input = stripWhitespace(getInput(request));
		if (input.empty())
			std::cout << "Input cannot be empty. Please try again." << std::endl;
		else if (!validationFunc(input)) 
		{
			std::cout << errorMessage << std::endl;
			input.clear();
		}
	} while (input.empty());

	return (input);
}

static std::string	getInputWithAlphaValidation(const std::string& request)
{
	return (
		getInputWithCustomValidation(
			request,
			isAlpha,
			"Input must contain only letters. Please try again."
		));
}

static std::string	getInputWithPhoneValidation(const std::string& request)
{
    return (
		getInputWithCustomValidation(
			request,
			isValidPhoneNumber,
			"Invalid phone number format. Please try again."
		));
}

static std::string	getInputWithValidation(const std::string& request)
{
	std::string	input;

	do
	{
		input = getInput(request);
		if (input.empty())
			std::cout << "Input cannot be empty. Please try again." << std::endl;
	} while (input.empty());

	return (input);
}

void	PhoneBook::incrementIndex(void)
{
	contactIndex++;
	contactLen++;
	if (contactIndex > 7)
		contactIndex = 0;
	if (contactLen > 8)
		contactLen = 8;
}

void	PhoneBook::addContact()
{
	Contact	contact;

	std::cout 	<< std::endl
				<< "\t|-------------- add a contact --------------|" << std::endl
				<< std::endl;

	contact.setFirstName(getInputWithAlphaValidation("first name"));
	contact.setLastName(getInputWithAlphaValidation("last name"));
	contact.setNickname(getInputWithValidation("nickname"));
	contact.setPhoneNumber(getInputWithPhoneValidation("phone number"));
	contact.setDarkestSecret(getInputWithValidation("a dark secret"));

	contactList[contactIndex] = contact;
	incrementIndex();
}

void	PhoneBook::displayContacts() const
{
	std::cout << std::endl
			<< "\t|----------+----------+----------+----------|" << std::endl
			<< "\t|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
			<< "\t|----------+----------+----------+----------|" << std::endl;

	for (int i = 0; i < contactLen; i++)
	{
		std::cout << "\t|"
				<< std::setw(10) << (i + 1) << "|"
				<< formatField(contactList[i].getFirstName()) << "|"
				<< formatField(contactList[i].getLastName()) << "|"
				<< formatField(contactList[i].getNickname()) << "|" << std::endl;
	}
	std::cout << "\t|----------+----------+----------+----------|" << std::endl;
}

void	PhoneBook::displayContactDetails(int index) const
{
	if (index >= 0 && index < contactLen)
	{
		std::cout	<< " - First Name: " << contactList[index].getFirstName() << std::endl
					<< " - Last Name: " << contactList[index].getLastName() << std::endl
					<< " - Nickname: " << contactList[index].getNickname() << std::endl
					<< " - Phone Number: " << contactList[index].getPhoneNumber() << std::endl
					<< " - Darkest Secret: " << contactList[index].getDarkestSecret() << std::endl
					<< std::endl;
	}
	else
		std::cout << "Invalid index!" << std::endl;
}

static int	getValidatedIndex(const std::string& input, int maxIndex)
{
	if (input.empty())
	{
		std::cout << "Input cannot be empty. Please enter a valid number." << std::endl;
		return (-1);
	}
	if (isValidNumber(input))
	{
		int index = std::stoi(input) - 1;
		if (index >= 0 && index < maxIndex)
			return (index);
		else
		{
			std::cout	<< "Invalid index! Please enter a number between 1 and " 
						<< maxIndex << "." 
						<< std::endl;
			return (-1);
		}
	}
	else
	{
		std::cout << "Invalid input! Please use a number next time." << std::endl;
		return (-1);
	}
}

void	PhoneBook::searchContacts() const
{
	if (contactLen == 0)
	{
		std::cout << "No contacts in the phone book to search." << std::endl;
		return;
	}
	displayContacts();

	std::string input = getInput("the index of the contact to display");
	int index = getValidatedIndex(input, contactLen);
	if (index != -1)
		displayContactDetails(index);
}
