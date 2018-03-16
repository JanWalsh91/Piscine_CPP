#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"

#include <iostream>
#include <string>

Character::Character( std::string const & name ) : _name(name), _ap(40) {
	this->_weapon = NULL;
	return ;
};

Character::Character( void ) {
	this->_weapon = NULL;
	// std::cout << "Default constructor called" << std::endl;
	return ;
};

Character::Character( Character const & character ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = character;
	return ;
};

Character::~Character( void ) {
	return ;
};

Character &    Character::operator=( Character const & rhs ) {
	this->_name = rhs._name;
	this->_ap = rhs._ap;
	this->_weapon = rhs._weapon;
	return (*this);
};

void Character::recoverAP( void ) {
	this->_ap += 10;
	if ( this->_ap > 40 ) {
		this->_ap = 40; 
	}
};

void Character::equip( AWeapon* weapon ) {
	this->_weapon = weapon;
};

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
};

std::string Character::getName( void ) const {
	return (this->_name);
};

int Character::getAP( void ) const {
	return (this->_ap);
};

AWeapon* Character::getWeapon( void ) const {
	return (this->_weapon);
};

std::ostream& operator<<( std::ostream& os, const Character & character )
{
	os
		<< character.getName()
		<< " has "
		<< character.getAP();

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