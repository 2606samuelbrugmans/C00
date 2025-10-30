#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();

    void setFirstName(const std::string &fn);
    void setLastName(const std::string &ln);
    void setNickname(const std::string &nn);
    void setPhoneNumber(const std::string &pn);
    void setDarkestSecret(const std::string &ds);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif