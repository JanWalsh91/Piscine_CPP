#ifndef PHONEBOOK_ENTRY_H
# define PHONEBOOK_ENTRY_H

#include <string>

class PhonebookEntry {
	public:
		int index;
		int isInit;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string login;
		std::string postalAddress;
		std::string emailAddress;
		std::string phoneNumber;
		std::string birthdayDate;
		std::string favoriteMeal;
		std::string underwearColor;
		std::string darkestSecret;
		void returnEntry( void ) const;
		void returnEntryFull( void ) const;
		PhonebookEntry( void ); 
		~PhonebookEntry( void ); 
};

#endif