#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include "Form.hpp"

# include <string>
# include <iostream>
# include <exception>

class Form;

class Bureaucrat {

	private:
		int					_grade;
		const std::string	_name;
		void				_updateGrade( int grade );

	public:
		Bureaucrat( void );
		Bureaucrat( const std::string name, int grade );
		Bureaucrat( Bureaucrat const & bureaucrat );
		~Bureaucrat( void );

		Bureaucrat &    operator=( Bureaucrat const & rhs );

		int		getGrade( void ) const ;
		const std::string	getName( void ) const ;
		void	incrementGrade( void );
		void	decrementGrade( void );
		void	signForm( Form& form );
		void	executeForm( Form& form );

		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException( void );
				GradeTooHighException( GradeTooHighException const & e );
				virtual ~GradeTooHighException( void ) throw();
				GradeTooHighException &    operator=( GradeTooHighException const & rhs ) throw() ;
			private:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException( void );
				GradeTooLowException( GradeTooLowException const & e );
				virtual ~GradeTooLowException( void ) throw();
				GradeTooLowException &    operator=( GradeTooLowException const & rhs ) ;
			private:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<( std::ostream& os, const Bureaucrat & bureaucrat );

#endif