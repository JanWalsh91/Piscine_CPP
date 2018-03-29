#include "NinjaTrap.hpp"
#include <iostream>
#include <string>

NinjaTrap::NinjaTrap( void ) {};

NinjaTrap::NinjaTrap( std::string name ) : ClapTrap( name ) {
	this->_maxHitPoints = this->_hitPoints = 60;
	this->_maxEnergyPoints = this->_energyPoints = 120;
	this->_level = 1;
	this->_meleeDmg = 60;
	this->_rangedDmg = 5;
	this->_armor = 0;
	std::cout << "NINJ4-TP " << this->_name << " created ! Hehehe ..." << std::endl;
}

NinjaTrap::~NinjaTrap( void ) {
	std::cout << "NINJ4-TP " << this->_name << " destroyed ! Splat !" << std::endl;
}

NinjaTrap &    NinjaTrap::operator=( NinjaTrap const & rhs ) {
	this->_maxHitPoints = rhs._maxHitPoints;
	this->_hitPoints = rhs._hitPoints;
	this->_maxEnergyPoints = rhs._maxEnergyPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_level = rhs._level;
	this->_name = rhs._name;
	this->_meleeDmg = rhs._meleeDmg;
	this->_rangedDmg = rhs._rangedDmg;
	this->_armor = rhs._armor;
	return (*this);
}

void NinjaTrap::rangedAttack( std::string & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "NINJ4-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "NINJ4-TP " << this->_name << " attacks " << target << " at range with crossbow, causing " << this->_rangedDmg << " points of damage !" << std::endl;
}

void NinjaTrap::meleeAttack( std::string & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "NINJ4-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "NINJ4-TP " << this->_name << " melee attacks " << target << " with its poison daggers, causing " << this->_meleeDmg << " points of damage !" << std::endl;
}

void NinjaTrap::ninjaShoebox( FragTrap & fragTrap ) {
	std::cout << "NINJ4-TP " << this->getName() << " puts " << fragTrap.getName() << " in a shoebox ! " << std::endl;
}

void NinjaTrap::ninjaShoebox( ClapTrap & clapTrap ) {
	std::cout << "NINJ4-TP " << this->getName() << " hits " << clapTrap.getName() << " with a shoebox ! " << std::endl;
}

void NinjaTrap::ninjaShoebox( NinjaTrap & ninjaTrap ) {
	std::cout << "NINJ4-TP " << this->getName() << " makes " << ninjaTrap.getName() << " dance on a shoebox ! " << std::endl;
}

void NinjaTrap::ninjaShoebox( ScavTrap & scavTrap ) {
	std::cout << "NINJ4-TP " << this->getName() << " throws the shoebox at " << scavTrap.getName() << ". Ouch ! " << std::endl;
}

