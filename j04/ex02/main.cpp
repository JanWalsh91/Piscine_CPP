#include "Squad.hpp"
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

#include <iostream>

int    main ( void ) {
	// ISquad* vlc = new Squad;

	ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISpaceMarine* bobby = new TacticalMarine;
    ISpaceMarine* jimmy = new AssaultTerminator;
	
	// int i = vlc->push(bob);
	// std::cout << "i: " << i << std::endl;
	
	// i = vlc->push(jim);
	// std::cout << "i: " << i << std::endl;
	
	// i = vlc->push(bobby);
	// std::cout << "i: " << i << std::endl;
	
	// i = vlc->push(jimmy);
	// std::cout << "i: " << i << std::endl;

	// for (int i = 0; i < vlc->getCount(); ++i)
	// {
	// 	std::cout << "========== " << i << " ==========" << std::endl;
	// 	ISpaceMarine* cur = vlc->getUnit(i);
	// 	cur->battleCry();
	// 	cur->rangedAttack();
	// 	cur->meleeAttack();
	// }

	// ISpaceMarine* cur = vlc->getUnit(-1);
	// if ( cur ) {
	// 	cur->battleCry();
	// 	cur->rangedAttack();
	// 	cur->meleeAttack();
	// }
	std::cout << "==========+++==========" << std::endl;

	Squad * test = new Squad;
	
	std::cout << "bob:\t" << bob << std::endl;
	std::cout << "jim:\t" << jim << std::endl;
	std::cout << "bobby:\t" << bobby << std::endl;
	std::cout << "jimmy:\t" << jimmy << std::endl;

	test->push(bob);
	test->push(jim);
	test->push(bobby);
	test->push(jimmy);

	std::cout << "==========+++==========" << std::endl;

	ISquad* copied = NULL;
	
	copied = new Squad(*test);
	
	// for (int i = 0; i < copied->getCount(); ++i)
	// {
	// 	std::cout << "========== " << i << " ==========" << std::endl;
	// 	ISpaceMarine* cur = copied->getUnit(i);
	// 	cur->battleCry();
	// 	cur->rangedAttack();
	// 	cur->meleeAttack();
	// }
	
	std::cout << "==========+++==========" << std::endl;
	(void)copied;

	delete copied;
	std::cout << "==========+++==========" << std::endl;
	delete test;
	// delete vlc;
	return 0;
}