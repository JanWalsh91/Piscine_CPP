#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource( void ) {
	return ;
};

IMateriaSource::IMateriaSource( IMateriaSource const & iMateriaSource ) {
	*this = iMateriaSource;
	return ;
};

IMateriaSource &    IMateriaSource::operator=( IMateriaSource const & rhs ) {
	( void )rhs;
	return (*this);
};