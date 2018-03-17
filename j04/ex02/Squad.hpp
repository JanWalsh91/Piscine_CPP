#ifndef SQUAD_H
# define SQUAD_H

# include "ISquad.hpp"
# include "SpaceMarines.hpp"

class Squad : public ISquad {

	private:
		int					_unitCount;
		SpaceMarines* 		_marines;

	public:
		Squad( void );
		Squad( Squad const & squad );
		~Squad( void );

		Squad &    operator=( Squad const & rhs );

		int getCount( void ) const;
		ISpaceMarine* getUnit( int i ) const;
		int push( ISpaceMarine* marine );
};

#endif