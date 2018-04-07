class TestClass {

	public:

	TestClass( int n ) : _n( n ) {}

	bool operator==( TestClass const & rhs ) { return (this->_n == rhs._n); }
	bool operator!=( TestClass const & rhs ) { return (this->_n != rhs._n); }
	bool operator>( TestClass const & rhs ) { return (this->_n > rhs._n); }
	bool operator<( TestClass const & rhs ) { return (this->_n < rhs._n); }
	bool operator>=( TestClass const & rhs ) { return (this->_n >= rhs._n); }
	bool operator<=( TestClass const & rhs ) { return (this->_n <= rhs._n); }

	int _n;
};