#ifndef RAD_SCORPION_H
# define RAD_SCORPION_H

# include "Enemy.hpp"

class RadScorpion : public Enemy {

	public:
		RadScorpion( void );
		RadScorpion( RadScorpion const & radScorpion );
		~RadScorpion( void );

		virtual void takeDamage( int damage );
		
		RadScorpion &    operator=( RadScorpion const & rhs );
};

#endif