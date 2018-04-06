#ifndef DECREMENT_H
# define DECREMENT_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <vector>

class Decrement : public Instruction {

	public:
		Decrement( void );
		Decrement( Decrement const & );
		~Decrement( void );

		Decrement & operator=( Decrement const & rhs );

		void execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr );
};

#endif