#ifndef INTERN_H
# define INTERN_H

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# include <string>
# include <exception>

class Intern {

	public:
		Intern( void );
		Intern( Intern const & intern );
		~Intern( void );

		Intern &    operator=( Intern const & rhs );

		Form*	makeForm( std::string type, std::string target );

		class FormTypeUnknownException : public std::exception {
			virtual const char* what() const throw();
		};
};

#endif