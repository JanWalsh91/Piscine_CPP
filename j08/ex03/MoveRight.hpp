#ifndef MOVE_RIGHT_H
# define MOVE_RIGHT_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <vector>

class MoveRight : public Instruction {

	public:
		MoveRight( void );
		MoveRight( MoveRight const & );
		~MoveRight( void );

		MoveRight & operator=( MoveRight const & rhs );

		void execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr );
};

#endif