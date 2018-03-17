#include "MateriaSource.hpp"

#include <string>

MateriaSource::MateriaSource( void ) {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
	}
	return ;
};

MateriaSource::MateriaSource( MateriaSource const & materiaSource ) {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
	}
	*this = materiaSource;
	return ;
};

MateriaSource::~MateriaSource( void ) {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
	}
	return ;
};

MateriaSource &    MateriaSource::operator=( MateriaSource const & rhs ) {
	for ( int i = 0; i < 4; i ++ ) {
		this->materia_[i] = NULL;
		this->materia_[i] = rhs.materia_[i];
	}
	return (*this);
};

void MateriaSource::learnMateria( AMateria* m ) {
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

AMateria* MateriaSource::createMateria( std::string const & type ) {
	int i = 0;
	if ( type == "" ) {
		return NULL;
	}
	while ( i < 4 ) {
		if ( this->materia_[i]->getType() == type ) {;
			return this->materia_[i];
		}
		++i;
	}
	return NULL;
};
