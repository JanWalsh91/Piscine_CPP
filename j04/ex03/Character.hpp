#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include "AMateria.hpp"

# include <string>

class Character : public ICharacter {

	private:
		std::string name_;
		AMateria* materia_[4];

	public:
		Character( void );
		Character( std::string name );
		Character( Character const & character );
		~Character( void );

		Character &    operator=( Character const & rhs );

		std::string const & getName( void ) const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );
};

#endif