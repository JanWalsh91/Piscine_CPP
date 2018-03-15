#include "Pony.hpp"
#include <iostream>

void ponyOnTheHeap( void );
void ponyOnTheStack( void );

int main( void ) {
	ponyOnTheHeap();
	ponyOnTheStack();
}

void ponyOnTheHeap( void ) {
	Pony* myPony = new Pony("blue");
	myPony->neigh();
	delete myPony;
}

void ponyOnTheStack( void ) {
	Pony myPony("pink");
	myPony.neigh();
}