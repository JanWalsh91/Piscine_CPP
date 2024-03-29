#include "MindOpen.hpp"

MindOpen::MindOpen( void ) {}

MindOpen::MindOpen( std::string file ) : file(file), bracketDepth(0) {
}

MindOpen::MindOpen( MindOpen const & MindOpen ) {
	*this = MindOpen;
}

MindOpen::~MindOpen( void ) {}

MindOpen & MindOpen::operator=( MindOpen const & rhs ) {
	this->file = rhs.file;
	this->instructions = rhs.instructions;
	this->iPtr = rhs.iPtr;
	this->chars = rhs.chars;
	this->cPtr = rhs.fcPtr

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
		}
	}
	else {
		std::cout << "error" << std::endl;
	}
	this->matchBrackets();
	this->chars.push_back(0);
	this->cPtr = this->chars.begin();
	this->iPtr = this->instructions.begin();
}

void MindOpen::executeProgram( void ) {
	(*(this->iPtr))->execute( this->instructions, this->iPtr, this->chars, this->cPtr );
}

Instruction*	MindOpen::makeInstruction( char c ) {
	
	for ( int i = 0; i < 8 ; ++i ) {
		if ( c == this->availableInstructions[i] ) {
			Instruction * newInstruction = this->getInstruction[i](  );
			OpenLoop * open = dynamic_cast<OpenLoop *>(newInstruction);
			if ( open ) {
				open->setMatchIndex( ++(this->bracketDepth) );
			}
			CloseLoop * close = dynamic_cast<CloseLoop *>(newInstruction);
			if ( close ) {
				close->setMatchIndex( (this->bracketDepth)-- );
			}
			return newInstruction;
		}
	}
	return NULL;
}

void			MindOpen::matchBrackets( void ) {
	bool valid = true;
	for (std::vector<Instruction *>::iterator it = this->instructions.begin(); it != this->instructions.end(); ++it) {
		OpenLoop * open = dynamic_cast<OpenLoop *>( *it );
		if ( open ) {
			valid = false;
			for (std::vector<Instruction *>::iterator it2 = it; it2 != this->instructions.end(); ++it2) {
				CloseLoop * close = dynamic_cast<CloseLoop *>( *it2 );
				if ( close && open->getMatchIndex() == close->getMatchIndex() ) {
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