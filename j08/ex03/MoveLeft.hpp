#ifndef MOVE_LEFT_H
# define MOVE_LEFT_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <vector>

class MoveLeft : public Instruction {

	public:
		MoveLeft( void );
		MoveLeft( MoveLeft const & );
		~MoveLeft( void );

		MoveLeft & operator=( MoveLeft const & rhs );

		void execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr );
};

#endif