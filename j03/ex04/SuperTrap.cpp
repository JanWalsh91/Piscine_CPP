#include "SuperTrap.hpp"

#include <iostream>
#include <string>

SuperTrap::SuperTrap( void ) {} ;

SuperTrap::SuperTrap( std::string name ) : ClapTrap (
	name,
	FragTrap::_defaultHitPoints,
	NinjaTrap::_defaultEnergyPoints,
	1,
	NinjaTrap::_defaultMeleeDmg,
	FragTrap::_defaultRangedDmg,
	FragTrap::_defaultArmor),
	FragTrap( name ),
	NinjaTrap( name ) {
	
	std::cout << "SUP3R-TP " << this->_name << " created ! " << std::endl;
}

SuperTrap::~SuperTrap( void ) {
	std::cout << "SUP3R-TP " << this->_name << " destroyed ! " << std::endl;
}

SuperTrap &    SuperTrap::operator=( SuperTrap const & rhs ) {
	ClapTrap::operator=( rhs );
	return (*this);
}

void SuperTrap::rangedAttack( std::string const & target ) const {
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack( std::string const & target ) const {
	NinjaTrap::rangedAttack(target);
}