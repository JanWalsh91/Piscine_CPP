#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "AsteroBocal.hpp"
#include "BocalSteroid.hpp"

int    main ( void ) {
	
	DeepCoreMiner deepCoreMiner;
	StripMiner stripMiner;

	AsteroBocal asteroBocal;
	BocalSteroid bocalSteroid;
	
	stripMiner.mine(&bocalSteroid);
	deepCoreMiner.mine(&bocalSteroid);
	stripMiner.mine(&asteroBocal);
	deepCoreMiner.mine(&asteroBocal);

	return (0);
}