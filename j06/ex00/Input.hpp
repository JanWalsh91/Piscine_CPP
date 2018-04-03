#ifndef INPUT_H
# define INPUT_H

# include <exception>
# include <string>
# include <iostream>
# include <sstream>
# include <cctype>
# include <limits>

class Input {

	private:
		std::string _type;
		char		_char;
		int			_int;
		float		_float;
		double		_double;
		bool		_impossible;
		Input( void );

	public:
		Input( std::string input );
		Input( Input const & input );
		~Input( void );

		std::string	getType( void ) const;

		std::string getInt( void );
		std::string getChar( void );
		std::string getFloat( void );
		std::string getDouble( void );

		Input &    operator=( Input const & rhs );

		class InvalidInputException : public std::exception {
			public:
				InvalidInputException( void );
				InvalidInputException( InvalidInputException const & e );
				virtual ~InvalidInputException( void ) throw();
				InvalidInputException &    operator=( InvalidInputException const & rhs ) throw() ;
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream & os, const Input & input);

#endif