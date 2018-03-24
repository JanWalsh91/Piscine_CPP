#include "Phonebook.hpp"
#include "PhonebookEntry.hpp"

#include <iostream>

Phonebook::Phonebook( void ) {}

Phonebook::~Phonebook( void ) {}

void Phonebook::executeCommand( std::string command ) {
	if (command.compare("ADD") == 0) {
		this->_add();
	}
	else if (command.compare("SEARCH") == 0) {
		this->_search();
	}
	else {
		std::cout << "Invalid command: " << command << std::endl;
	}
}

void Phonebook::_add( void ) {
	std::cout << "Please enter the following information: " << std::endl;

	int index = this->_getIndexOfNextEmptyEntry();
	this->_entries[index].setIndex( index );
	
	if (index == 8) {
		std::cout << "Your phonebook is full!" << std::endl;
		return ;
	}


	std::string str = "";

	std::cout << "first name: ";
	getline(std::cin, str);
	this->_entries[index].setFirstName( str );

	std::cout << "last name: ";
	getline(std::cin, str);
	this->_entries[index].setLastName( str );
	
	std::cout << "nickanme: ";
	getline(std::cin, str);
	this->_entries[index].setNickname( str );
	
	std::cout << "login: ";
	getline(std::cin, str);
	this->_entries[index].setLogin( str );

	std::cout << "postal address: ";
	getline(std::cin, str);
	this->_entries[index].setPostalAddress( str );

	std::cout << "email address: ";
	getline(std::cin, str);
	this->_entries[index].setEmailAddress( str );

	std::cout << "phone number: ";
	getline(std::cin, str);
	this->_entries[index].setPhoneNumber( str );

	std::cout << "birthday date: ";
	getline(std::cin, str);
	this->_entries[index].setBirthdayDate( str );

	std::cout << "favorite meal: ";
	getline(std::cin, str);
	this->_entries[index].setFavoriteMeal( str );

	std::cout << "underwear color: ";
	getline(std::cin, str);
	this->_entries[index].setUnderwearColor( str );

	std::cout << "darkest secret: ";
	getline(std::cin, str);
	this->_entries[index].setDarkestSecret( str );

	this->_entries[index].setIsInit();
}

void Phonebook::_search( void ) const {
	int index = 0;
	if ( !this->_entries[index].isInit() ) {
		std::cout << "Your phonebook is empty" << std::endl;
		return ;
	}
	std::cout
		<< "index     |"
		<< "first name|"
		<< "last name |"
		<< "nickname  "
		<< std::endl;

	while ( this->_entries[index].isInit() ) {
		this->_entries[index].displayEntry();
		++index;
	}
	while (1) {
		std::cout << "Enter index of desired entry: ";
		std::string	entryIndex;

		getline(std::cin, entryIndex);
		if (!std::cin) {
			break ;
		}
		if (entryIndex.length() != 1 || isdigit(!entryIndex[0])) {
			std::cout << "Invalid index!" << std::endl;
			continue ;
		}
		index = entryIndex[0] - '0';
		if (index >= 0 && index < 8 && this->_entries[index].isInit() ) {
			this->_entries[index].displayEntryFull();
			break ;
		}
		else {
			std::cout << "Invalid index!" << std::endl;
			continue ;
		}
	}
}

int Phonebook::_getIndexOfNextEmptyEntry( void ) {
	int index = 0;

	while (index < 8) {
		if ( !this->_entries[index].isInit() ) {
			return index;
		}
		++index;
	}
	return 8;
};