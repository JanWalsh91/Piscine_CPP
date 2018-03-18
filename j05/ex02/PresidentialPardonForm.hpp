#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

# include "Form.hpp"

# include <string>

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		void	execute( Bureaucrat const & executor ) const;
};

#endif