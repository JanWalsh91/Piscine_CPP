#ifndef I_ASTEROID_H
# define I_ASTEROID_H

# include "IMiningLaser.hpp"

# include <string>

class IMiningLaser;

class IAsteroid {

	public:
		IAsteroid( void );
		IAsteroid( IAsteroid const & iAsteroid );
		virtual ~IAsteroid() {}

		IAsteroid &    operator=( IAsteroid const & rhs );

		virtual std::string beMined( IAsteroid* asteroid ) const = 0;
		virtual std::string beMined( IMiningLaser* miningLaser ) const = 0;
		virtual std::string getName( void ) const = 0;
};

#endif