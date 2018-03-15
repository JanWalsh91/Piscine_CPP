#include "Human.hpp"
#include "Brain.hpp"
#include <string>

Human::Human( void ): _brain(new Brain) {
	return ;
}

Human::~Human( void ) {
	return ;
}

std::string Human::identify( void ) const {
	return this->_brain->identify();
}

Brain const & Human::getBrain( void ) const{
	Brain const & brainRef = *this->_brain;
	return brainRef;
}