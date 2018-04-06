#include "MindOpen.hpp"

MindOpen::MindOpen( void ) {}

MindOpen::MindOpen( std::string file ) : file(file), bracketDepth(0) {
	// std::cout << "MindOpen construction: file: " << file << std::endl;
}

MindOpen::MindOpen( MindOpen const & MindOpen ) {
	*this = MindOpen;
}

MindOpen::~MindOpen( void ) {}

MindOpen & MindOpen::operator=( MindOpen const & rhs ) {
	( void )rhs;
	return *this;
}

void MindOpen::readFile( void ) {
	char c = 0;
	std::ifstream is(this->file);
	if ( is.is_open() ) {
		while (is >> std::noskipws >> c) {
			if (this->availableInstructions.find(c) != std::string::npos) {
				this->instructions.push_back( this->makeInstruction( c ) );
			}
			else {
				// std::cout << "skip" << std::endl;
			}
		}
	}
	else {
		std::cout << "error" << std::endl;
	}
	this->matchBrackets();
	this->chars.push_back(97);
	this->cPtr = this->chars.begin();
	this->iPtr = this->instructions.begin();
}

void MindOpen::executeProgram( void ) {
	// std::cout << "execute" << std::endl;
	this->chars.push_back(98);
	// this->cPtr++;
	std::cout << *cPtr << std::endl;
	// exit(0);
	(*(this->iPtr))->execute( this->instructions, this->iPtr, this->chars, this->cPtr );
}

Instruction*	MindOpen::makeInstruction( char c ) {
	// std::cout << "Make Instruction" << std::endl;
	
	for ( int i = 0; i < 8 ; ++i ) {
		if ( c == this->availableInstructions[i] ) {
			Instruction * newInstruction = this->getInstruction[i](  );
			OpenLoop * open = dynamic_cast<OpenLoop *>(newInstruction);
			if ( open ) {
				open->setMatchIndex( ++(this->bracketDepth) );
				// std::cout << "Found Open. Index: " << this->bracketDepth << std::endl;
			}
			CloseLoop * close = dynamic_cast<CloseLoop *>(newInstruction);
			if ( close ) {
				close->setMatchIndex( (this->bracketDepth)-- );
				// std::cout << "Found Close. Index: " << this->bracketDepth << std::endl;
			}
			// std::cout << "Created " << c << std::endl;
			return newInstruction;
		}
	}
	return NULL;
}

void			MindOpen::matchBrackets( void ) {
	// loop through until you find a Open Bracket
	bool valid = true;
	for (std::list<Instruction *>::iterator it = this->instructions.begin(); it != this->instructions.end(); ++it) {
		OpenLoop * open = dynamic_cast<OpenLoop *>( *it );
		if ( open ) {
			valid = false;
			// std::cout << "Found Open " << std::endl;
			for (std::list<Instruction *>::iterator it2 = it; it2 != this->instructions.end(); ++it2) {
				CloseLoop * close = dynamic_cast<CloseLoop *>( *it2 );
				if ( close && open->getMatchIndex() == close->getMatchIndex() ) {
					// std::cout << "Found Close " << std::endl;
					open->setMatch( it2 );
					close->setMatch( it );
					valid = true;
					break ;
				}
			}
			if ( !valid ) {
				std::cout << "INVALID" << std::endl;
				exit(0);
			}
		}
	}
}

Instruction* MindOpen::createMoveRight( void ) {
	return new MoveRight();
}
Instruction* MindOpen::createMoveLeft( void ) {
	return new MoveLeft();
}
Instruction* MindOpen::createIncrement( void ) {
	return new Increment();
}
Instruction* MindOpen::createDecrement( void ) {
	return new Decrement();
}
Instruction* MindOpen::createPutChar( void ) {
	return new PutChar();
}
Instruction* MindOpen::createOpenLoop( void ) {
	return new OpenLoop();
}
Instruction* MindOpen::createCloseLoop( void ) {
	return new CloseLoop();
}
Instruction* MindOpen::createGetInput( void ) {
	return new GetInput();
}

MindOpen::instructionGetter MindOpen::getInstruction[] = {
	&(MindOpen::createMoveRight),
	&(MindOpen::createMoveLeft),
	&(MindOpen::createIncrement),
	&(MindOpen::createDecrement),
	&(MindOpen::createPutChar),
	&(MindOpen::createOpenLoop),
	&(MindOpen::createCloseLoop),
	&(MindOpen::createGetInput)
};

const std::string MindOpen::availableInstructions = "><+-.[],";