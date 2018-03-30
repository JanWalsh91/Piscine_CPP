#ifndef ENEMY_H
# define ENEMY_H

# include <string>
# include <iostream>

class Enemy {

	protected:
		int			_hp;
		std::string _type;
		Enemy( void );

	public:
		Enemy( int hp, std::string const & type );
		Enemy( Enemy const & enemy );
		virtual ~Enemy( void );

		std::string const getType( void ) const;
		int getHP( void ) const;

		virtual void takeDamage( int damage );

		Enemy &    operator=( Enemy const & rhs );
};

#endif