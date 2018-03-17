#include "IMiningLaser.hpp"

#include <iostream>

IMiningLaser::IMiningLaser( void ) {
	// std::cout << "Default constructor called" << std::endl;
	return ;
};

IMiningLaser::IMiningLaser( IMiningLaser const & iMiningLaser ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = iMiningLaser;
	return ;
};

IMiningLaser &    IMiningLaser::operator=( IMiningLaser const & rhs ) {
	( void )rhs;
	return (*this);
};