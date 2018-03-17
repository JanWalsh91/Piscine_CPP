#ifndef A_MATERIA_H
# define A_MATERIA_H

# include "ICharacter.hpp"

# include <string>

class ICharacter;

class AMateria {

	protected:
		unsigned int xp_;
		std::string type_;

	public:
		AMateria( void );
		AMateria( std::string const & type );
		AMateria( AMateria const & aMateria );
		~AMateria( void );

		AMateria &    operator=( AMateria const & rhs );

		std::string const & getType( void ) const;
		unsigned int getXP( void ) const;
		virtual AMateria* clone( void ) const = 0;
		virtual void use( ICharacter& target );
};

#endif