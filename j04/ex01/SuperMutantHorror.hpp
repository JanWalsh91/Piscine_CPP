#ifndef SUPER_MUTANT_HORROR_H
# define SUPER_MUTANT_HORROR_H

# include "SuperMutant.hpp"

class SuperMutantHorror : public SuperMutant {

	public:
		SuperMutantHorror( void );
		SuperMutantHorror( SuperMutantHorror const & superMutantHorror );
		~SuperMutantHorror( void );

		virtual void takeDamage( int damage );
		
		SuperMutantHorror &    operator=( SuperMutantHorror const & rhs );
};

#endif
