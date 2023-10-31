/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:07:02 by frmurcia          #+#    #+#             */
/*   Updated: 2023/10/07 11:08:33 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp(void)
{
    time_t ActualTime = time(NULL);
    struct tm *LocalTime = localtime(&ActualTime);
    std::cout << "[" << LocalTime->tm_year + 1900 << LocalTime->tm_mon << LocalTime->tm_mday << "_"
    << LocalTime->tm_hour << LocalTime->tm_min << LocalTime->tm_sec << "] ";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	_totalAmount = _totalAmount + initial_deposit;
	std::cout <<"index:" <<_accountIndex << ";";
	std::cout <<"amount:" <<_amount << ";created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout <<"index:" <<_accountIndex << ";";
	std::cout <<"amount:" <<_amount << ";closed\n";
}

int		Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout <<"accounts:" <<_nbAccounts <<";total:" <<_totalAmount;
	std::cout <<";deposits:" <<_totalNbDeposits <<";withdrawals:" <<_totalNbWithdrawals <<"\n";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout <<"index:" <<_accountIndex <<";p_amount:" <<_amount;
	std::cout <<";deposit:" <<deposit <<";amount:" <<_amount + deposit;
	std::cout <<";nb_deposits:" <<++_nbDeposits << "\n";
	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
	_totalNbDeposits = _totalNbDeposits + 1;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout <<"index:" <<_accountIndex <<";p_amount:" <<_amount;
	if (_amount > withdrawal)
	{
		std::cout <<";withdrawal:" <<withdrawal <<";amount:" <<_amount - withdrawal;
		std::cout <<";nb_withdrawals:" <<++_nbWithdrawals << "\n";
		_amount = _amount - withdrawal;
		_totalAmount = _totalAmount - withdrawal;
		_totalNbWithdrawals = _totalNbWithdrawals + 1;
		return (true);
	}
	else
	{
		std::cout << ";withdrawal:refused\n";
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return(_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout <<"index:" <<_accountIndex <<";amount:" <<_amount;
	std::cout <<";deposits:" <<_nbDeposits;
	std::cout <<";withdrawals:" <<_nbWithdrawals << "\n";
}













