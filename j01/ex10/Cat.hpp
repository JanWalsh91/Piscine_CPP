#include <string>

class Cat {
	void writeFileToSO( std::string file );
	void readSI( void );

	public:
		Cat( void );
		~Cat( void );

		void handleArg( std::string arg );
};