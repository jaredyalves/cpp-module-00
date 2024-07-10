#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
	std::string getFirstName() const;
	void		setFirstName(const std::string& first_name);
	std::string getLastName() const;
	void		setLastName(const std::string& last_name);
	std::string getNickname() const;
	void		setNickname(const std::string& nickname);
	std::string getPhoneNumber() const;
	void		setPhoneNumber(const std::string& phone_number);
	std::string getDarkestSecret() const;
	void		setDarkestSecret(const std::string& darkest_secret);

private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif // CONTACT_HPP
