#include "NinjaTrap.hpp"
#include <iostream>
#include <string>

NinjaTrap::NinjaTrap( std::string name ) : ClapTrap( name ) {
	this->_maxHitPoints = this->_hitPoints = 60;
	this->_maxEnergyPoints = this->_energyPoints = 120;
	this->_level = 1;
	this->_meleeDmg = 60;
	this->_rangedDmg = 5;
	this->_armor = 0;
	std::cout << "NINJ4-TP " << this->_name << " created ! " << std::endl;
	return ;
};

NinjaTrap::~NinjaTrap( void ) {
	std::cout << "NINJ4-TP " << this->_name << " destroyed ! " << std::endl;
	return ;
};

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
};

void NinjaTrap::ninjaShoebox( FragTrap & fragTrap ) {
	std::cout << "NINJ4-TP " << this->getName() << " puts " << fragTrap.getName() << " in a shoebox ! " << std::endl;
	return ;
};

void NinjaTrap::ninjaShoebox( ClapTrap & clapTrap ) {
	std::cout << "NINJ4-TP " << this->getName() << " hits " << clapTrap.getName() << " with a shoebox ! " << std::endl;
	return ;
};

void NinjaTrap::ninjaShoebox( NinjaTrap & ninjaTrap ) {
	std::cout << "NINJ4-TP " << this->getName() << " makes " << ninjaTrap.getName() << " dance on a shoebox ! " << std::endl;
	return ;
};
