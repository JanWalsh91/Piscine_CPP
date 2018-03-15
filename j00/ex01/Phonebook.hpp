#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>
#include "PhonebookEntry.hpp"

class Phonebook {
	
	public:
		Phonebook( void );
		~Phonebook( void );

		void executeCommand( std::string command );

	private:
		PhonebookEntry entries[8];
		void add( void );
		void search( void ) const;

		int getIndexOfNextEmptyEntry( void );
};

#endif