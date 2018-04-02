#include "TacticalMarine.hpp"

#include <iostream>

TacticalMarine::TacticalMarine( void ) {
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine( TacticalMarine const & tacticalMarine ) {
	std::cout << "Tactical Marine ready for battle (copy)" << std::endl;
	*this = tacticalMarine;
}

TacticalMarine::~TacticalMarine( void ) {
	std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine &    TacticalMarine::operator=( TacticalMarine const & rhs ) {
	( void )rhs;
	return (*this);
}

TacticalMarine*	TacticalMarine::clone( void ) const {
	std::cout << "Cloning Tactical Marine" << std::endl;
	return ( new TacticalMarine(*this) );
}

void TacticalMarine::battleCry( void ) const {
	std::cout << "For the holy PLOT !" << std::endl;
}

void TacticalMarine::rangedAttack( void ) const {
	std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack( void ) const {
	std::cout << "* attacks with chainsword *" << std::endl;
}
