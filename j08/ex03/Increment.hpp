#ifndef INCREMENT_H
# define INCREMENT_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <list>

class Increment : public Instruction {

	public:
		Increment( void );
		Increment( Increment const & );
		~Increment( void );

		Increment & operator=( Increment const & rhs );

		virtual void execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr );
};

#endif