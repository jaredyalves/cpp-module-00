#include "Contact.hpp"

std::string Contact::getFirstName() const
{
	return _first_name;
}

void Contact::setFirstName(const std::string& first_name)
{
	_first_name = first_name;
}

std::string Contact::getLastName() const
{
	return _last_name;
}

void Contact::setLastName(const std::string& last_name)
{
	_last_name = last_name;
}

std::string Contact::getNickname() const
{
	return _nickname;
}

void Contact::setNickname(const std::string& nickname)
{
	_nickname = nickname;
}

std::string Contact::getPhoneNumber() const
{
	return _phone_number;
}

void Contact::setPhoneNumber(const std::string& phone_number)
{
	_phone_number = phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return _darkest_secret;
}

void Contact::setDarkestSecret(const std::string& darkest_secret)
{
	_darkest_secret = darkest_secret;
}
