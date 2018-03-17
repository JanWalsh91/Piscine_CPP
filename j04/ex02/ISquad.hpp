#ifndef I_SQUAD_H
# define I_SQUAD_H

# include "ISpaceMarine.hpp"

class ISquad {

	public:
		virtual ~ISquad( void ) {} ;

		virtual int getCount( void ) const = 0;
		virtual ISpaceMarine* getUnit( int i ) const = 0;
		virtual int push( ISpaceMarine* marine ) = 0;
};

#endif