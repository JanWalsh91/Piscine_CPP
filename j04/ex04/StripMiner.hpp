#ifndef STRIP_MINER_H
# define STRIP_MINER_H

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class StripMiner : public IMiningLaser {

	private:

	public:
		StripMiner( void );
		StripMiner( StripMiner const & stripMiner );
		~StripMiner( void );

		StripMiner &    operator=( StripMiner const & rhs );

		void mine( IAsteroid* asteroid );
};

#endif