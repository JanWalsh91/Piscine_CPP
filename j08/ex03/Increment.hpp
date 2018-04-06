#ifndef INCREMENT_H
# define INCREMENT_H

# include "Instruction.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <vector>

class Increment : public Instruction {

	public:
		Increment( void );
		Increment( Increment const & );
		~Increment( void );

		Increment & operator=( Increment const & rhs );

		virtual void execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr );
};

#endif