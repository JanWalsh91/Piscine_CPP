#ifndef BOCAL_STEROID_H
# define BOCAL_STEROID_H

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

class BocalSteroid : public IAsteroid {

	public:
		BocalSteroid( void );
		BocalSteroid( BocalSteroid const & bocalSteroid );
		~BocalSteroid( void );

		BocalSteroid &    operator=( BocalSteroid const & rhs );

		std::string beMined( IAsteroid* asteroid ) const ;
		std::string beMined( IMiningLaser* miningLaser ) const ;
		std::string getName( void ) const ;
};

#endif