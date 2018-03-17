#include "Account.class.hpp"

#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {

	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "amount:"
		<< this->_amount
		<< ";"
		<< "created"
		<< std::endl;

	return ;
};

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "amount:"
		<< this->_amount
		<< ";"
		<< "closed";
	
	if (this->_accountIndex != 0) {
		std::cout << std::endl;
	}
	return ;
};

int	Account::getNbAccounts( void ){
	return Account::_nbAccounts;
};

int	Account::getTotalAmount( void ){
	return Account::_totalAmount;
};

int	Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
};

int	Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
};

void	Account::displayAccountsInfos( void ){
	//accounts:8;total:20049;deposits:0;withdrawals:0
	Account::_displayTimestamp();
	std::cout << "accounts:"
		<< Account::getNbAccounts()
		<< ";"
		<< "total:"
		<< Account::getTotalAmount()
		<< ";"
		<< "deposits:"
		<< Account::getNbDeposits()
		<< ";"
		<< "withdrawals:"
		<< Account::getNbWithdrawals()
		<< std::endl;
};

void Account::makeDeposit( int deposit ) {

	Account::_displayTimestamp();
	//index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	std::cout << "index:"
		<< this->_accountIndex
		<< ";"
		<< "p_amount:"
		<< this->_amount
		<< ";"
		<< "deposit:"
		<< deposit
		<< ";";

	++this->_nbDeposits;
	++Account::_totalNbDeposits;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	
	std::cout
		<< "amount:"
		<< this->_amount
		<< ";"	
		<< "nb_deposits:"
		<< this->_nbDeposits
		<< std::endl;

};

bool Account::makeWithdrawal( int withdrawal ) {

	Account::_displayTimestamp();
	//index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
	//index:5;p_amount:23;withdrawal:refused
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "p_amount:"
		<< this->_amount
		<< ";"
		<< "withdrawal:";

	if (this->_amount >= withdrawal) {
		++this->_nbWithdrawals;
		++Account::_totalNbWithdrawals;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		
		std::cout
			<< withdrawal
			<< ";"
			<< "amount:"
			<< this->_amount
			<< ";"	
			<< "nb_withdrawals:"
			<< this->_nbWithdrawals
			<< std::endl;
	}
	else {
		std::cout << "refused" << std::endl;
	}
	

	return true;
};

int	Account::checkAmount( void ) const {
	return this->_amount;
};

void	Account::displayStatus( void ) const {
	//index:7;amount:8942;deposits:1;withdrawals:1
	Account::_displayTimestamp();
	std::cout << "index:"
		<< this->_accountIndex
		<< ";"
		<< "amount:"
		<< this->_amount
		<< ";"
		<< "deposits:"
		<< this->_nbDeposits
		<< ";"
		<< "withdrawals:"
		<< this->_nbWithdrawals
		<< std::endl;
};

void Account::_displayTimestamp( void ) {
	//[20150406_153629]
	// std::cout << "[20150406_153629] ";
	// return ;
	time_t t = time(0);
    struct tm * now = localtime( & t );
    std::cout 
		<< "["
		<< (now->tm_year + 1900)
		<< (now->tm_mon + 1 < 10 ? "0" : "")
        << (now->tm_mon + 1)
		<< now->tm_mday
		<< "_"
		<< now->tm_hour
		<< now->tm_min
		<< now->tm_sec
		<< "] ";
};