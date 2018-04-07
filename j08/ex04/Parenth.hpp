#ifndef PARENTH_H
# define PARENTH_H

class Parenth {

	public:
		Parenth( char );
		Parenth( Parenth const & );
		~Parenth( void );
		
		Parenth & operator=( Parenth const & rhs );
		
	private:
		Parenth( void );
		const char value;

};

#endif