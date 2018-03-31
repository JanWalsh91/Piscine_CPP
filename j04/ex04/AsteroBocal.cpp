#include "AsteroBocal.hpp"

#include <iostream>

AsteroBocal::AsteroBocal( void ) {
	std::cout << "AsteroBocal created" << std::endl;
}

AsteroBocal::AsteroBocal( AsteroBocal const & asteroBocal ) {
	std::cout << "Copy AsteroBocal" << std::endl;
	*this = asteroBocal;
}

AsteroBocal::~AsteroBocal( void ) {
	std::cout << "AsteroBocal destroyed" << std::endl;
}

AsteroBocal &    AsteroBocal::operator=( AsteroBocal const & rhs ) {
	( void )rhs;
	return (*this);
}

std::string AsteroBocal::beMined( DeepCoreMiner* deepCoreMiner ) const {
	( void )deepCoreMiner;
	return "Thorite";
}

std::string AsteroBocal::beMined( StripMiner* stripMiner ) const {
	( void )stripMiner;
	return "Flavium";
}

std::string AsteroBocal::getName( void ) const {
	return ("AsteroBocal");
}