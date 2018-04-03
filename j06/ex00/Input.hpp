#ifndef INPUT_H
# define INPUT_H

# include <exception>
# include <string>
# include <iostream>
# include <cctype>
# include <limits>

class Input {

	private:
		std::string _type;
		void *		_input;

	public:
		Input( void );
		Input( std::string input );
		Input( Input const & input );
		~Input( void );

		void *		getInput( void ) const;
		std::string	getType( void ) const;

		operator	char();
		operator	int();
		operator	float();
		operator	double();

		Input &    operator=( Input const & rhs );

		class OverflowException : public std::exception {
			public:
				OverflowException( void );
				OverflowException( OverflowException const & e );
				virtual ~OverflowException( void ) throw();
				OverflowException &    operator=( OverflowException const & rhs ) throw() ;
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream & os, const Input & input);

#endif