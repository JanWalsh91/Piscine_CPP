#ifndef I_MINING_LASER_H
# define I_MINING_LASER_H

# include "IAsteroid.hpp"

class IAsteroid;

class IMiningLaser {

	public:
		IMiningLaser( void );
		IMiningLaser( IMiningLaser const & iMiningLaser );
		virtual ~IMiningLaser( void ) {};

		IMiningLaser &    operator=( IMiningLaser const & rhs );

		virtual void mine( IAsteroid* ) = 0;
};

#endif