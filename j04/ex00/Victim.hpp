#ifndef VICTIM_H
# define VICTIM_H

# include <string>
# include <iostream>

class Victim {

	protected:
		std::string _name;

	public:
		Victim( std::string name );
		Victim( Victim const & victim );
		~Victim( void );

		Victim &    operator=( Victim const & rhs );
		
		std::string getName( void ) const;
		virtual void getPolymorphed( void ) const;
};

std::ostream& operator<<(std::ostream & os, const Victim & Victim );

#endif