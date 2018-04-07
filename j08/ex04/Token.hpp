#ifndef TOKEN_H
# define TOKEN_H

class Token {

	public:
		Token( void );
		Token( Token const & );
		~Token( void );

		Token & operator=( Token const & rhs );
	private:

};

#endif