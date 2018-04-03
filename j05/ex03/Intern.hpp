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

		static Form*	makePresidentialPardonForm( std::string target );
		static Form*	makeRobotomyRequestForm( std::string );
		static Form*	makeShrubberyCreationForm( std::string );

		typedef Form*( *formGetter )( std::string target );
		static const formGetter getForm[3];

		class FormTypeUnknownException : public std::exception {
			public:
				FormTypeUnknownException( void );
				FormTypeUnknownException( FormTypeUnknownException const & e );
				virtual ~FormTypeUnknownException( void ) throw();
				FormTypeUnknownException &    operator=( FormTypeUnknownException const & rhs ) throw() ;
			private:
				virtual const char* what() const throw();
		};
};

#endif