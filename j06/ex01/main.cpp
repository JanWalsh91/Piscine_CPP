#include <string>
#include <iostream>

struct Data { std::string s1; int n; std::string s2; };

void *	serialize( void );
Data *	deserialize( void * raw );
char	random_alphanum( void );
int		random_num( void );

int		main ( void ) {
	std::srand(std::time(nullptr));
	void * array = serialize();
	Data * data = deserialize(array);
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
	return (0);
}

void *	serialize( void ) {
	char *	array = new char[20];

	for ( int i = 0; i < 8; i++ ) {
		array[i] = random_alphanum();
	}
	array[8] = random_num();
	for ( int i = 12; i < 20; i++ ) {
		array[i] = random_alphanum();
	}

	for (int i = 0; i < 20; i++) {
		std::cout << i << "\t- ";
		if (i == 8) {
			std::cout << static_cast<int>(array[i]) << std::endl;
		} else {
			std::cout << array[i] << std::endl;
		}
	}
	return reinterpret_cast<void *>(array);
};

Data *	deserialize( void * raw ) {
	std::cout << "deserialize" << std::endl;
	Data * data = new Data();
	data->s1.assign( reinterpret_cast<char *>(raw), 0, 8 );
	data->n = * reinterpret_cast<int *> ( &reinterpret_cast<char *>(raw)[8] );
	data->s2.assign( &(reinterpret_cast<char *>(raw)[12]), 8 );
	std::cout << "deserialize DONE" << std::endl;
	return data;
}

char	random_alphanum( void ) {
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	char c = alphanum[rand() % (sizeof(alphanum) - 1)];
	return c;
}

int		random_num( void ) {
	int i = rand() % 1000;
	std::cout << i << std::endl;
	return i;
}