#include "PhonebookEntry.hpp"

#include <iostream>

std::string truncateString( std::string str );

PhonebookEntry::PhonebookEntry( void ) : isInit(0) {}

PhonebookEntry::~PhonebookEntry( void ) {}

void PhonebookEntry::returnEntry( void ) const {
	std::cout
		<< truncateString( std::to_string(this->index) )
		<< '|'
		<< truncateString( this->firstName )
		<< '|'
		<< truncateString( this->lastName )
		<< '|'
		<< truncateString( this->nickname )
		<< std::endl;
};

void PhonebookEntry::returnEntryFull( void ) const {
	std::cout
		<< "index: "
		<< std::to_string(this->index)
		<< std::endl
		<< "first name: "
		<< this->firstName
		<< std::endl
		<< "last name: "
		<< this->lastName
		<< std::endl
		<< "nickname: "
		<< this->nickname
		<< std::endl
		<< "login: "
		<< this->login
		<< std::endl
		<< "postal address: "
		<< this->postalAddress
		<< std::endl
		<< "email address: "
		<< this->emailAddress
		<< std::endl
		<< "phone number: "
		<< this->phoneNumber
		<< std::endl
		<< "birthday date: "
		<< this->birthdayDate
		<< std::endl
		<< "favorite meal: "
		<< this->favoriteMeal
		<< std::endl
		<< "underwear color: "
		<< this->underwearColor
		<< std::endl
		<< "darkest secret: "
		<< this->darkestSecret
		<< std::endl;
};

std::string truncateString( std::string str ) {
	std::string str2 = "          ";
	str2.replace(0, str.length(), str.substr(0, 10));
	if ( str.length() > 10 ) {
		str2[9] = '.';
	}
	return ( str2 );
};