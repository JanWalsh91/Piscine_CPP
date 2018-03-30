#ifndef SUPER_MUTANT_H
# define SUPER_MUTANT_H

# include "Enemy.hpp"

class SuperMutant : public Enemy {

	public:
		SuperMutant( void );
		SuperMutant( SuperMutant const & superMutant );
		~SuperMutant( void );

		virtual void takeDamage( int damage );
		
		SuperMutant &    operator=( SuperMutant const & rhs );
};

#endif