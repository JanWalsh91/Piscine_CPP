#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "PhonebookEntry.hpp"

#include <string>

class Phonebook {
	
	public:
		Phonebook( void );
		~Phonebook( void );

		void			executeCommand( std::string command );

	private:
		PhonebookEntry	_entries[8];
		void			_add( void );
		void			_search( void ) const;

		int				_getIndexOfNextEmptyEntry( void );
};

#endif