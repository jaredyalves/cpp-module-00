#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define CONTACTS_MAX 8

class PhoneBook {
private:
    int _size;
    int _last_index;
    Contact _contacts[CONTACTS_MAX];

public:
    PhoneBook();

    int size() const;

    bool empty() const;

    Contact *contacts();

    void add(const Contact &contact);
};

#endif //PHONEBOOK_HPP
