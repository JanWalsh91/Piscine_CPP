#include "Enemy.hpp"

#include <iostream>
#include <string>

Enemy::Enemy( void ) {}

Enemy::Enemy( int hp, std::string const & type ) : _hp(hp), _type(type) {
	std::cout << "Creating enemy: " << "Type: " << this->getType() << ". HP: " << this->getHP() << std::endl;
}

Enemy::Enemy( Enemy const & enemy ) {
	*this = enemy;
	std::cout << "Copying enemy: " << this->getType() << std::endl;
}

Enemy::~Enemy( void ) {
	std::cout << "Destroying enemy: " << this->getType() << std::endl;
}

Enemy &    Enemy::operator=( Enemy const & rhs ) {
	this->_type = rhs._type;
	this->_hp = rhs._hp;
	return (*this);
}

std::string const Enemy::getType( void ) const {
	return (this->_type);
}

int Enemy::getHP( void ) const {
	return (this->_hp);
}

void Enemy::takeDamage( int damage ) {
	if (this->_hp < 0) {
		return ;
	}
	this->_hp -= damage;
}