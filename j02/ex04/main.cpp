#include "Fixed.hpp"
#include "Eval.hpp"
#include <iostream>

int    main ( int ac, char** av ) {
	// if (ac == 1) {
	// 	return (0);
	// }
	Eval eval;

	std::string str = "1 + (2 + 23)";
	for(int i = 0; i < str.length(); i++)
    	if(str[i] == ' ') str.erase(i,1);
	std::cout << "str: " << str << std::endl; 

	std::string sol = eval.eval(str);
		std::cout << "result: " << sol << std::endl; 


	return (0);
}

// check while parsing
// recursive when determining expression in parenths
// replace expression with result, rinse and repeat
// find highest op priority

// 1 * ( 2 + 3 )
// found expression in parenths, call on eval to expr in parenths
// 2 + 3 ..

// 1 * ( 2 + 3 * 3 )
// eval 2 + 3 * 3 (bc parenths)
// find highest priority operator: * eval and replace: 2 + 9
// eval and replace 1 * 11
// eval and replace 11

// 1 * ( 2 + 3 * ( 4 + 5 ) )

