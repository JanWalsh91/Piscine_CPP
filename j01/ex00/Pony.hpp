#include <string>

class Pony {
	private:
		std::string _color;

	public:
		Pony(std::string color);
		~Pony( void );
		void neigh( void );

};