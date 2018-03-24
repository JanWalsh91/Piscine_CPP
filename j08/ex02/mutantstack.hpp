#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>

template< typename T >
class Mutantstack : std::stack< T >{

	public:
		Mutantstack< T >( void );
		Mutantstack< T >( Mutantstack const & mutantstack ) ;
		~Mutantstack< T >( void );

		Mutantstack &    operator=( Mutantstack const & rhs );
};

#include "mutantstack.cpp"

#endif