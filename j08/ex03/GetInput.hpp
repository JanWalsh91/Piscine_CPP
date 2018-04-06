#ifndef GET_INPUT_H
# define GET_INPUT_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <vector>

class GetInput : public Instruction {

	public:
		GetInput( void );
		GetInput( GetInput const & );
		~GetInput( void );

		GetInput & operator=( GetInput const & rhs );

		void execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr );
};

#endif