#include "ScavTrap.hpp"

#include <iostream>
#include <string>

ScavTrap::ScavTrap( void ) {} ;

ScavTrap::ScavTrap( std::string name ) :
	_name(name),
	_maxHitPoints(100),
	_hitPoints(100),
	_maxEnergyPoints(50),
	_energyPoints(50),
	_level(1),
	_meleeDmg(20),
	_rangedDmg(15),
	_armor(3) {

	std::srand(std::time(nullptr));

	std::cout << "SC4V-TP " << this->_name << " created ! Poof !" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & scavTrap ) {
	std::srand(std::time(nullptr));
	*this = scavTrap;
	std::cout << "SC4V-TP " << this->_name << " copied ! Poof ! " << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "SC4V-TP " << this->_name << " destroyed ! Poof ! " << std::endl;
}

ScavTrap &    ScavTrap::operator=( ScavTrap const & rhs ) {
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

void ScavTrap::rangedAttack( std::string const & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "SC4V-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at range with its unicorn gun blaster, causing " << this->_rangedDmg << " points of damage !" << std::endl;
}

void ScavTrap::meleeAttack( std::string const & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "SC4V-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "SC4V-TP " << this->_name << " melee attacks " << target << " with its rainbow dagger, causing " << this->_meleeDmg << " points of damage !" << std::endl;
}

void ScavTrap::takeDamage( unsigned int amount ) {
	if (this->_hitPoints == 0) {
		std::cout << "SC4V-TP " << this->_name << " is being tickled to death ! " << std::endl;
		return ;
	}
	if ((int)amount <= this->_armor) {
		std::cout << "SC4V-TP " << this->_name << " resists the dammage ! " << std::endl;
		return ;
	} 
	amount = amount - this->_armor;
	std::cout << "SC4V-TP " << this->_name << " takes " << amount << " points of damage ! " << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0) {
		std::cout << "SC4V-TP " << this->_name << "is KO'ed ! " << std::endl;
		this->_hitPoints = 0;
	}
}

void ScavTrap::beRepaired( unsigned int amount ) {
	std::cout << "SC4V-TP " << this->_name << " is repaired for " << amount << " points !" << std::endl;
	if (this->_hitPoints == 0) {
		std::cout << "SC4V-TP " << this->_name << " is back up !" << std::endl;
	}
	this->_hitPoints += amount;
	if ( this->_hitPoints > this->_maxHitPoints ) {
		this->_hitPoints = this->_maxHitPoints;
	}
}

void ScavTrap::challengeNewcomer( std::string const & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "SC4V-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::string challenge[] = {
		"to chew on its toe!",
		"tp throw itself out the window!",
		"to play rock paper scissors!",
		"to inflate a rubber ducky!",
		"to eat unicorn poop!"
		};

	int i = std::rand() % 5;
	std::cout << "SC4V-TP " << this->_name << " challenges " << target << " " << challenge[i] << std::endl;
}
