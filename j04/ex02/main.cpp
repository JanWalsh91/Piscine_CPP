#include "Squad.hpp"
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

#include <iostream>

int    main ( void ) {
	ISquad* vlc = new Squad;

	ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* bobby = new TacticalMarine;
    ISpaceMarine* bobbio = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISpaceMarine* jimmy = new AssaultTerminator;
	
	std::cout << "getCount(vlc): " << vlc->getCount() << std::endl;
	
	std::cout << "push unit: " << vlc->push(bob) << std::endl;
	std::cout << "push unit: " << vlc->push(bobby) << std::endl;
	std::cout << "push unit: " << vlc->push(bobbio) << std::endl;
	std::cout << "push unit: " << vlc->push(jim) << std::endl;
	std::cout << "push unit: " << vlc->push(jimmy) << std::endl;
	std::cout << "push unit: " << vlc->push(jimmy) << std::endl;
	std::cout << "push unit: " << vlc->push(NULL) << std::endl;
	
	std::cout << "getCount(vlc) : " << vlc->getCount() << std::endl;



	for (int i = 0; i < vlc->getCount(); ++i)
	{
		std::cout << "--------- " << i << " ---------" << std::endl;
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << "============  +++  ============" << std::endl;

	ISquad* copied = NULL;

	copied = new Squad(*(Squad*)vlc);
	
	for (int i = 0; i < copied->getCount(); ++i)
	{
		std::cout << "--------- " << i << " ---------" << std::endl;
		ISpaceMarine* cur = copied->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}


	std::cout << "============  +++  ============" << std::endl;
	delete copied;
	std::cout << "============  +++  ============" << std::endl;
	delete vlc;
	return 0;
}