#include "Enemy.hpp"

#include <iostream>
#include <string>

Enemy::Enemy( void ) {
	return ;
};

Enemy::Enemy( int hp, std::string const & type ) : _hp(hp), _type(type) {
	return ;
};

Enemy::Enemy( Enemy const & enemy ) {
	*this = enemy;
	return ;
};

Enemy::~Enemy( void ) {
	return ;
};

Enemy &    Enemy::operator=( Enemy const & rhs ) {
	this->_type = rhs._type;
	this->_hp = rhs._hp;
	return (*this);
};

std::string Enemy::getType( void ) const {
	return (this->_type);
};

void Enemy::takeDamage( int damage ) {
	if (this->_hp < 0) {
		return ;
	}
	this->_hp -= damage;
};