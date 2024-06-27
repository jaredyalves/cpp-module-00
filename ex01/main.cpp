#include <iomanip>
#include <iostream>
#include <sstream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

static void add_contact(PhoneBook &phonebook) {
    std::string input;
    Contact contact;

    while (input.empty() && !std::cin.eof()) {
        std::cout << "Enter the contact's first name: ";
        if (std::getline(std::cin, input) && !input.empty())
            contact.set_first_name(input);
    }

    input = "";
    while (input.empty() && !std::cin.eof()) {
        std::cout << "Enter the contact's last name: ";
        if (std::getline(std::cin, input) && !input.empty())
            contact.set_last_name(input);
    }

    input = "";
    while (input.empty() && !std::cin.eof()) {
        std::cout << "Enter the contact's nickname: ";
        if (std::getline(std::cin, input) && !input.empty())
            contact.set_nickname(input);
    }

    input = "";
    while (input.empty() && !std::cin.eof()) {
        std::cout << "Enter the contact's phone number: ";
        if (std::getline(std::cin, input) && !input.empty())
            contact.set_phone_number(input);
    }

    input = "";
    while (input.empty() && !std::cin.eof()) {
        std::cout << "Enter the contact's darkest secret: ";
        if (std::getline(std::cin, input) && !input.empty())
            contact.set_darkest_secret(input);
    }

    if (!std::cin.eof()) {
        phonebook.add(contact);
        std::cout << "Contact added.\n";
    }
}

static void display_contacts(PhoneBook &phonebook) {
    std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10)
            << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < phonebook.size(); ++i) {
        const Contact &contact = phonebook.contacts()[i];
        std::cout << "|" << std::setw(10) << i + 1 << "|"
                << std::setw(10) << (contact.get_first_name().size() > 10
                                         ? contact.get_first_name().substr(0, 9) + "."
                                         : contact.get_first_name()) << "|"
                << std::setw(10) << (contact.get_last_name().size() > 10
                                         ? contact.get_last_name().substr(0, 9) + "."
                                         : contact.get_last_name()) << "|"
                << std::setw(10) << (contact.get_nickname().size() > 10
                                         ? contact.get_nickname().substr(0, 9) + "."
                                         : contact.get_nickname()) << "|" << std::endl;
    }
}

static void search_contact(PhoneBook &phonebook) {
    int index;

    if (phonebook.empty()) {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    display_contacts(phonebook);

    while (true) {
        std::string input;
        std::istringstream iss;

        std::cout << "Enter the index of the contact to display: ";
        std::getline(std::cin, input);

        if (std::cin.eof())
            return;

        if (input.empty()) {
            std::cout << "Invalid index. Please try again." << std::endl;
            continue;
        }

        iss.clear();
        iss.str(input);

        if (iss >> index) {
            if (index >= 1 && index <= phonebook.size())
                break;
        }
        std::cout << "Invalid index. Please try again." << std::endl;
    }

    const Contact &contact = phonebook.contacts()[index - 1];
    std::cout << "First Name: " << contact.get_first_name() << std::endl;
    std::cout << "Last Name: " << contact.get_last_name() << std::endl;
    std::cout << "Nickname: " << contact.get_nickname() << std::endl;
    std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << contact.get_darkest_secret() << std::endl;
}

int main() {
    PhoneBook phonebook;

    std::cout << "Welcome to the PhoneBook!" << std::endl;
    std::cout << "Please enter one of the following commands: ADD, SEARCH or EXIT." << std::endl;

    while (true) {
        std::string input;

        std::cout << "Enter command: ";
        std::getline(std::cin, input);

        if (input == "ADD") {
            add_contact(phonebook);
        } else if (input == "SEARCH") {
            search_contact(phonebook);
        }

        if (input == "EXIT" || std::cin.eof()) {
            std::cout << "Exiting... Goodbye!" << std::endl;
            break;
        }
    }
}
