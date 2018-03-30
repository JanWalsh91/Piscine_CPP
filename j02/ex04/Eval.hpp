#ifndef EVAL_H
# define EVAL_H

# include "Fixed.hpp"

# include <string>
# include <sstream>
# include <limits>

class Eval {
    private:
        std::string _expr;
        Fixed calc(Fixed &, Fixed &, char op);
        size_t findLast( std::string expr, int i );
        size_t findNext( std::string expr, int i );
        std::string replace( std::string expr, Fixed f, size_t li, size_t ri );

    public:
        Eval( void );
        Eval( Eval & eval );
        ~Eval( void );
        Eval &	   operator=( Eval const & rhs );

        std::string eval( std::string expr );
        std::string reduce( std::string expr );
};

#endif