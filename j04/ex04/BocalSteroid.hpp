#ifndef BOCAL_STEROID_H
# define BOCAL_STEROID_H

# include "IAsteroid.hpp"
# include "DeepCoreMiner.hpp"
# include "StripMiner.hpp"

class BocalSteroid : public IAsteroid {

	public:
		BocalSteroid( void );
		BocalSteroid( BocalSteroid const & bocalSteroid );
		~BocalSteroid( void );

		BocalSteroid &    operator=( BocalSteroid const & rhs );

		std::string beMined( DeepCoreMiner* deepCoreMiner ) const ;
		std::string beMined( StripMiner* stripMiner ) const ;
		std::string getName( void ) const ;
};

#endif