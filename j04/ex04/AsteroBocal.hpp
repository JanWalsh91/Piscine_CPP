#ifndef ASTERO_BOCAL_H
# define ASTERO_BOCAL_H

# include "IAsteroid.hpp"
# include "DeepCoreMiner.hpp"
# include "StripMiner.hpp"

class AsteroBocal : public IAsteroid {

	public:
		AsteroBocal( void );
		AsteroBocal( AsteroBocal const & asteroBocal );
		~AsteroBocal( void );

		AsteroBocal &    operator=( AsteroBocal const & rhs );

		std::string beMined( DeepCoreMiner* deepCoreMiner ) const ;
		std::string beMined( StripMiner* stripMiner ) const ;
		std::string getName( void ) const ;
};

#endif