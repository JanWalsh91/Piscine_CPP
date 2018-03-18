#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

# include "Form.hpp"

# include <string>

class RobotomyRequestForm : public Form {

	private:
		static void	_initRand( void );
		static int	_randInit;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		void	execute( Bureaucrat const & executor ) const;
};

#endif