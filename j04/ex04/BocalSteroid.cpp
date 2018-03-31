#include "BocalSteroid.hpp"

#include <iostream>

BocalSteroid::BocalSteroid( void ) {
	std::cout << "BocalSteroid created" << std::endl;
}

BocalSteroid::BocalSteroid( BocalSteroid const & bocalSteroid ) {
	std::cout << "Copy BocalSteroid" << std::endl;
	*this = bocalSteroid;
}

BocalSteroid::~BocalSteroid( void ) {
	std::cout << "BocalSteroid destroyed" << std::endl;
}

BocalSteroid &    BocalSteroid::operator=( BocalSteroid const & rhs ) {
	( void )rhs;
	return (*this);
}

std::string BocalSteroid::beMined( DeepCoreMiner* deepCoreMiner ) const {
	( void )deepCoreMiner;
	return "Zazium";
}

std::string BocalSteroid::beMined( StripMiner* stripMiner ) const {
	( void )stripMiner;
	return "Krpite";
}

std::string BocalSteroid::getName( void ) const {
	return ("BocalSteroid");
}