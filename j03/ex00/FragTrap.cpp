#include "FragTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap( void ) {};

FragTrap::FragTrap( std::string name ) :
	_name(name),
	_maxHitPoints(100),
	_hitPoints(100),
	_maxEnergyPoints(100),
	_energyPoints(100),
	_level(1),
	_meleeDmg(30),
	_rangedDmg(20),
	_armor(5) {

	std::srand(std::time(nullptr));
	std::cout << "FR4G-TP " << this->_name << " created ! " << std::endl;
}

FragTrap::FragTrap( FragTrap const & FragTrap ) {
	std::srand(std::time(nullptr));
	*this = FragTrap;
	std::cout << "FR4G-TP " << this->_name << " copied ! " << std::endl;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FR4G-TP " << this->_name << " destroyed ! " << std::endl;
}

FragTrap &    FragTrap::operator=( FragTrap const & rhs ) {
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

void FragTrap::rangedAttack( std::string const & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "FR4G-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedDmg << " points of damage !" << std::endl;
}

void FragTrap::meleeAttack( std::string const & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "FR4G-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->_name << " melee attacks " << target << ", causing " << this->_meleeDmg << " points of damage !" << std::endl;
}

void FragTrap::takeDamage( unsigned int amount ) {
	if (this->_hitPoints == 0) {
		std::cout << "FR4G-TP " << this->_name << " is being pummeled to death ! " << std::endl;
		return ;
	}
	if ((int)amount <= this->_armor) {
		std::cout << "FR4G-TP " << this->_name << " resists the dammage ! " << std::endl;
		return ;
	} 
	amount = amount - this->_armor;
	std::cout << "FR4G-TP " << this->_name << " takes " << amount << " points of damage ! " << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0) {
		std::cout << "FR4G-TP " << this->_name << " is KO'ed ! " << std::endl;
		this->_hitPoints = 0;
	}
}

void FragTrap::beRepaired( unsigned int amount ) {
	std::cout << "FR4G-TP " << this->_name << " is repaired for " << amount << " points !" << std::endl;
	if (this->_hitPoints == 0) {
		std::cout << "FR4G-TP " << this->_name << " is back up !" << std::endl;
	}
	this->_hitPoints += amount;
	if ( this->_hitPoints > this->_maxHitPoints ) {
		this->_hitPoints = this->_maxHitPoints;
	}
}

void FragTrap::vaulthunter_dot_exe( std::string const & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "FR4G-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::string attackNames[] = {"Meat Unicycle", "Mechromagician", "Shhhh... Trap!", "Rubber Ducky", "Senseless Sacrifice"};
	std::string attackEffect[] = {
		"slashed to pieces and his arms turn to bacon !",
		"shot by a thousand bouncing bunny bullets !", 
		"blinded by bacon shadow and is unable to see his target !",
		"annoyed by the jumping rubber ducky !",
		"gasping flamboyantly as all his enemies come back to life !"
		};
	if (this->_energyPoints >= 25) {
		this->_energyPoints -= 25;
		int i = std::rand() % 5;
		std::cout << "FR4G-TP " << this->_name << " uses \"" << attackNames[i] << "\"! " << target << " is " << attackEffect[i] << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->_name << " is out of energy! :(" << std::endl;
}
