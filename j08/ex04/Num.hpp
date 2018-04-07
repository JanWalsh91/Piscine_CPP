#ifndef NUM_H
# define NUM_H

class Num {

	public:
		Num( int );
		Num( Num const & );
		~Num( void );
		
		Num & operator=( Num const & rhs );
	
	private:
		Num( void );
		int value;
};

#endif