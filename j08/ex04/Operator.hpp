#ifndef OPERATOR_H
# define OPERATOR_H

class Operator {

	public:
		Operator( char );
		Operator( Operator const & );
		~Operator( void );
		
		Operator & operator=( Operator const & rhs );
		
	private:
		Operator( void );
		
		const char	value;
		int			priority;

};

#endif