#include "FragTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap( void ) {};

FragTrap::FragTrap( std::string name ) : ClapTrap( name, 100, 100, 1, 30, 20, 5 ) {
	std::cout << "FR4G-TP " << this->_name << " created ! " << std::endl;
	return ;
};

FragTrap::~FragTrap( void ) {
	std::cout << "FR4G-TP " << this->_name << " destroyed ! " << std::endl;
	return ;
};

FragTrap::FragTrap( FragTrap const & FragTrap ) {
	std::srand(std::time(nullptr));
	*this = FragTrap;
	std::cout << "FR4G-TP " << this->_name << " copied ! " << std::endl;
}

FragTrap &    FragTrap::operator=( FragTrap const & rhs ) {
	ClapTrap::operator=( rhs );
	return (*this);
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
};

void FragTrap::rangedAttack( std::string const & target ) const {
	if (this->_hitPoints == 0) {
		std::cout << "FR4G-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedDmg << " points of damage !" << std::endl;
};

void FragTrap::meleeAttack( std::string const & target ) const {
	if (this->_hitPoints == 0) {
		std::cout << "FR4G-TP " << this->_name << " is KO'ed and can't attack ! " << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << this->_name << " melee attacks " << target << ", causing " << this->_meleeDmg << " points of damage !" << std::endl;
};