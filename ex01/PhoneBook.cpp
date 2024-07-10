#include "PhoneBook.hpp"

int PhoneBook::size() const
{
	return _contacts_size;
}

bool PhoneBook::isEmpty() const
{
	return _contacts_size == 0;
}

void PhoneBook::add(const Contact& contact)
{
	if (_contacts_size < CONTACTS_MAX)
		_contacts_size++;

	_contacts[_contacts_last_index] = contact;

	_contacts_last_index = (_contacts_last_index + 1) % CONTACTS_MAX;
}

std::string PhoneBook::getFirstName(int idx) const
{
	return _contacts[idx].getFirstName();
}

void PhoneBook::setFirstName(int idx, const std::string& first_name)
{
	_contacts[idx].setFirstName(first_name);
}

std::string PhoneBook::getLastName(int idx) const
{
	return _contacts[idx].getLastName();
}

void PhoneBook::setLastName(int idx, const std::string& last_name)
{
	_contacts[idx].setLastName(last_name);
}

std::string PhoneBook::getNickname(int idx) const
{
	return _contacts[idx].getNickname();
}

void PhoneBook::setNickname(int idx, const std::string& nickname)
{
	_contacts[idx].setNickname(nickname);
}

std::string PhoneBook::getPhoneNumber(int idx) const
{
	return _contacts[idx].getPhoneNumber();
}

void PhoneBook::setPhoneNumber(int idx, const std::string& phone_number)
{
	_contacts[idx].setPhoneNumber(phone_number);
}

std::string PhoneBook::getDarkestSecret(int idx) const
{
	return _contacts[idx].getDarkestSecret();
}

void PhoneBook::setDarkestSecret(int idx, const std::string& darkest_secret)
{
	_contacts[idx].setDarkestSecret(darkest_secret);
}

PhoneBook::PhoneBook(): _contacts_size(0), _contacts_last_index(0) {}
