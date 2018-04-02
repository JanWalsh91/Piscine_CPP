#ifndef CENTRAL_BUREAUCRACY_H
# define CENTRAL_BUREAUCRACY_H

# include "OfficeBlock.hpp"
# include "Bureaucrat.hpp"

struct TargetList {
	std::string name;
	TargetList* next;
};

class CentralBureaucracy {

	private:
		OfficeBlock		_officeBlocks[20];
		TargetList*		_targetList;

	public:
		CentralBureaucracy( void );
		CentralBureaucracy( CentralBureaucracy const & centralBureaucracy );
		~CentralBureaucracy( void );

		CentralBureaucracy &    operator=( CentralBureaucracy const & rhs );

		void addBureaucrat( Bureaucrat& bureaucrat );
		void queueUp( std::string target );
		void doBureaucracy( void );

		class BureaucratRejectedException : public std::exception {
			public:
				BureaucratRejectedException( void );
				BureaucratRejectedException( BureaucratRejectedException const & e );
				virtual ~BureaucratRejectedException( void ) throw();
				BureaucratRejectedException &    operator=( BureaucratRejectedException const & rhs ) ;
				virtual const char* what() const throw();
		};
};

#endif