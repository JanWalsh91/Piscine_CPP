#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"

#include <iostream>

DeepCoreMiner::DeepCoreMiner( void ) {
	std::cout << "DeepCoreMiner created" << std::endl;
}

DeepCoreMiner::DeepCoreMiner( DeepCoreMiner const & deepCoreMiner ) {
	std::cout << "Copy DeepCoreMiner" << std::endl;
	*this = deepCoreMiner;
}

DeepCoreMiner::~DeepCoreMiner( void ) {
	std::cout << "DeepCoreMiner destroyed" << std::endl;
}

DeepCoreMiner &    DeepCoreMiner::operator=( DeepCoreMiner const & rhs ) {
	( void )rhs;
	return (*this);
}

void DeepCoreMiner::mine( IAsteroid* asteroid ) {
	std::cout << "Trageting " << asteroid->getName() << " * mining deep ... got " << asteroid->beMined(this) << " ! *" << std::endl;
}