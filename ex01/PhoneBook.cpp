#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>

PhoneBook::PhoneBook() : num_contacts(0), oldest_index(0) {}

bool PhoneBook::is_all_digits(const std::string &s)
{
    if (s.empty()) return false;
    for (size_t i = 0; i < s.length(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    return true;
}

bool PhoneBook::is_all_char(const std::string &s)
{
    if (s.empty()) return false;
    for (size_t i = 0; i < s.length(); ++i)
        if (!std::isalpha(static_cast<unsigned char>(s[i])))
            return false;
    return true;
}

std::string PhoneBook::formatField(const std::string &field) const
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    std::ostringstream oss;
    oss << std::setw(10) << std::right << field;
    return oss.str();
}

void PhoneBook::addContact(const Contact &/*new_contact*/)
{
    int contact_index = -1;
    if (num_contacts < 8)
        contact_index = num_contacts++;
    else {
        contact_index = oldest_index;
        oldest_index = (oldest_index + 1) % 8;
    }

    std::string input;

    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
    } while (!is_all_char(input));
    contacts[contact_index].setNickname(input);

    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
    } while (!is_all_char(input));
    contacts[contact_index].setFirstName(input);

    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
    } while (!is_all_char(input));
    contacts[contact_index].setLastName(input);

    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
    } while (!is_all_digits(input));
    contacts[contact_index].setPhoneNumber(input);

    do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
    } while (input.empty());
    contacts[contact_index].setDarkestSecret(input);
}

void PhoneBook::searchContacts() const
{
    if (num_contacts == 0)
    {
        std::cout << "Phone book is empty." << std::endl;
        return;
    }

    std::cout << "Index | First Name | Last Name  | Nickname  " << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (int i = 0; i < num_contacts; ++i)
    {
        std::cout << i + 1 << "     | "
                  << formatField(contacts[i].getFirstName()) << " | "
                  << formatField(contacts[i].getLastName()) << " | "
                  << formatField(contacts[i].getNickname()) << std::endl;
    }

    std::string input;
    int index = -1;
    do {
        std::cout << "Enter contact index to view details (1-" << num_contacts << "): ";
        std::getline(std::cin, input);
        std::stringstream ss(input);
        ss >> index;
        if (ss.fail() || !ss.eof())
            index = -1;
    } while (index < 1 || index > num_contacts);

    const Contact &c = contacts[index - 1];
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}