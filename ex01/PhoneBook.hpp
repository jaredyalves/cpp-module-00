#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define CONTACTS_MAX 8

class PhoneBook
{
public:
	int	 size() const;
	bool isEmpty() const;
	void add(const Contact& contact);

	std::string getFirstName(int idx) const;
	void		setFirstName(int idx, const std::string& first_name);
	std::string getLastName(int idx) const;
	void		setLastName(int idx, const std::string& last_name);
	std::string getNickname(int idx) const;
	void		setNickname(int idx, const std::string& nickname);
	std::string getPhoneNumber(int idx) const;
	void		setPhoneNumber(int idx, const std::string& phone_number);
	std::string getDarkestSecret(int idx) const;
	void		setDarkestSecret(int idx, const std::string& darkest_secret);

	PhoneBook();

private:
	Contact _contacts[CONTACTS_MAX];
	int		_contacts_size;
	int		_contacts_last_index;
};

#endif // PHONEBOOK_HPP
