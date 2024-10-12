/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:27:42 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/12 11:03:26 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor -> Initializes a new account with an initial deposit
// Updates the total number of accounts and total amount across all accounts
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

// Destructor
Account::~Account() {
   	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";amount:" << _amount 
		<< ";closed" << std::endl;
}

// Display the current status of an individual account
void	Account::displayStatus(void) const {
    Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";amount:" << _amount 
        << ";deposits:" << _nbDeposits 
        << ";withdrawals:" << _nbWithdrawals 
        << std::endl;
}

// Process a deposit to the account
// Updates the account balance, deposit count, and the total deposit statistics
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

// Display the status of all accounts
void	Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
	std::cout << "accounts:"
		<< _nbAccounts << ";total:" 
		<< _totalAmount << ";deposits:" 
		<< _totalNbDeposits << ";withdrawals:"
		<< _totalNbWithdrawals << std::endl;
}

// Return the current amount in the account
// This is a helper method to check the account balance
// 'this' is used to access variables inside a class
int 	Account::checkAmount(void) const {
	return this->_amount;
}

// Process a withdrawal from the account
bool	Account::makeWithdrawal(int withdrawal) {
// If the withdrawal amount exceeds the current balance, the transaction is refused
	if (withdrawal > _amount) {
    	Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:"
			<< "refused" << std::endl;
        return false;
    }
// Otherwise, the withdrawal is processed, updating the balance, withdrawal count, and total statistics
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

// Display the current timestamp in a specific format
void	Account::_displayTimestamp(void) {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
// size_t strftime(char *res, size_t capacity, const char *format, const struct *time&date_info);
    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", &tstruct);
    std::cout << buf << " ";
}

// Return the total number of accounts
int		Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

// Return the total amount across all accounts
int		Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

// Return the total number of deposits across all accounts
int		Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

// Return the total number of withdrawals across all accounts
int		Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}
