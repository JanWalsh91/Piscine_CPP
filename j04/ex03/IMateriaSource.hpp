#ifndef I_MATERIA_SOURCE_H
# define I_MATERIA_SOURCE_H

# include "AMateria.hpp"

# include <string>

class IMateriaSource {

	public:
		virtual ~IMateriaSource( void ) {};
		virtual void learnMateria( AMateria* m ) = 0;
		virtual AMateria* createMateria( std::string const & type ) = 0;
};

#endif