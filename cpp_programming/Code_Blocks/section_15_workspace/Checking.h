#ifndef _CHECKING_H_
#define _CHECKING_H_

#include "Account.h"
class Checking :
    public Account
{
friend std::ostream& operator<<(std::ostream& os, const Checking& account);
    using Account::Account;
protected:
    double const withdrawal_fee=1.50;
public:
    bool withdraw(double amount);
    bool operator+=(double amount);
    bool operator-=(double amount);
};
#endif //_CHECKING_H_
