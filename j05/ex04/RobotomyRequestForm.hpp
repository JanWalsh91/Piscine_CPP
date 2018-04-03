#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

# include "Form.hpp"

class RobotomyRequestForm : public Form {

	private:
		static void	_initRand( void );
		static bool	_randInit;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		void	execute( Bureaucrat const & executor ) const;

		RobotomyRequestForm &    operator=( RobotomyRequestForm const & rhs );
};

#endif