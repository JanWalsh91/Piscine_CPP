#include "ShrubberyCreationForm.hpp"

#include <fstream>

/* ========== ShrubberyCreationForm ========== */

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	Form("Shrubbery Creation Form", 145, 137, "Default Target") {
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :
	Form("Shrubbery Creation Form", 145, 137, target) {
}

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
}

ShrubberyCreationForm &    ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {
	(void)rhs;
	return (*this);
}