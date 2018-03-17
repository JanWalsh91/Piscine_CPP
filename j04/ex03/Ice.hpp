#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {

	public:
		Ice( void );
		Ice( Ice const & ice );
		~Ice( void );

		Ice &    operator=( Ice const & rhs );

		Ice* clone( void ) const;

		void use( ICharacter& target );
};

#endif