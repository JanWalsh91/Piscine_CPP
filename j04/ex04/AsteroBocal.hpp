#ifndef ASTERO_BOCAL_H
# define ASTERO_BOCAL_H

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

class AsteroBocal : public IAsteroid {

	public:
		AsteroBocal( void );
		AsteroBocal( AsteroBocal const & asteroBocal );
		~AsteroBocal( void );

		AsteroBocal &    operator=( AsteroBocal const & rhs );

		std::string beMined( IAsteroid* asteroid ) const ;
		std::string beMined( IMiningLaser* miningLaser ) const ;
		std::string getName( void ) const ;
};

#endif