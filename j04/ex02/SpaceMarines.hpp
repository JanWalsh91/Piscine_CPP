#ifndef SPACE_MARINES_H
# define SPACE_MARINES_H

# include "ISpaceMarine.hpp"

class SpaceMarines {

	private:
		ISpaceMarine* _marine;
		SpaceMarines* _next;

	public:
		SpaceMarines( void );
		SpaceMarines( ISpaceMarine* marine );
		SpaceMarines( SpaceMarines const & spaceMarines );
		~SpaceMarines( void );
		
		int getCount( void ) const;
		ISpaceMarine* getUnit( int i ) const ;
		int push( ISpaceMarine* iSpaceMarine );
		SpaceMarines &    operator=( SpaceMarines const & rhs );
};

#endif