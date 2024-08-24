#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#include "../Savings_Account.h"


class Trust_Account : public Savings_Account
{
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
protected:
    const double bonus=50.0;
    const double percentage_fac=0.2;
    int withdrawal_limit=0;

public:
    bool deposit(double amount);
    bool withdraw(double amount);
    using Savings_Account::Savings_Account;
};

#endif // TRUST_ACCOUNT_H
