#include "ScavTrap.hpp"

#include <iostream>
#include <string>

ScavTrap::ScavTrap( void ) {} ;

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name, 100, 50, 1, 20, 15, 3) {
	std::cout << "SC4V-TP " << this->_name << " created ! Poof !" << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "SC4V-TP " << this->_name << " destroyed ! Poof ! " << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & scavTrap ) {
	std::srand(std::time(nullptr));
	*this = scavTrap;
	std::cout << "SC4V-TP " << this->_name << " copied ! Poof ! " << std::endl;
}

ScavTrap &    ScavTrap::operator=( ScavTrap const & rhs ) {
	ClapTrap::operator=( rhs );
	return (*this);
}

void ScavTrap::challengeNewcomer( std::string const & target ) const {
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

void ScavTrap::rangedAttack( std::string const & target ) const {
	if (this->_hitPoints == 0) {
		std::cout << "SC4V-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at range with its unicorn gun blaster, causing " << this->_rangedDmg << " points of damage !" << std::endl;
}

void ScavTrap::meleeAttack( std::string const & target ) const {
	if (this->_hitPoints == 0) {
		std::cout << "SC4V-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "SC4V-TP " << this->_name << " melee attacks " << target << " with its rainbow dagger, causing " << this->_meleeDmg << " points of damage !" << std::endl;
}