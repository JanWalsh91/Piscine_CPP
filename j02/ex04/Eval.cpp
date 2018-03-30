#include "Eval.hpp"

#include <iostream>

Eval::Eval( void ) {}

Eval::~Eval( void ) {}

Eval::Eval( Eval & eval ) {
    *this = eval;
}

Eval &	   Eval::operator=( Eval const & rhs ) {
    return (*this);
}

std::string Eval::eval( std::string expr ) {
    std::cout << expr << std::endl;
    size_t i = expr.find("(");
    // std::cout << "i: " << i << std::endl;
    if ( i != std::string::npos ) {
        size_t i2 = expr.find("(", i + 1);
        // std::cout << "i2: " << i2 << std::endl;
        
        size_t y = expr.find(")", i + 1);
        // std::cout << "y: " << y << std::endl;
        // TODO handle ex
        if ( i2 != std::string::npos ) {
            if ( i2 < y ) {
                size_t y2 = expr.find_last_of(")", i + 1);
                std::string expr2 = expr.substr(i2 + 1, y2 - i2 - 1);
                this->eval( expr2 );
            }
        }
        else {
            // size_t y2 = expr.find_last_of(")", i + 1);
            // std::cout << "y2B: " << y2 << std::endl;
            std::string expr2 = expr.substr(i + 1, y - i - 1);
            return this->eval( expr2 );
        }
    }
    else {
        expr = this->reduce( expr );
        std::cout << "done: " << expr << std::endl;
    }
    return expr;
}

std::string Eval::reduce( std::string eval ) {
    std::cout << "reduce" << std::endl;
    size_t i = eval.find("*");
    if ( i == std::string::npos ) {
        i = eval.find("/");
    }
    if ( i == std::string::npos ) {
        i = eval.find("+");
    }
    if ( i == std::string::npos ) {
        i = eval.find("-");
    }

    if ( i != std::string::npos ) {
        std::cout << "found " << eval[i] << " operator." << std::endl;
        // find last pos + -* / && atoi de l'autre cote 
        
        size_t li = this->findLast(eval, i);
        size_t ri = this->findNext(eval, i);
        std::cout << "li: " << li << ", ri: " << ri << std::endl;

        Fixed l =  Fixed((float)std::atof(eval.substr(li, i).c_str()));
        Fixed r =  Fixed((float)std::atof(eval.substr(ri).c_str()));

        std::cout << "l: " << l << ", r: " << r << std::endl;
        Fixed res = this->calc(l, r, eval[i]);
        std::cout << "res: " << res << std::endl;
        eval = this->replace(eval, res, li, ri);
        std::cout << eval << std::endl;
    }
    return eval;
}

size_t Eval::findLast( std::string expr, int i ) {
    std::cout << "findLast: " << expr << "  i: " << i << std::endl;
    size_t m = expr.find_last_of('*', i - 1);
    size_t d = expr.find_last_of('/', i - 1);
    size_t a = expr.find_last_of('+', i - 1);
    size_t s = expr.find_last_of('-', i - 1);
    // std::cout << "a: " << a << std::endl;
    m = m == std::string::npos ? std::numeric_limits<size_t>::max() : m;
    d = d == std::string::npos ? std::numeric_limits<size_t>::max() : d;
    a = a == std::string::npos ? std::numeric_limits<size_t>::max() : a;
    s = s == std::string::npos ? std::numeric_limits<size_t>::max() : s;
    std::cout << "a: " << a << std::endl;
    size_t res = std::min(std::min(std::min(m, d), a), s);
    if ( res == std::numeric_limits<size_t>::max() ) {
        std::cout << "findLast done: " << 0 << std::endl;
        return 0;
    }
    std::cout << "findLast done: " << res << std::endl;
    return res;
}

size_t Eval::findNext( std::string expr, int i ) {
    std::cout << "findNext: " << expr << "  i: " << i << std::endl;
    size_t m = expr.find('*', i + 1);
    size_t d = expr.find('/', i + 1);
    size_t a = expr.find('+', i + 1);
    size_t s = expr.find('-', i + 1);
    // std::cout << "a: " << a << std::endl;

    m = m == std::string::npos ? std::numeric_limits<size_t>::max() : m;
    d = d == std::string::npos ? std::numeric_limits<size_t>::max() : d;
    a = a == std::string::npos ? std::numeric_limits<size_t>::max() : a;
    s = s == std::string::npos ? std::numeric_limits<size_t>::max() : s;

    size_t res = std::min(std::min(std::min(m, d), a), s);
    if ( res == std::numeric_limits<size_t>::max() ) {
        std::cout << "findNext done i: " << i + 1 << std::endl;
        return i + 1;
    }
    std::cout << "findNext done res: " << res << std::endl;
    return res;
}

Fixed Eval::calc(Fixed & a, Fixed & b, char op) {
    std::cout << "calc: " << a << op << b << std::endl;
    switch(op) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;
    }
    return Fixed();
}

std::string Eval::replace( std::string expr, Fixed f, size_t li, size_t ri ) {
    std::cout << "replace in " << expr << " f: " << f << " li: " << li << " ri: " << ri << std::endl;
    std::ostringstream o;
    o << f;
    std::string res = expr.replace(li, ri - li + o.str().length(), o.str());
    
    std::cout << "res: " << res << std::endl;
    return res;
}