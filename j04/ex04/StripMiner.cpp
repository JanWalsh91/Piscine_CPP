#include "StripMiner.hpp"
#include "IAsteroid.hpp"

#include <iostream>

StripMiner::StripMiner( void ) {
	std::cout << "StripMiner created" << std::endl;
	return ;
};

StripMiner::StripMiner( StripMiner const & stripMiner ) {
	std::cout << "Copy StripMiner" << std::endl;
	*this = stripMiner;
	return ;
};

StripMiner::~StripMiner( void ) {
	std::cout << "StripMiner destroyed" << std::endl;
	return ;
};

StripMiner &    StripMiner::operator=( StripMiner const & rhs ) {
	( void )rhs;
	return (*this);
};

void StripMiner::mine( IAsteroid* asteroid ) {
	std::cout << "Trageting " << asteroid->getName() << " * strip mining ... got " << asteroid->beMined(this) << " ! *" << std::endl;
};