#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) 
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	++_nbAccounts;
	_totalAmount += initial_deposit;
    Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";amount:" << _amount 
		<< ";created" << std::endl;
}

Account::~Account() {
   	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";amount:" << _amount 
		<< ";closed" << std::endl;
}

void	Account::displayStatus(void) const {
    Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";amount:" << _amount 
        << ";deposits:" << _nbDeposits 
        << ";withdrawals:" << _nbWithdrawals 
        << std::endl;
}

void	Account::makeDeposit(int deposit) {
	int	p_amount = _amount;
	_amount += deposit;
    ++_nbDeposits;
    _totalAmount += deposit;
    ++_totalNbDeposits;
    Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

void	Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
	std::cout << "accounts:"
		<< _nbAccounts << ";total:" 
		<< _totalAmount << ";deposits:" 
		<< _totalNbDeposits << ";withdrawals:"
		<< _totalNbWithdrawals << std::endl;
}

int 	Account::checkAmount(void) const {
	return this->_amount;
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (withdrawal > _amount) {
    	Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:"
			<< "refused" << std::endl;
        return false;
    }
	int p_amount = _amount;
   	Account::_displayTimestamp();
    _amount -= withdrawal;
    ++_nbWithdrawals;
    _totalAmount -= withdrawal;
    ++_totalNbWithdrawals;
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" <<_nbWithdrawals
			<< std::endl;
    return true;
}

void	Account::_displayTimestamp(void) {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", &tstruct);
    std::cout << buf << " ";
}

int		Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int		Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int		Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}
