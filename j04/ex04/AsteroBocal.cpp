#include "AsteroBocal.hpp"

#include <iostream>

AsteroBocal::AsteroBocal( void ) {
	std::cout << "AsteroBocal created" << std::endl;
	return ;
};

AsteroBocal::AsteroBocal( AsteroBocal const & asteroBocal ) {
	std::cout << "Copy AsteroBocal" << std::endl;
	*this = asteroBocal;
	return ;
};

AsteroBocal::~AsteroBocal( void ) {
	std::cout << "AsteroBocal destroyed" << std::endl;
	return ;
};

AsteroBocal &    AsteroBocal::operator=( AsteroBocal const & rhs ) {
	( void )rhs;
	return (*this);
};

std::string AsteroBocal::beMined( IAsteroid* asteroid ) const {
	( void )asteroid;
	return "Thorite";
};

std::string AsteroBocal::beMined( IMiningLaser* miningLaser ) const {
	( void )miningLaser;
	return "Flavium";
};

std::string AsteroBocal::getName( void ) const {
	return ("AsteroBocal");
};