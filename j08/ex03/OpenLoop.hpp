#ifndef OPEN_LOOP_H
# define OPEN_LOOP_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <list>

class OpenLoop : public Instruction {

	public:
		OpenLoop( void );
		OpenLoop( OpenLoop const & );
		~OpenLoop( void );

		OpenLoop & operator=( OpenLoop const & rhs );

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