#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	Form("Shrubbery Creation Form", 145, 137, "Default Target") {

	return ;
};

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :
	Form("Shrubbery Creation Form", 145, 137, target) {

	return ;
};

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
	Form::execute( executor );

	std::ofstream os(this->getTarget() + "_shrubbery");

	os
	<< "          %%%,%%%%%%%"
	<< std::endl
    << "      ,'%% -*%%%%%%%%"
    << std::endl
	<< " ;%%%%%*%   _%%%%"
    << std::endl
	<< "  ,%%%       \(_.*%%%%."
    << std::endl
	<< "  % *%%, ,%%%%*(    '"
    << std::endl
	<< "%^     ,*%%% )|,%%*%,_"
    << std::endl
	<< "     *%     #).-*%%*"
    << std::endl
	<< "         _.) ,/ *%,"
    << std::endl
	<< "__________/)#(____________"
	<< std::endl
	<< std::endl;

	os
	<< "          %%%,%%%%%%%"
	<< std::endl
    << "      ,'%% -*%%%%%%%%"
    << std::endl
	<< " ;%%%%%*%   _%%%%"
    << std::endl
	<< "  ,%%%       \(_.*%%%%."
    << std::endl
	<< "  % *%%, ,%%%%*(    '"
    << std::endl
	<< "%^     ,*%%% )|,%%*%,_"
    << std::endl
	<< "     *%     #).-*%%*"
    << std::endl
	<< "         _.) ,/ *%,"
    << std::endl
	<< "__________/)#(____________"
	<< std::endl;

	os.close();
};