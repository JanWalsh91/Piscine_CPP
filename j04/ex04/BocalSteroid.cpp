#include "BocalSteroid.hpp"

#include <iostream>

BocalSteroid::BocalSteroid( void ) {
	std::cout << "BocalSteroid created" << std::endl;
	return ;
};

BocalSteroid::BocalSteroid( BocalSteroid const & bocalSteroid ) {
	std::cout << "Copy BocalSteroid" << std::endl;
	*this = bocalSteroid;
	return ;
};

BocalSteroid::~BocalSteroid( void ) {
	std::cout << "BocalSteroid destroyed" << std::endl;
	return ;
};

BocalSteroid &    BocalSteroid::operator=( BocalSteroid const & rhs ) {
	( void )rhs;
	return (*this);
};

std::string BocalSteroid::beMined( IAsteroid* asteroid ) const {
	( void )asteroid;
	return "Zazium";
};

std::string BocalSteroid::beMined( IMiningLaser* miningLaser ) const {
	( void )miningLaser;
	return "Krpite";
};

std::string BocalSteroid::getName( void ) const {
	return ("BocalSteroid");
};