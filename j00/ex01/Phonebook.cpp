#include <string>
#include <iostream>
#include "Phonebook.hpp"
#include "PhonebookEntry.hpp"

Phonebook::Phonebook( void ) {
	return ;
}

Phonebook::~Phonebook( void ) {
	return ;
}

void Phonebook::executeCommand( std::string command ) {
	std::cout << "executing command" << std::endl;
	if (command.compare("ADD") == 0) {
		this->add();
	}
	else if (command.compare("SEARCH") == 0) {
		this->search();
	}
	else {
		std::cout << "Invalid command: " << command << std::endl;
	}
};

void Phonebook::add( void ) {
	std::cout << "Please enter the following information: " << std::endl;

	int index = this->getIndexOfNextEmptyEntry();
	this->entries[index].index = index;
	
	if (index == 8) {
		std::cout << "Your phonebook is full!" << std::endl;
		return ;
	}

	std::cout << "first name: ";
	getline(std::cin, this->entries[index].firstName);

	std::cout << "last name: ";
	getline(std::cin, this->entries[index].lastName);

	std::cout << "nickanme: ";
	getline(std::cin, this->entries[index].nickname);

	std::cout << "login: ";
	getline(std::cin, this->entries[index].login);

	std::cout << "postal address: ";
	getline(std::cin, this->entries[index].postalAddress);

	std::cout << "email address: ";
	getline(std::cin, this->entries[index].emailAddress);

	std::cout << "phone number: ";
	getline(std::cin, this->entries[index].phoneNumber);

	std::cout << "birthday date: ";
	getline(std::cin, this->entries[index].birthdayDate);
	
	std::cout << "favorite meal: ";
	getline(std::cin, this->entries[index].favoriteMeal);
	
	std::cout << "underwear color: ";
	getline(std::cin, this->entries[index].underwearColor);
	
	std::cout << "darkest secret: ";
	getline(std::cin, this->entries[index].darkestSecret);
	this->entries[index].isInit = 1;
}

void Phonebook::search( void ) const {
	int index = 0;
	if (!this->entries[index].isInit) {
		std::cout << "Your phonebook is empty" << std::endl;
		return ;
	}
	std::cout
		<< "index     |"
		<< "first name|"
		<< "last name |"
		<< "nickname  "
		<< std::endl;

	while (this->entries[index].isInit) {
		this->entries[index].returnEntry();
		++index;
	}
	while (1) {
		std::cout << "Enter index of desired entry: ";
		std::string entryIndex;
		getline(std::cin, entryIndex);

		if (entryIndex.length() != 1 || isdigit(!entryIndex[0])) {
			std::cout << "Invalid index!" << std::endl;
			continue ;
		}
		index = entryIndex[0] - '0';
		if (index >= 0 && index < 8 && this->entries[index].isInit) {
			this->entries[index].returnEntryFull();
			break ;
		}
		else {
			std::cout << "Invalid index!" << std::endl;
			continue ;
		}
	}
}

int Phonebook::getIndexOfNextEmptyEntry( void ) {
	int index = 0;

	while (index < 8) {
		if (!this->entries[index].isInit) {
			return index;
		}
		++index;
	}
	return 8;
};