#include "Contact.hpp"
#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

static void add_contact(PhoneBook& phonebook)
{
	std::string input;
	Contact		contact;

	while (input.empty() && !std::cin.eof())
	{
		std::cout << "Enter the contact's first name: ";
		if (std::getline(std::cin, input) && !input.empty())
			contact.setFirstName(input);
	}

	input = "";
	while (input.empty() && !std::cin.eof())
	{
		std::cout << "Enter the contact's last name: ";
		if (std::getline(std::cin, input) && !input.empty())
			contact.setLastName(input);
	}

	input = "";
	while (input.empty() && !std::cin.eof())
	{
		std::cout << "Enter the contact's nickname: ";
		if (std::getline(std::cin, input) && !input.empty())
			contact.setNickname(input);
	}

	input = "";
	while (input.empty() && !std::cin.eof())
	{
		std::cout << "Enter the contact's phone number: ";
		if (std::getline(std::cin, input) && !input.empty())
			contact.setPhoneNumber(input);
	}

	input = "";
	while (input.empty() && !std::cin.eof())
	{
		std::cout << "Enter the contact's darkest secret: ";
		if (std::getline(std::cin, input) && !input.empty())
			contact.setDarkestSecret(input);
	}

	if (!std::cin.eof())
	{
		phonebook.add(contact);
		std::cout << "Contact added.\n";
	}
}

static void display_contacts(PhoneBook& phonebook)
{
	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10)
			  << "First Name" << "|" << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0; i < phonebook.size(); ++i)
		std::cout << "|" << std::setw(10) << i + 1 << "|" << std::setw(10)
				  << (phonebook.getFirstName(i).size() > 10
							 ? phonebook.getFirstName(i).substr(0, 9) + "."
							 : phonebook.getFirstName(i))
				  << "|" << std::setw(10)
				  << (phonebook.getLastName(i).size() > 10
							 ? phonebook.getLastName(i).substr(0, 9) + "."
							 : phonebook.getLastName(i))
				  << "|" << std::setw(10)
				  << (phonebook.getNickname(i).size() > 10
							 ? phonebook.getNickname(i).substr(0, 9) + "."
							 : phonebook.getNickname(i))
				  << "|" << std::endl;
}

static void search_contact(PhoneBook& phonebook)
{
	int index;

	if (phonebook.isEmpty())
	{
		std::cout << "No contacts available." << std::endl;
		return;
	}

	display_contacts(phonebook);

	while (true)
	{
		std::string		   input;
		std::istringstream iss;

		std::cout << "Enter the index of the contact to display: ";
		std::getline(std::cin, input);

		if (std::cin.eof())
			return;

		if (input.empty())
		{
			std::cout << "Invalid index. Please try again." << std::endl;
			continue;
		}

		iss.clear();
		iss.str(input);

		if (iss >> index)
			if (index >= 1 && index <= phonebook.size())
				break;
		std::cout << "Invalid index. Please try again." << std::endl;
	}

	int i = index - 1;
	std::cout << "First Name: " << phonebook.getFirstName(i) << std::endl
			  << "Last Name: " << phonebook.getLastName(i) << std::endl
			  << "Nickname: " << phonebook.getNickname(i) << std::endl
			  << "Phone Number: " << phonebook.getPhoneNumber(i) << std::endl
			  << "Darkest Secret: " << phonebook.getDarkestSecret(i)
			  << std::endl;
}

int main()
{
	PhoneBook phonebook;

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	std::cout
		<< "Please enter one of the following commands: ADD, SEARCH or EXIT."
		<< std::endl;

	while (true)
	{
		std::string input;

		std::cout << "Enter command: ";
		std::getline(std::cin, input);

		if (input == "ADD")
			add_contact(phonebook);
		else if (input == "SEARCH")
			search_contact(phonebook);
		if (input == "EXIT" || std::cin.eof())
		{
			std::cout << "Exiting... Goodbye!" << std::endl;
			break;
		}
	}
}
