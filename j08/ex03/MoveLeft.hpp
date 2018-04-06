#ifndef MOVE_LEFT_H
# define MOVE_LEFT_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <list>

class MoveLeft : public Instruction {

	public:
		MoveLeft( void );
		MoveLeft( MoveLeft const & );
		~MoveLeft( void );

		MoveLeft & operator=( MoveLeft const & rhs );

		void execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr );
};

#endif