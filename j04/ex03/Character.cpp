#include "Character.hpp"
#include "AMateria.hpp"

#include <string>
#include <iostream>

Character::Character( void ) : name_("Nameless") {
	for ( int i = 0; i < 4; i++ ) {
		this->materia_[i] = NULL;
	}
}

Character::Character( std::string name ) : name_(name) {
	for ( int i = 0; i < 4; i++ ) {
		this->materia_[i] = NULL;
	}
}

Character::Character( Character const & character ) {
	*this = character;
}

Character::~Character( void ) {
	for ( int i = 0; i < 4; i++ ) {
		this->materia_[i] = NULL;
	}
}

Character &    Character::operator=( Character const & rhs ) {
	std::cout << "Copying character" << std::endl;
	for ( int i = 0; i < 4; i++ ) {
		this->materia_[i] = NULL;
		if ( rhs.materia_[i] != NULL ) {
			std::cout << "Copying materia" << std::endl;
			this->materia_[i] = rhs.materia_[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName( void ) const {
	return (this->name_);
}

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
}

void Character::unequip( int idx ) {
	if (idx < 0 || idx > 3 || !this->materia_[idx] ) {
		std::cout << "No Materia found in this pocket ! Can't unequip." << std::endl;
		return ;
	}
	this->materia_[idx] = NULL;
}

void Character::use( int idx, ICharacter& target ) {
	if (idx < 0 || idx > 3 || !this->materia_[idx] ) {
		std::cout << "No Materia found in this pocket ! Can't use." << std::endl;
		return ;
	}
	if ( this->materia_[idx] ) {
		this->materia_[idx]->use(target);
	}
}

