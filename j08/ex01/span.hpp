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
		virtual ~Span( void );

		Span &    operator=( Span const & rhs );

		void	addNumber( int n );
		void	addNumbers( int n[], int count );
		int		shortestSpan( void );
		int		longestSpan( void );

		class FullException : public std::exception {
			public:
				FullException( void );
				FullException( FullException const & e );
				virtual ~FullException( void ) throw();
				FullException &    operator=( FullException const & rhs ) throw() ;
				virtual const char* what() const throw();
		};

		class NotEnoughElementsToCompareException : public std::exception {
			public:
				NotEnoughElementsToCompareException( void );
				NotEnoughElementsToCompareException( NotEnoughElementsToCompareException const & e );
				virtual ~NotEnoughElementsToCompareException( void ) throw();
				NotEnoughElementsToCompareException &    operator=( NotEnoughElementsToCompareException const & rhs ) throw() ;
				virtual const char* what() const throw();
		};
};

#endif