#ifndef PUT_CHAR_H
# define PUT_CHAR_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <list>

class PutChar : public Instruction {

	public:
		PutChar( void );
		PutChar( PutChar const & );
		~PutChar( void );

		PutChar & operator=( PutChar const & rhs );

		void execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr );
};

#endif