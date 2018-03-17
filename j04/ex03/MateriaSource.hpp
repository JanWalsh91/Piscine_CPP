#ifndef MATERIA_SOURCE_H
# define MATERIA_SOURCE_H

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# include <string>

class MateriaSource : public IMateriaSource {

	private:
		AMateria* materia_[4];

	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const & materiaSource );
		~MateriaSource( void );

		MateriaSource &    operator=( MateriaSource const & rhs );

		virtual void learnMateria( AMateria* );
		virtual AMateria* createMateria( std::string const & type );
};

#endif