#ifndef I_CHARACTER_H
# define I_CHARACTER_H

# include "AMateria.hpp"

# include <string>

class AMateria;

class ICharacter {

	public:
		ICharacter( void );
		ICharacter( ICharacter const & iCharacter );
		virtual ~ICharacter( void ) {}

		ICharacter &    operator=( ICharacter const & rhs );

		virtual std::string const & getName( void ) const = 0;
		virtual void equip( AMateria* m ) = 0;
		virtual void unequip( int idx ) = 0;
		virtual void use( int idx, ICharacter& target ) = 0;
};

#endif