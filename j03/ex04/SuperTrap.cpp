#include "SuperTrap.hpp"

#include <iostream>
#include <string>

SuperTrap::SuperTrap( void ) {} ;

SuperTrap::SuperTrap( std::string name ) : ClapTrap ( name ), FragTrap( name ), NinjaTrap( name ) {
	this->_maxHitPoints = this->_hitPoints = 100;
	this->_maxEnergyPoints = this->_energyPoints = 120;
	this->_level = 1;
	this->_meleeDmg = 60;
	this->_rangedDmg = 20;
	this->_armor = 5;
	std::cout << "SUP3R-TP " << this->_name << " created ! " << std::endl;
}

SuperTrap::~SuperTrap( void ) {
	std::cout << "SUP3R-TP " << this->_name << " destroyed ! " << std::endl;
}

SuperTrap &    SuperTrap::operator=( SuperTrap const & rhs ) {
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

void SuperTrap::rangedAttack( std::string const & target ) {
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack( std::string const & target ) {
	NinjaTrap::rangedAttack(target);
}