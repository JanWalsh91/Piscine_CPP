#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap( std::string name ) {
	std::srand(std::time(nullptr));
	this->_maxHitPoints = this->hitPoints = 100;
	this->_maxEnergyPoints = this->energyPoints = 50;
	this->level = 1;
	this->name = name;
	this->meleeDmg = 20;
	this->rangedDmg = 15;
	this->armor = 3;
	std::cout << "SC4V-TP " << this->name << " created ! Poof !" << std::endl;
	return ;
};

ScavTrap::ScavTrap( ScavTrap const & scavTrap ) {
	std::cout << "SC4V-TP " << this->name << " copied ! Poof ! " << std::endl;
	std::srand(std::time(nullptr));
	*this = scavTrap;
	return ;
};

ScavTrap::~ScavTrap( void ) {
	std::cout << "SC4V-TP " << this->name << " destroyed ! Poof ! " << std::endl;
	return ;
};

ScavTrap &    ScavTrap::operator=( ScavTrap const & rhs ) {
	this->_maxHitPoints = rhs._maxHitPoints;
	this->hitPoints = rhs.hitPoints;
	this->_maxEnergyPoints = rhs._maxEnergyPoints;
	this->energyPoints = rhs.energyPoints;
	this->level = rhs.level;
	this->name = rhs.name;
	this->meleeDmg = rhs.meleeDmg;
	this->rangedDmg = rhs.rangedDmg;
	this->armor = rhs.armor;
	return (*this);
};

void ScavTrap::rangedAttack(std::string & target) {
	if (this->hitPoints == 0) {
		std::cout << "SC4V-TP " << this->name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "SC4V-TP " << this->name << " attacks " << target << " at range with its unicorn gun blaster, causing " << this->rangedDmg << " points of damage !" << std::endl;
};

void ScavTrap::meleeAttack(std::string & target) {
	if (this->hitPoints == 0) {
		std::cout << "SC4V-TP " << this->name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "SC4V-TP " << this->name << " melee attacks " << target << " with its rainbow dagger, causing " << this->meleeDmg << " points of damage !" << std::endl;
};

void ScavTrap::takeDamage(unsigned int dmg) {
	if (this->hitPoints == 0) {
		std::cout << "SC4V-TP " << this->name << " is being tickled to death ! " << std::endl;
		return ;
	}
	std::cout << "SC4V-TP " << this->name << " takes " << dmg << " points of damage ! " << std::endl;
	this->hitPoints -= dmg;
	if (this->hitPoints <= 0) {
		std::cout << "SC4V-TP " << this->name << "is KO'ed ! " << std::endl;
		this->hitPoints = 0;
	}
};

void ScavTrap::beRepaired(unsigned int hitPoints) {
	std::cout << "SC4V-TP " << this->name << " is repaired for " << hitPoints << " points !" << std::endl;
	if (this->hitPoints == 0) {
		std::cout << "SC4V-TP " << this->name << " is back up !" << std::endl;
	}
	this->hitPoints += hitPoints;
	if ( this->hitPoints > this->_maxHitPoints ) {
		this->hitPoints = this->_maxHitPoints;
	}
};

void ScavTrap::challengeNewcomer(std::string const & target) {
	if (this->hitPoints == 0) {
		std::cout << "SC4V-TP " << this->name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::string challenge[] = {
		"chew on its toe!",
		"throw itself out the window!",
		"play rock paper scissors!",
		"inflate a rubber ducky!",
		"eat unicorn poop!"
		};

	int i = std::rand() % 5;
	std::cout << "SC4V-TP " << this->name << " challenges " << target << " " << challenge[i] << std::endl;

};