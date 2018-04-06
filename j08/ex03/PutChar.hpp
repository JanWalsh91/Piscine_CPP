#ifndef PUT_CHAR_H
# define PUT_CHAR_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <vector>

class PutChar : public Instruction {

	public:
		PutChar( void );
		PutChar( PutChar const & );
		~PutChar( void );

		PutChar & operator=( PutChar const & rhs );

		void execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr );
};

#endif