#ifndef SQUAD_H
# define SQUAD_H

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class SpaceMarineNode;

class Squad : public ISquad {
	
	private:
		SpaceMarineNode*	_marines;

	public:
		Squad( void );
		Squad( Squad const & squad );
		~Squad( void );

		Squad &    operator=( Squad const & rhs );

		int getCount( void ) const;
		ISpaceMarine* getUnit( int i ) const;
		int push( ISpaceMarine* marine );
};

class SpaceMarineNode {
	
	public:
		ISpaceMarine*		marine;
		SpaceMarineNode*	next;

		SpaceMarineNode( void );
		SpaceMarineNode( ISpaceMarine* marine );
		SpaceMarineNode( SpaceMarineNode const & spaceMarineNode );
		~SpaceMarineNode( void );

		SpaceMarineNode &    operator=( SpaceMarineNode const & rhs );
};

#endif