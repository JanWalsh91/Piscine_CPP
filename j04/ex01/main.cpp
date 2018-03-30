#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "SuperMutantHorror.hpp"
#include "PlasmaRifle.hpp"
#include "UltimatePlasmaRifle.hpp"
#include "PowerFist.hpp"

#include <iostream>

int    main ( void ) {
	
	Character* zaz = new Character("zaz");
    std::cout << *zaz;
	Enemy* b = new RadScorpion();
	Enemy* m = new SuperMutant();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	std::cout << "=========" << std::endl;
	
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	
	zaz->attack(m);
	zaz->attack(m);
	zaz->attack(m);
	zaz->attack(m);
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;

	std::cout << "=========" << std::endl;

	Character* zazette = new Character("zazette");
	AWeapon* upr = new UltimatePlasmaRifle();
	zazette->equip(upr);
	zazette->attack(m);
	zaz->attack(m);

	std::cout << "=========" << std::endl;
	
	Enemy* mh = new SuperMutantHorror();
	zaz->attack(mh);
	zazette->attack(mh);

	std::cout << "=========" << std::endl;
	
	delete mh;
	delete upr;
	delete zazette;
	delete pf;
	delete pr;
	delete m;
	delete b;
	delete zaz;

	return 0;
}