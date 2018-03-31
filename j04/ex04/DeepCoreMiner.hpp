#ifndef DEEP_CORE_MINER_H
# define DEEP_CORE_MINER_H

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class DeepCoreMiner : public IMiningLaser {

	public:
		DeepCoreMiner( void );
		DeepCoreMiner( DeepCoreMiner const & deepCoreMiner );
		~DeepCoreMiner( void );

		DeepCoreMiner &    operator=( DeepCoreMiner const & rhs );

		void mine( IAsteroid* asteroid );
};

#endif