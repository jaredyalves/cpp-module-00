#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _size(0), _last_index(0) {}

int PhoneBook::size() const
{
    return _size;
}

bool PhoneBook::empty() const
{
    return _size == 0;
}

Contact* PhoneBook::contacts()
{
    return _contacts;
}

void PhoneBook::add(const Contact& contact)
{
    _contacts[_last_index] = contact;
    _last_index = (_last_index + 1) % CONTACTS_MAX;
    if (_size < CONTACTS_MAX)
        ++_size;
}
