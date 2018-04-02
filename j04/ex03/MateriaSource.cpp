#include "MateriaSource.hpp"

#include <string>
#include <iostream>

MateriaSource::MateriaSource( void ) {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
	}
}

MateriaSource::MateriaSource( MateriaSource const & materiaSource ) {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
	}
	*this = materiaSource;
}

MateriaSource::~MateriaSource( void ) {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
	}
}

MateriaSource &    MateriaSource::operator=( MateriaSource const & rhs ) {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
		this->materia_[i] = rhs.materia_[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria( AMateria* m ) {
	int i = 0;
	if ( m == NULL) {
		std::cout << "You need to give me a materia for me to learn." << std::endl;
		return ;
	}
	while ( i < 4 ) {
		if ( this->materia_[i] == NULL ) {
			std::cout << "I just learned " << m->getType() << "(" << i << ")" << std::endl;
			this->materia_[i] = m;
			return ;
		}
		++i;
	}
	std::cout << "I can only learn 4 materia types." << std::endl;
}

AMateria* MateriaSource::createMateria( std::string const & type ) {
	int i = 0;

	if ( type == "" ) {
		std::cout << "I don't know this type !" << std::endl;
		return 0;
	}
	while ( i < 4 ) {
		if ( this->materia_[i] && this->materia_[i]->getType() == type ) {
			return this->materia_[i]->clone();
		}
		++i;
	}
	std::cout << "I don't know this type !" << std::endl;
	return 0;
}
