#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

# include "Form.hpp"

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		void	execute( Bureaucrat const & executor ) const;

		PresidentialPardonForm &    operator=( PresidentialPardonForm const & rhs );
};

#endif