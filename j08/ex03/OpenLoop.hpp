#ifndef OPEN_LOOP_H
# define OPEN_LOOP_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <vector>

class OpenLoop : public Instruction {

	public:
		OpenLoop( void );
		OpenLoop( OpenLoop const & );
		~OpenLoop( void );

		OpenLoop & operator=( OpenLoop const & rhs );

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