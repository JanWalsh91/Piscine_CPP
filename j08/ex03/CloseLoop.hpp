#ifndef CLOSE_LOOP_H
# define CLOSE_LOOP_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <list>

class CloseLoop : public Instruction {

	public:
		CloseLoop( void );
		CloseLoop( CloseLoop const & );
		~CloseLoop( void );

		CloseLoop & operator=( CloseLoop const & rhs );

		void execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr );

		void setMatchIndex( int i );
		int  getMatchIndex( void ) const;
		void setMatch( std::list<Instruction *>::iterator );
		std::list<Instruction *>::iterator getMatch( void ) const;
	
	private:
		int matchIndex;
		std::list<Instruction *>::iterator match;
};

#endif