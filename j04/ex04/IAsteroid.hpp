#ifndef I_ASTEROID_H
# define I_ASTEROID_H

# include "DeepCoreMiner.hpp"
# include "StripMiner.hpp"

# include <string>

class DeepCoreMiner;
class StripMiner;

class IAsteroid {

	public:
		virtual ~IAsteroid() {}
		virtual std::string beMined( DeepCoreMiner* deepCoreMiner ) const = 0;
		virtual std::string beMined( StripMiner* stripMiner ) const = 0;
		virtual std::string getName( void ) const = 0;
};

#endif