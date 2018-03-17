#include "Character.hpp"
#include "AMateria.hpp"

#include <string>

Character::Character( void ) : name_("") {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
	}
	return ;
};

Character::Character( std::string name ) : name_(name) {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
	}
	return ;
};

Character::Character( Character const & character ) {
	*this = character;
	return ;
};

Character::~Character( void ) {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
	}
	return ;
};

Character &    Character::operator=( Character const & rhs ) {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
		this->materia_[i] = rhs.materia_[i];
	}
	return (*this);
};

std::string const & Character::getName( void ) const {
	return (this->name_);
};

void Character::equip( AMateria* m ) {
	int i = 0;
	if ( m == NULL) {
		return ;
	}
	while ( i < 4 ) {
		if ( this->materia_[i] == NULL ) {
			this->materia_[i] = m;
			return ;
		}
		++i;
	}
};

void Character::unequip( int idx ) {
	if (idx < 0 || idx > 3) {
		return ;
	}
	this->materia_[idx] = NULL;
};

void Character::use( int idx, ICharacter& target ) {
	if (idx < 0 || idx > 3) {
		return ;
	}
	this->materia_[idx]->use(target);
};

