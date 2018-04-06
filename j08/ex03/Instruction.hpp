#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include <iostream>
# include <list>

class Instruction {

	public:
		Instruction( void );
		Instruction( Instruction const & );
		~Instruction( void );

		Instruction & operator=( Instruction const & rhs );

		virtual void execute( std::list<Instruction *> & instructions, std::list<Instruction *>::iterator & iPtr, std::list<char> & chars, std::list<char>::iterator & cPtr );
};

#endif