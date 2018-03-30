#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"

#include <iostream>
#include <string>

Character::Character( void ) : _weapon(NULL) {}

Character::Character( std::string const & name ) : _name(name), _ap(40), _weapon(NULL) {
	std::cout << "Creating character: " << this->_name << std::endl;
}

Character::Character( Character const & character ) {
	*this = character;
	std::cout << "Copying character: " << this->_name << std::endl;
}

Character::~Character( void ) {
	std::cout << "Destroying character " << this->_name << std::endl;
}

Character &    Character::operator=( Character const & rhs ) {
	this->_name = rhs._name;
	this->_ap = rhs._ap;
	this->_weapon = rhs._weapon;
	return (*this);
}

void Character::recoverAP( void ) {
	this->_ap += 10;
	if ( this->_ap > 40 ) {
		this->_ap = 40; 
	}
}

void Character::equip( AWeapon* weapon ) {
	this->_weapon = weapon;
}

void Character::attack( Enemy* enemy ) {
	if ( this->getWeapon() == NULL) {
		std::cout << this->getName() << " has no weapon !" << std::endl;
		return ;
	}
	if ( this->getAP() < this->getWeapon()->getAPCost() ) {
		std::cout << this->getName() << " does not have enough AP !" << std::endl;
		return ;
	}

	this->_ap -= this->getWeapon()->getAPCost();

	std::cout
		<< this->getName()
		<< " attacks "
		<< enemy->getType()
		<<  " with a "
		<< this->_weapon->getName()
		<< std::endl;

	this->_weapon->attack();
	enemy->takeDamage(this->getWeapon()->getDamage());
}

std::string const Character::getName( void ) const {
	return (this->_name);
}

int Character::getAP( void ) const {
	return (this->_ap);
}

AWeapon* Character::getWeapon( void ) const {
	return (this->_weapon);
}

std::ostream& operator<<( std::ostream& os, const Character & character )
{
	os
		<< character.getName()
		<< " has "
		<< character.getAP()
		<< " AP";

	if ( character.getWeapon() != NULL ) {
	os
		<< " and wields a "
		<< character.getWeapon()->getName()
		<< std::endl;
	}
	else {
	os
		<< " and is unarmed"
		<< std::endl;
	}
	
	return os;
}