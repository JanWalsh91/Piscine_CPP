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
	std::cout << "\n" << std::endl;
	Data * data = deserialize(array);

	std::cout << "s1: \t" << data->s1 << std::endl;
	std::cout << "n: \t" << data->n << std::endl;
	std::cout << "s2: \t" << data->s2 << std::endl;
	return (0);
}

void *	serialize( void ) {
	std::cout << "==  serialize  ==\n" << std::endl;
	char *	array = new char[20];

	for ( int i = 0; i < 8; ++i ) {
		array[i] = random_alphanum();
	}
	int *p = reinterpret_cast<int *>(&(array[8]));
	*p = (random_num());
	for ( int i = 12; i < 20; ++i ) {
		array[i] = random_alphanum();
	}

	for ( int i = 0; i < 20; ++i ) {
		std::cout << i << ":\t";
		if (i == 8) {
			std::cout << *(reinterpret_cast<int*>(p)) << std::endl;
		} else {
			std::cout << array[i] << std::endl;
		}
	}
	return reinterpret_cast<void *>(array);
}

Data *	deserialize( void * raw ) {
	std::cout << "== deserialize ==\n" << std::endl;
	Data * data = new Data();
	data->s1.assign( reinterpret_cast<char *>(raw), 0, 8 );
	data->n = * reinterpret_cast<int *> ( &reinterpret_cast<char *>(raw)[8] );
	data->s2.assign( &(reinterpret_cast<char *>(raw)[12]), 8 );
	return data;
}

char	random_alphanum( void ) {
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char c = alphanum[std::rand() % (sizeof(alphanum) - 1)];
	return c;
}

int		random_num( void ) {
	int n = std::rand() % 2 ? 1 : -1;
	int i = std::rand() % 1000;
	return n * i;
}