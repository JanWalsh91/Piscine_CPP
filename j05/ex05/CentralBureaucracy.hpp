#ifndef CENTRAL_BUREAUCRACY_H
# define CENTRAL_BUREAUCRACY_H

# include "OfficeBlock.hpp"
# include "Bureaucrat.hpp"

# include <exception>
# include <string>

struct TargetList {
	std::string name;
	TargetList* next;
};

class CentralBureaucracy {

	private:
		OfficeBlock*	_officeBlocks[20];
		TargetList*		_targetList;

	public:
		CentralBureaucracy( void );
		CentralBureaucracy( CentralBureaucracy const & centralBureaucracy );
		~CentralBureaucracy( void );

		CentralBureaucracy &    operator=( CentralBureaucracy const & rhs );


		const OfficeBlock* getOfficeBlock( int i ) const;
		void addBureaucrat( Bureaucrat& bureaucrat );
		void queueUp( std::string target );
		void doBureaucracy( void );

		class BureaucratRejectedException : public std::exception {
			virtual const char* what() const throw();
		};



};

#endif