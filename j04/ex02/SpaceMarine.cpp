// what should be in this file?

#include "ISpaceMarine.hpp"

#include <iostream>

// ISpaceMarine::ISpaceMarine( void ) {
// 	std::cout << "Default constructor called" << std::endl;
// 	return ;
// };

// ISpaceMarine::ISpaceMarine( ISpaceMarine const & iSpaceMarine ) {
// 	std::cout << "Copy constructor called" << std::endl;
// 	*this = iSpaceMarine;
// 	return ;
// };

ISpaceMarine::~ISpaceMarine( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
};

ISpaceMarine &    ISpaceMarine::operator=( ISpaceMarine const & rhs ) {
	// this->_i = rhs._i;
	return (*this);
};