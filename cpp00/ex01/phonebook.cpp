#include <iostream>
#include <string>
#include <iomanip>

class	contact
{
	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	login;
	std::string	postal_address;
	std::string	email;
	std::string	phone;
	std::string	birthdate;
	std::string	fav_meal;
	std::string	clr_underwear;
	std::string	secret;
	
	public:
	void	add_contact(contact *new_contact);
	void	search_contact(int amount, contact contacts[8]);
};

/*
	ERRORS
*/
void	error(const char *msg)
{
	std::cout << "\e[0;31mERROR!\n reading" << msg << "failed!\n\e[0;0m";
	exit (-1);
}

/*
	this function reads from cin and returns that line
*/
std::string	fill_contact(const char *type)
{
	std::string line;

	std::cout << "\e[0;34m" << type << "\n\e[0;0m";
	std::cin.clear();
	std::cin.sync();
	if (std::getline(std::cin, line).good() == 0)
		error(type);
	std::cout << "\n";
	return (line);
}

/*
	this function formats the arguments to a length of 10chars
*/
std::string	format(std::string str)
{
	int i = str.length();
	if (i > 10) {
		for (int j = i; j >= 10; j--)
			str.pop_back();
		str.push_back('.');
	}
	return (str);
}

/*
	this function adds the contacts to the class
*/
void	contact::add_contact(contact *new_contact)
{
	std::cout << "\n\e[0;34mPlease fill in the folowing information to add the new contact!\n";
	new_contact->first_name = fill_contact("first name");
	new_contact->last_name = fill_contact("last name");
	new_contact->nickname = fill_contact("nickname");
	new_contact->login = fill_contact("login");
	new_contact->postal_address = fill_contact("postal address");
	new_contact->email = fill_contact("email address");
	new_contact->phone = fill_contact("phone number");
	new_contact->birthdate = fill_contact("birthdate");
	new_contact->fav_meal = fill_contact("favorite meal");
	new_contact->clr_underwear = fill_contact("underwear color");
	new_contact->secret = fill_contact("darkest secret");
	std::cout << "\n\e[0;32mAdded new contact successfully!\n\n\e[0;0m";
}

/*
	prints out all the contacts and asks for specific contact
*/
void	contact::search_contact(int amount, contact contacts[8])
{
	std::string line;

	for (int i = 0; i < amount; i++) {
		std::cout << "        #" << i << "|";
		std::cout << std::setw(10) << format(contacts[i].first_name) << "|";
		std::cout << std::setw(10) << format(contacts[i].last_name) << "|";
		std::cout << std::setw(10) << format(contacts[i].nickname) << "\n";
	}
	while (1) {
		std::cout << "\nwhich contacts information would you like to see?\n";
		if (std::getline(std::cin, line).good() == 0)
			error("reading index failed!");
		if (!line.compare("BREAK"))
			return ;
		int index = std::atoi(line.c_str());
		int i = 0;
		while (line[i] >= '0' && line[i] < '8') {i++;}
		if (index >= amount || index < 0 || line[i])
			std::cout << "\e[0;31m" << "\nInvalid input, try again!\n\e[0;0m";
		else {
			std::cout << "first name:      " << contacts[index].first_name << "\n";
			std::cout << "last name:       " << contacts[index].last_name << "\n";
			std::cout << "nickname:        " << contacts[index].nickname << "\n";
			std::cout << "login name:      " << contacts[index].login << "\n";
			std::cout << "postal address:  " << contacts[index].postal_address << "\n";
			std::cout << "email address:   " << contacts[index].email << "\n";
			std::cout << "phone number:    " << contacts[index].phone << "\n";
			std::cout << "birthdate:       " << contacts[index].birthdate << "\n";
			std::cout << "favorite meal:   " << contacts[index].fav_meal << "\n";
			std::cout << "underwear color: " << contacts[index].clr_underwear << "\n";
			std::cout << "darkest secret:  " << contacts[index].secret << "\n";
			std::cout << "\e[0;34myou can use ADD to add a contact, SEARCH to search for a contact, and EXIT to exit my phonebook!\e[0;0m\n\n";
			return ;
		}
	}
}

/*
	this is the main loop where the commands will be redirected.
*/
int		main(void)
{
	static contact	contacts[8];
	int				amount;
    std::string		str;

	amount = 0;
    std::cout << "\e[0;34mWelcome to my awesome phonebook, you can use ADD to add a contact, SEARCH to search for a contact, and EXIT to exit my phonebook!\e[0;0m\n\n";
    while(1) {
		std::cin.clear();
		std::cin.sync();
		if (std::getline(std::cin, str).good() == 0)
			error("command");
		if (!str.compare("ADD")) {
			if (amount == 8) {
				std::cout << "\e[0;31mYou have reached the limit of my phonebook, you cannot add more contacts!\e[0;0m\n\n";
				continue ;
			}
			contacts->add_contact(&contacts[amount]);
			amount++;
		}
		else if (!str.compare("SEARCH"))
			contacts->search_contact(amount, contacts);
		else if (!str.compare("EXIT"))
			break ;
		else
			std::cout << "\n\e[0;31m" << str << ", is not a valid argument!\nplease try ADD, SEARCH or EXIT!\n\n\e[0;0m";
    }
	return (0);
}
