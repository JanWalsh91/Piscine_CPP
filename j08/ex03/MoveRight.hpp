#ifndef MOVE_RIGHT_H
# define MOVE_RIGHT_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <list>

class MoveRight : public Instruction {

	public:
		MoveRight( void );
		MoveRight( MoveRight const & );
		~MoveRight( void );

		MoveRight & operator=( MoveRight const & rhs );

		void execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr );
};

#endif