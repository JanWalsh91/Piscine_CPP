#ifndef RPN_N
# define RPN_N

# include "Token.hpp"
# include "Operator.hpp"
# include "Num.hpp"
# include "Parenth.hpp"

# include <stack>
# include <string>
# include <iostream>

class RPN {

	public:
		RPN( void );
		RPN( RPN const & );
		~RPN( void );

		RPN & operator=( RPN const & rhs );

		void tokenize( std::string );


	private:
		std::stack<Token> tokens;

		bool isop( char );

		Token & parseParenth( std::string, int & );
		Token & parseNum( std::string, int & );
		Token & parseOp( std::string, int & );

};

#endif