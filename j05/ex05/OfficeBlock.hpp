#ifndef OFFICE_BLOCK_H
# define OFFICE_BLOCK_H

# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"

class OfficeBlock {

	private:
		Intern*		_intern;
		Bureaucrat*	_signer;
		Bureaucrat*	_executor;

	public:
		OfficeBlock( void );
		OfficeBlock( Intern& intern, Bureaucrat& signer, Bureaucrat& executor );
		// No copy
		~OfficeBlock( void );
		// No assignation

		void setIntern( Intern& intern );
		void setSigner( Bureaucrat& signer );
		void setExecutor( Bureaucrat& executor );
		
		const Intern * getIntern( void ) const;
		const Bureaucrat * getSigner( void ) const;
		const Bureaucrat * getExecutor( void ) const;

		void doBureaucracy( std::string formType, std::string target );

		class NoInternException : public std::exception {
			public:
				NoInternException( void );
				NoInternException( NoInternException const & e );
				virtual ~NoInternException( void ) throw();
				NoInternException &    operator=( NoInternException const & rhs ) throw() ;
				virtual const char* what() const throw();
		};

		class NoSignerException : public std::exception {
			public:
				NoSignerException( void );
				NoSignerException( NoSignerException const & e );
				virtual ~NoSignerException( void ) throw();
				NoSignerException &    operator=( NoSignerException const & rhs ) throw() ;
				virtual const char* what() const throw();
		};

		class NoExecutorException : public std::exception {
			public:
				NoExecutorException( void );
				NoExecutorException( NoExecutorException const & e );
				virtual ~NoExecutorException( void ) throw();
				NoExecutorException &    operator=( NoExecutorException const & rhs ) throw() ;
				virtual const char* what() const throw();
		};
};

#endif