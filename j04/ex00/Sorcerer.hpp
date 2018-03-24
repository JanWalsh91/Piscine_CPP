#ifndef SORCERER_H
# define SORCERER_H

# include "Victim.hpp"

# include <string>
# include <iostream>


class Sorcerer {

	private:
		Sorcerer( void );
		std::string _name;
		std::string _title;

	public:
		Sorcerer( std::string name, std::string title );
		Sorcerer( Sorcerer const & sorcerer );
		~Sorcerer( void );

		Sorcerer &    operator=( Sorcerer const & rhs );

		std::string getName( void ) const;
		std::string getTitle( void ) const;
		void polymorph( Victim const & victim ) const;
};

std::ostream& operator<<(std::ostream & os, const Sorcerer & sorcerer);

#endif