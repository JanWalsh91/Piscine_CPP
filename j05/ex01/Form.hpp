#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form {

	private:
		bool				_signed;
		const int			_minSignGrade;
		const int			_minExecuteGrade;
		const std::string	_name;

	public:
		Form( void );
		Form( std::string name, int minSignGrade, int minExecuteGrade );
		Form( Form const & form );
		virtual  ~Form( void );

		Form &    operator=( Form const & rhs );

		bool		isSigned( void ) const ;
		int			getMinSignGrade( void ) const ;
		int			getMinExecuteGrade( void ) const ;
		std::string	getName( void ) const ;
		void		beSigned( Bureaucrat& bureaucrat );

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
		class AlreadySignedException : public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, const Form & form );

#endif