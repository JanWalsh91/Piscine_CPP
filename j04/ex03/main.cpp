#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#include <iostream>

int    main ( void ) {
	IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
	
	std::cout << "=============" << std::endl;
	
	ICharacter* zaz = new Character("zaz");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);
	ICharacter* bob = new Character("bob");
	
	
	zaz->use(0, *bob);
	zaz->use(1, *bob);
	zaz->use(2, *bob);
	zaz->use(3, *bob);
	zaz->use(4, *bob);
	
	std::cout << "=============" << std::endl;

	zaz->unequip(0);
	zaz->use(0, *bob);

	std::cout << "=============" << std::endl;
	
	zaz->equip(tmp);


	ICharacter* zazette = new Character(*(Character*)zaz);

	zazette->unequip(1);
	zazette->unequip(2);

	zazette->use(0, *bob);
	zazette->use(1, *bob);

	std::cout << "=============" << std::endl;

	AMateria* ice = new Ice();
	AMateria* iceCopy = new Ice(*(Ice*)ice);

	bob->equip(iceCopy);
	
	bob->use(0, *bob);

	std::cout << "=============" << std::endl;

	tmp = src->createMateria("poison");

	delete bob;
	delete zaz;
	delete zazette;
	delete src;
	return 0;
}