#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
private:
    Contact contacts[8];
    int num_contacts;
    int oldest_index;

    bool is_all_digits(const std::string &s);
    bool is_all_char(const std::string &s);
    std::string formatField(const std::string &field) const;

public:
    PhoneBook();
    void addContact(const Contact &new_contact);
    void searchContacts() const;
};

#endif