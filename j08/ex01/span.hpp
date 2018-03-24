#ifndef SPAN_H
# define SPAN_H

# include <set>
# include <exception>

class Span {

	private:
		unsigned int			_N;
		unsigned int			_C;
		std::multiset< int > 	_set;

	public:
		Span( void );
		Span( unsigned int N );
		Span( Span const & span );
		~Span( void );

		Span &    operator=( Span const & rhs );

		void	addNumber( int n );
		int		shortestSpan( void );
		int		longestSpan( void );

		class FullException : public std::exception {
			virtual const char* what() const throw();
		};
		class NotEnoughElementsToCompareException : public std::exception {
			virtual const char* what() const throw();
		};
};

#endif