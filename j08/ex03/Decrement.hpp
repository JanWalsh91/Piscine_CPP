#ifndef DECREMENT_H
# define DECREMENT_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <list>

class Decrement : public Instruction {

	public:
		Decrement( void );
		Decrement( Decrement const & );
		~Decrement( void );

		Decrement & operator=( Decrement const & rhs );

		void execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr );
};

#endif