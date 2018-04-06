#ifndef CLOSE_LOOP_H
# define CLOSE_LOOP_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <vector>

class CloseLoop : public Instruction {

	public:
		CloseLoop( void );
		CloseLoop( CloseLoop const & );
		~CloseLoop( void );

		CloseLoop & operator=( CloseLoop const & rhs );

		void execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr );

		void setMatchIndex( int i );
		int  getMatchIndex( void ) const;
		void setMatch( std::vector<Instruction *>::iterator );
		std::vector<Instruction *>::iterator getMatch( void ) const;
	
	private:
		int matchIndex;
		std::vector<Instruction *>::iterator match;
};

#endif