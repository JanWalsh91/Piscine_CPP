#ifndef MIND_OPEN_H
# define MIND_OPEN_H

# include "Instruction.hpp"
# include "MoveRight.hpp"
# include "MoveLeft.hpp"
# include "Increment.hpp"
# include "Decrement.hpp"
# include "PutChar.hpp"
# include "OpenLoop.hpp"
# include "CloseLoop.hpp"
# include "GetInput.hpp"

# include <string>
# include <iostream>
# include <fstream>
# include <vector>

class MindOpen {
	private:
		MindOpen( void );
		std::string							file;
		std::vector<Instruction *> 			instructions;
		std::vector<Instruction *>::iterator	iPtr;
		std::vector<char>						chars;
		std::vector<char>::iterator			cPtr;

		void			matchBrackets( void );

		Instruction*	makeInstruction( char c );
		
		static Instruction* createMoveRight( void );
		static Instruction* createMoveLeft( void );
		static Instruction* createIncrement( void );
		static Instruction* createDecrement( void );
		static Instruction* createPutChar( void );
		static Instruction* createOpenLoop( void );
		static Instruction* createCloseLoop( void );
		static Instruction* createGetInput( void );
		
		typedef Instruction* ( *instructionGetter )( void );
		static	instructionGetter getInstruction[];

		static const std::string availableInstructions;

		int bracketDepth;
	public:
		MindOpen( std::string file );
		MindOpen( MindOpen const & );
		~MindOpen( void );

		MindOpen & operator=( MindOpen const & rhs );

		void readFile( void );
		void executeProgram( void );
};

#endif