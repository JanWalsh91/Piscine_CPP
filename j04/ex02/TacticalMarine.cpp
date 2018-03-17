#include "TacticalMarine.hpp"

#include <iostream>

TacticalMarine::TacticalMarine( void ) {
	std::cout << "Tactical Marine ready for battle" << std::endl;
	return ;
};

TacticalMarine::TacticalMarine( TacticalMarine const & tacticalMarine ) {
	std::cout << "Copy: Tactical Marine ready for battle" << std::endl;
	*this = tacticalMarine;
	return ;
};

TacticalMarine::~TacticalMarine( void ) {
	std::cout << "Aaargh ..." << std::endl;
	return ;
};

TacticalMarine &    TacticalMarine::operator=( TacticalMarine const & rhs ) {
	// *this = rhs;
	( void )rhs;
	return (*this);
};

TacticalMarine*	TacticalMarine::clone( void ) const {
	return ( new TacticalMarine(*this) );
};

void TacticalMarine::battleCry( void ) const {
	std::cout << "For the holy PLOT !" << std::endl;
};

void TacticalMarine::rangedAttack( void ) const {
	std::cout << "* attacks with bolter *" << std::endl;
};

void TacticalMarine::meleeAttack( void ) const {
	std::cout << "* attacks with chainsword *" << std::endl;
};
