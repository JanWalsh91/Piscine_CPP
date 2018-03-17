#include "FragTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {
	this->_maxHitPoints = this->_hitPoints = 100;
	this->_maxEnergyPoints = this->_energyPoints = 100;
	this->_level = 1;
	this->_meleeDmg = 30;
	this->_rangedDmg = 20;
	this->_armor = 5;
	std::cout << "FR4G-TP " << this->_name << " created ! " << this->_hitPoints << std::endl;
	return ;
};

FragTrap::~FragTrap( void ) {
	std::cout << "FR4G-TP " << this->_name << " destroyed ! " << std::endl;
	return ;
};

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
};

void FragTrap::vaulthunter_dot_exe( std::string const & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "FR4G-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::string attackNames[] = {"Meat Unicycle", "Mechromagician", "Shhhh... Trap!", "Rubber Ducky", "Senseless Sacrifice"};
	std::string attackEffect[] = {"slashed to pieces !", "shot by a thousand bouncing bullets !", "unable to see his target !", "annoyed by the jumping rubber ducky !", "gasping as all his enemies come back to life !"};
	if (this->_energyPoints >= 25) {
		this->_energyPoints -= 25;
		int i = std::rand() % 5;
		std::cout << "FR4G-TP " << this->_name << " uses \"" << attackNames[i] << "\"! " << target << " is " << attackEffect[i] << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->_name << " is out of energy! :(" << std::endl;
};

void FragTrap::rangedAttack( std::string & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "FR4G-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedDmg << " points of damage !" << std::endl;
};

void FragTrap::meleeAttack( std::string & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "FR4G-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->_name << " melee attacks " << target << ", causing " << this->_meleeDmg << " points of damage !" << std::endl;
};