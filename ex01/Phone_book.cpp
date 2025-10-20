#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
class contact
{
public:
	contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}
	void setFirstName(const std::string& fn) { first_name = fn; }
	void setLastName(const std::string& ln) { last_name = ln; }
	void setNickname(const std::string& nn) { nickname = nn; }
	void setPhoneNumber(const std::string& pn) { phone_number = pn; }
	void setDarkestSecret(const std::string& ds) { darkest_secret = ds; }
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

class PhoneBook
{
contact contacts[8];
int num_contacts;
int oldest_index;
public:
PhoneBook() : num_contacts(0), oldest_index(0) {}
bool is_all_digits(const std::string& s)
{
	if (s.empty()) return false;
	for (size_t i = 0; i < s.length(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}
	return true;
}
bool is_all_char(const std::string& s) {
	if (s.empty()) return false;
	for (size_t i = 0; i < s.length(); ++i) {
		if (!std::isalpha(static_cast<unsigned char>(s[i])))
			return false;
	}
	return true;
}
std::string formatField(const std::string& field) const {
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	std::ostringstream oss;
    oss << std::setw(10) << std::right << field;
	return oss.str();
}
public:

void addContact(const contact& /*new_contact*/)
{
	int contact_index = -1;
	if (num_contacts < 8)
	{
		contact_index = num_contacts++;
	}
	else
	{
		contact_index = oldest_index;
		oldest_index = (oldest_index + 1) % 8;
	}

	std::string input;
	do
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
	} while (!is_all_char(input));
	contacts[contact_index].setNickname(input);
	do
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
	}
	while (!is_all_char(input));
	contacts[contact_index].setFirstName(input);
	do
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
	}
	while (!is_all_char(input));
	contacts[contact_index].setLastName(input);
	do
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
	}
	while (!is_all_digits(input));
	contacts[contact_index].setPhoneNumber(input);

	do
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
	}
	while (input.empty());
	contacts[contact_index].setDarkestSecret(input);
}
void searchContacts() const
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
              << formatField(contacts[i].first_name) << " | "
              << formatField(contacts[i].last_name) << " | "
              << formatField(contacts[i].nickname) << std::endl;
	}
	std::string input;
	int index = -1;
	do
	{
		std::cout << "Enter contact index to view details (1-" << num_contacts << "): ";
		std::getline(std::cin, input);
		std::stringstream ss(input);
		ss >> index;
		if (ss.fail() || !ss.eof())
			index = -1;
	} while (index < 1 || index > num_contacts);

	const contact& c = contacts[index - 1];
	std::cout << "First Name: " << c.first_name << std::endl;
	std::cout << "Last Name: " << c.last_name << std::endl;
	std::cout << "Nickname: " << c.nickname << std::endl;
	std::cout << "Phone Number: " << c.phone_number << std::endl;
	std::cout << "Darkest Secret: " << c.darkest_secret << std::endl;
}
};

int main()
{
	PhoneBook phonebook;
	do {
		std::string command;
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			phonebook.addContact(contact());
		}
		else if (command == "SEARCH")
		{
			phonebook.searchContacts();
		}
		else if (command == "EXIT")
		{
			break;
		}
			   else
			   {
					   std::cout << "Invalid command. Please try again." << std::endl;
			   }
	   } while (true);
	return 0;
}