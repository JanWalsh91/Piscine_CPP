#include "PhonebookEntry.hpp"

#include <iostream>

std::string truncateString( std::string str );

PhonebookEntry::PhonebookEntry( void ) : _isInit(0) {}

PhonebookEntry::~PhonebookEntry( void ) {}

void PhonebookEntry::displayEntry( void ) const {
	std::cout
		<< truncateString( std::to_string( this->getIndex() ) )
		<< '|'
		<< truncateString( this->getFirstName() )
		<< '|'
		<< truncateString( this->getLastName() )
		<< '|'
		<< truncateString( this->getNickname() )
		<< std::endl;
};

void PhonebookEntry::displayEntryFull( void ) const {
	std::cout
		<< "index: "
		<< std::to_string(this->getIndex())
		<< std::endl
		<< "first name: "
		<< this->getFirstName()
		<< std::endl
		<< "last name: "
		<< this->getLastName()
		<< std::endl
		<< "nickname: "
		<< this->getNickname()
		<< std::endl
		<< "login: "
		<< this->getLogin()
		<< std::endl
		<< "postal address: "
		<< this->getPostalAddress()
		<< std::endl
		<< "email address: "
		<< this->getEmailAddress()
		<< std::endl
		<< "phone number: "
		<< this->getPhoneNumber()
		<< std::endl
		<< "birthday date: "
		<< this->getBirthdayDate()
		<< std::endl
		<< "favorite meal: "
		<< this->getFavoriteMeal()
		<< std::endl
		<< "underwear color: "
		<< this->getUnderwearColor()
		<< std::endl
		<< "darkest secret: "
		<< this->getDarkestSecret()
		<< std::endl;
};

bool	PhonebookEntry::isInit( void ) const {
	return this->_isInit;
}

void	PhonebookEntry::setIsInit( void ) {
	this->_isInit = 1;
}

int		PhonebookEntry::getIndex( void ) const {
	return this->_index;
}

void	PhonebookEntry::setIndex( int i ) {
	this->_index = i;
}

void	PhonebookEntry::setFirstName( std::string str ) {
	this->_firstName = str;
}

void	PhonebookEntry::setLastName( std::string str ) {
	this->_lastName = str;
}

void	PhonebookEntry::setNickname( std::string str ) {
	this->_nickname = str;
}

void	PhonebookEntry::setLogin( std::string str ) {
	this->_login = str;
}

void	PhonebookEntry::setPostalAddress( std::string str ) {
	this->_postalAddress = str;
}

void	PhonebookEntry::setEmailAddress( std::string str ) {
	this->_emailAddress = str;
}

void	PhonebookEntry::setPhoneNumber( std::string str ) {
	this->_phoneNumber = str;
}

void	PhonebookEntry::setBirthdayDate( std::string str ) {
	this->_birthdayDate = str;
}

void	PhonebookEntry::setFavoriteMeal( std::string str ) {
	this->_favoriteMeal = str;
}

void	PhonebookEntry::setUnderwearColor( std::string str ) {
	this->_underwearColor = str;
}

void	PhonebookEntry::setDarkestSecret( std::string str ) {
	this->_darkestSecret = str;
}

std::string PhonebookEntry::getFirstName( void ) const {
	return this->_firstName;
}

std::string PhonebookEntry::getLastName( void ) const {
	return this->_lastName;
}

std::string PhonebookEntry::getNickname( void ) const {
	return this->_nickname;
}

std::string PhonebookEntry::getLogin( void ) const {
	return this->_login;
}

std::string PhonebookEntry::getPostalAddress( void ) const {
	return this->_postalAddress;
}

std::string PhonebookEntry::getEmailAddress( void ) const {
	return this->_emailAddress;
}

std::string PhonebookEntry::getPhoneNumber( void ) const {
	return this->_phoneNumber;
}

std::string PhonebookEntry::getBirthdayDate( void ) const {
	return this->_birthdayDate;
}

std::string PhonebookEntry::getFavoriteMeal( void ) const {
	return this->_favoriteMeal;
}

std::string PhonebookEntry::getUnderwearColor( void ) const {
	return this->_underwearColor;
}

std::string PhonebookEntry::getDarkestSecret( void ) const {
	return this->_darkestSecret;
}

std::string truncateString( std::string str ) {
	std::string str2 = "          ";
	str2.replace(0, str.length(), str.substr(0, 10));
	if ( str.length() > 10 ) {
		str2[9] = '.';
	}
	return ( str2 );
};