#include "Contact.hpp"

Contact::Contact()
    : first_name(""), last_name(""), nickname(""),
      phone_number(""), darkest_secret("") {}

void Contact::setFirstName(const std::string &fn) { first_name = fn; }
void Contact::setLastName(const std::string &ln) { last_name = ln; }
void Contact::setNickname(const std::string &nn) { nickname = nn; }
void Contact::setPhoneNumber(const std::string &pn) { phone_number = pn; }
void Contact::setDarkestSecret(const std::string &ds) { darkest_secret = ds; }

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phone_number; }
std::string Contact::getDarkestSecret() const { return darkest_secret; }