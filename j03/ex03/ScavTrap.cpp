#include "ScavTrap.hpp"

#include <iostream>
#include <string>

ScavTrap::ScavTrap( void ) {} ;

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	this->_name = name;
	this->_maxHitPoints = this->_hitPoints = 100;
	this->_maxEnergyPoints = this->_energyPoints = 50;
	this->_level = 1;
	this->_meleeDmg = 20;
	this->_rangedDmg = 15;
	this->_armor = 3;
	std::cout << "SC4V-TP " << this->_name << " created ! Poof !" << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "SC4V-TP " << this->_name << " destroyed ! Poof ! " << std::endl;
}

void ScavTrap::challengeNewcomer( std::string const & target ) {
	if (this->_hitPoints == 0) {
		std::cout << "SC4V-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
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
	std::cout << "SC4V-TP " << this->_name << " challenges " << target << " " << challenge[i] << std::endl;
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