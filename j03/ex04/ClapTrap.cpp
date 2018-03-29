#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap( void ) {};

ClapTrap::ClapTrap( std::string name ) : _name(name) {
	this->_initRand();
	std::cout << "ClapTrap under construction !" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & ClapTrap ) {
	this->_initRand();
	*this = ClapTrap;
	std::cout << "ClapTrap " << this->_name << "copied !" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap destroyed !" << std::endl;
}

ClapTrap &    ClapTrap::operator=( ClapTrap const & rhs ) {
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

int ClapTrap::_randInit = 0;

void	ClapTrap::_initRand( void ) {
	if ( ClapTrap::_randInit == 0 ) {
		std::srand(std::time(nullptr));
		ClapTrap::_randInit = 1;
	}
}

std::string ClapTrap::getName( void ) {
	return this->_name;
}

void ClapTrap::rangedAttack( std::string & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "CL4P-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "CL4P-TP " << this->_name << " attacks " << target << " at range with its unicorn gun blaster, causing " << this->_rangedDmg << " points of damage !" << std::endl;
}

void ClapTrap::meleeAttack( std::string & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "CL4P-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "CL4P-TP " << this->_name << " melee attacks " << target << " with its rainbow dagger, causing " << this->_meleeDmg << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage( unsigned int dmg ) {
	if (this->_hitPoints == 0) {
		std::cout << "CL4P-TP " << this->_name << " is being tickled to death ! " << std::endl;
		return ;
	}
	if ((int)dmg <= this->_armor) {
		std::cout << "CL4P-TP " << this->_name << " resists the dammage ! " << std::endl;
		return ;
	} 
	dmg = dmg - this->_armor;
	std::cout << "CL4P-TP " << this->_name << " takes " << dmg << " points of damage ! " << std::endl;
	this->_hitPoints -= dmg;
	if (this->_hitPoints <= 0) {
		std::cout << "CL4P-TP " << this->_name << " is KO'ed ! " << std::endl;
		this->_hitPoints = 0;
	}
}

void ClapTrap::beRepaired( unsigned int hitPoints ) {
	std::cout << "CL4P-TP " << this->_name << " is repaired for " << hitPoints << " points !" << std::endl;
	if (this->_hitPoints == 0) {
		std::cout << "CL4P-TP " << this->_name << " is back up !" << std::endl;
	}
	this->_hitPoints += hitPoints;
	if ( this->_hitPoints > this->_maxHitPoints ) {
		this->_hitPoints = this->_maxHitPoints;
	}
}