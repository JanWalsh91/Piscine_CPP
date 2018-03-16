#ifndef SUPER_MUTANT_H
# define SUPER_MUTANT_H

# include "Enemy.hpp"

class SuperMutant : public Enemy {

	public:
		SuperMutant( void );
		SuperMutant( SuperMutant const & superMutant );
		~SuperMutant( void );

		void takeDamage( int damage );
};

#endif