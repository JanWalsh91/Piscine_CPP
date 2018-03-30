#include "NinjaTrap.hpp"

#include <iostream>
#include <string>

const int NinjaTrap::_defaultHitPoints = 60;
const int NinjaTrap::_defaultEnergyPoints = 120;
const int NinjaTrap::_defaultLevel = 1;
const int NinjaTrap::_defaultMeleeDmg = 60;
const int NinjaTrap::_defaultRangedDmg = 5;
const int NinjaTrap::_defaultArmor = 0;

NinjaTrap::NinjaTrap( void ) {};

NinjaTrap::NinjaTrap( std::string name ) : ClapTrap(
	name,
	NinjaTrap::_defaultHitPoints,
	NinjaTrap::_defaultEnergyPoints,
	NinjaTrap::_defaultLevel,
	NinjaTrap::_defaultMeleeDmg,
	NinjaTrap::_defaultRangedDmg,
	NinjaTrap::_defaultArmor ) {
	
	std::cout << "NINJ4-TP " << this->_name << " created ! " << std::endl;
}

NinjaTrap::~NinjaTrap( void ) {
	std::cout << "NINJ4-TP " << this->_name << " destroyed ! " << std::endl;
}

NinjaTrap::NinjaTrap( NinjaTrap const & ninjaTrap ) {
	std::srand(std::time(nullptr));
	*this = ninjaTrap;
	std::cout << "NINJ4-TP " << this->_name << " copied ! Hehehe ... ! " << std::endl;
}

NinjaTrap &    NinjaTrap::operator=( NinjaTrap const & rhs ) {
	ClapTrap::operator=( rhs );
	return (*this);
}

void NinjaTrap::rangedAttack( std::string const & target ) const {
	if (this->_hitPoints == 0) {
		std::cout << "NINJ4-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "NINJ4-TP " << this->_name << " attacks " << target << " at range with crossbow, causing " << this->_rangedDmg << " points of damage !" << std::endl;
}

void NinjaTrap::meleeAttack( std::string const & target ) const {
	if (this->_hitPoints == 0) {
		std::cout << "NINJ4-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "NINJ4-TP " << this->_name << " melee attacks " << target << " with its poison daggers, causing " << this->_meleeDmg << " points of damage !" << std::endl;
}

void NinjaTrap::ninjaShoebox( FragTrap & fragTrap ) const {
	std::cout << "NINJ4-TP " << this->getName() << " puts " << fragTrap.getName() << " in a shoebox ! " << std::endl;
}

void NinjaTrap::ninjaShoebox( ClapTrap & clapTrap ) const {
	std::cout << "NINJ4-TP " << this->getName() << " hits " << clapTrap.getName() << " with a shoebox ! " << std::endl;
}

void NinjaTrap::ninjaShoebox( NinjaTrap & ninjaTrap ) const {
	std::cout << "NINJ4-TP " << this->getName() << " makes " << ninjaTrap.getName() << " dance on a shoebox ! " << std::endl;
}

void NinjaTrap::ninjaShoebox( ScavTrap & scavTrap ) const {
	std::cout << "NINJ4-TP " << this->getName() << " throws the shoebox at " << scavTrap.getName() << ". Ouch ! " << std::endl;
}

void NinjaTrap::ninjaShoebox( SuperTrap & superTrap ) const {
	std::cout << "NINJ4-TP " << this->getName() << " throws the shoebox at " << superTrap.getName() << ". Ouch ! " << std::endl;
}
