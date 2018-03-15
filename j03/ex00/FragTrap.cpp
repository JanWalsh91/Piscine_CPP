#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap( std::string name ) {
	std::srand(std::time(nullptr));
	this->_maxHitPoints = this->hitPoints = 100;
	this->_maxEnergyPoints = this->energyPoints = 100;
	this->level = 1;
	this->name = name;
	this->meleeDmg = 30;
	this->rangedDmg = 20;
	this->armor = 5;
	std::cout << "FR4G-TP " << this->name << " created ! " << std::endl;
	return ;
};

FragTrap::FragTrap( FragTrap const & FragTrap ) {
	std::cout << "FR4G-TP " << this->name << " copied ! " << std::endl;
	std::srand(std::time(nullptr));
	*this = FragTrap;
	return ;
};

FragTrap::~FragTrap( void ) {
	std::cout << "FR4G-TP " << this->name << " destroyed ! " << std::endl;
	return ;
};

FragTrap &    FragTrap::operator=( FragTrap const & rhs ) {
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

void FragTrap::rangedAttack(std::string & target) {
	if (this->hitPoints == 0) {
		std::cout << "FR4G-TP " << this->name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->name << " attacks " << target << " at range, causing " << this->rangedDmg << " points of damage !" << std::endl;
};

void FragTrap::meleeAttack(std::string & target) {
	if (this->hitPoints == 0) {
		std::cout << "FR4G-TP " << this->name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->name << " melee attacks " << target << ", causing " << this->meleeDmg << " points of damage !" << std::endl;
};

void FragTrap::takeDamage(unsigned int dmg) {
	if (this->hitPoints == 0) {
		std::cout << "FR4G-TP " << this->name << " is being pummeled to death ! " << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->name << " takes " << dmg << " points of damage ! " << std::endl;
	this->hitPoints -= dmg;
	if (this->hitPoints <= 0) {
		std::cout << "FR4G-TP " << this->name << " is KO'ed ! " << std::endl;
		this->hitPoints = 0;
	}
};

void FragTrap::beRepaired(unsigned int hitPoints) {
	std::cout << "FR4G-TP " << this->name << " is repaired for " << hitPoints << " points !" << std::endl;
	if (this->hitPoints == 0) {
		std::cout << "FR4G-TP " << this->name << " is back up !" << std::endl;
	}
	this->hitPoints += hitPoints;
	if ( this->hitPoints > this->_maxHitPoints ) {
		this->hitPoints = this->_maxHitPoints;
	}
};

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->hitPoints == 0) {
		std::cout << "FR4G-TP " << this->name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::string attackNames[] = {"Meat Unicycle", "Mechromagician", "Shhhh... Trap!", "Rubber Ducky", "Senseless Sacrifice"};
	std::string attackEffect[] = {"slashed to pieces !", "shot by a thousand bouncing bullets !", "unable to see his target !", "annoyed by the jumping rubber ducky !", "gasping as all his enemies come back to life !"};
	if (this->energyPoints >= 25) {
		this->energyPoints -= 25;
		int i = std::rand() % 5;
		std::cout << "FR4G-TP " << this->name << " uses \"" << attackNames[i] << "\"! " << target << " is " << attackEffect[i] << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->name << " is out of energy! :(" << std::endl;
};