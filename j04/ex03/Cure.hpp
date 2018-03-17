#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {

	private:

	public:
		Cure( void );
		Cure( Cure const & cure );
		~Cure( void );

		Cure &    operator=( Cure const & rhs );

		Cure* clone( void ) const;

		void use( ICharacter& target );
};

#endif