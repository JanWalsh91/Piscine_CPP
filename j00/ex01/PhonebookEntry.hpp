#ifndef PHONEBOOK_ENTRY_H
# define PHONEBOOK_ENTRY_H

#include <string>

class PhonebookEntry {
	private:
		int 		_isInit;
		int 		_index;
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _login;
		std::string _postalAddress;
		std::string _emailAddress;
		std::string _phoneNumber;
		std::string _birthdayDate;
		std::string _favoriteMeal;
		std::string _underwearColor;
		std::string _darkestSecret;

	public:
		PhonebookEntry( void ); 
		~PhonebookEntry( void ); 
		
		void displayEntry( void ) const;
		void displayEntryFull( void ) const;
		
		bool	isInit( void ) const;
		void	setIsInit( void );
		int		getIndex( void ) const;
		void	setIndex( int );

		void	setFirstName( std::string str ); 
		void	setLastName( std::string str ); 
		void	setNickname( std::string str ); 
		void	setLogin( std::string str ); 
		void	setPostalAddress( std::string str ); 
		void	setEmailAddress( std::string str ); 
		void	setPhoneNumber( std::string str ); 
		void	setBirthdayDate( std::string str ); 
		void	setFavoriteMeal( std::string str ); 
		void	setUnderwearColor( std::string str ); 
		void	setDarkestSecret( std::string str ); 

		std::string getFirstName( void ) const;
		std::string getLastName( void ) const;
		std::string getNickname( void ) const;
		std::string getLogin( void ) const;
		std::string getPostalAddress( void ) const;
		std::string getEmailAddress( void ) const;
		std::string getPhoneNumber( void ) const;
		std::string getBirthdayDate( void ) const;
		std::string getFavoriteMeal( void ) const;
		std::string getUnderwearColor( void ) const;
		std::string getDarkestSecret( void ) const;


};

#endif