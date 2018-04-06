#ifndef GET_INPUT_H
# define GET_INPUT_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <list>

class GetInput : public Instruction {

	public:
		GetInput( void );
		GetInput( GetInput const & );
		~GetInput( void );

		GetInput & operator=( GetInput const & rhs );

		void execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr );
};

#endif