#include "Checking.h"
bool Checking::withdraw(double amount)
{
	return Account::withdraw(amount + withdrawal_fee);
}
std::ostream& operator<<(std::ostream& os, const Checking& account)
{
	os << "[Checking Account: "<<account.name<<": "<<account.balance<<" ]";
	return os;
}

//overloading += for deposit;
bool Checking::operator+=(double amount)
{
    return Account::deposit(amount);
}

//overloading -= for withdraw
bool Checking::operator-=(double amount)
{
    return Checking::withdraw(amount);
}
