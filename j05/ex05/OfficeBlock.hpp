#ifndef OFFICE_BLOCK_H
# define OFFICE_BLOCK_H

# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"

# include <exception>
# include <string>

class OfficeBlock {

	private:
		Intern*		_intern;
		Bureaucrat*	_signer;
		Bureaucrat*	_executor;

	public:
		OfficeBlock( void );
		OfficeBlock( Intern& intern, Bureaucrat& signer, Bureaucrat& executor );
		~OfficeBlock( void );

		void setIntern( Intern& intern );
		void setSigner( Bureaucrat& signer );
		void setExecutor( Bureaucrat& executor );
		Intern* getIntern( void ) const;
		Bureaucrat* getSigner( void ) const;
		Bureaucrat* getExecutor( void ) const;

		void doBureaucracy( std::string formType, std::string target );

		class NoInternException : public std::exception {
			virtual const char* what() const throw();
		};
		class NoSignerException : public std::exception {
			virtual const char* what() const throw();
		};
		class NoExecutorException : public std::exception {
			virtual const char* what() const throw();
		};
};

#endif