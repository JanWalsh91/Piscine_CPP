#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include <iostream>
# include <vector>

class Instruction {

	public:
		Instruction( void );
		Instruction( Instruction const & );
		~Instruction( void );

		Instruction & operator=( Instruction const & rhs );

		virtual void execute( std::vector<Instruction *> & instructions, std::vector<Instruction *>::iterator & iPtr, std::vector<char> & chars, std::vector<char>::iterator & cPtr );
};

#endif