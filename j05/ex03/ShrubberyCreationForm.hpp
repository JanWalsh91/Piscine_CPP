#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

# include "Form.hpp"

class ShrubberyCreationForm : public Form {

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		void	execute( Bureaucrat const & executor ) const;

		ShrubberyCreationForm &    operator=( ShrubberyCreationForm const & rhs );
};

#endif