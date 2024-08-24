#include "Trust_Account.h"

bool Trust_Account::deposit(double amount)
{
    if(amount>=5000)
        amount+=50;
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
    if((amount>(percentage_fac*(this->balance))) || withdrawal_limit>2)
        return false;
    else
    {
        withdrawal_limit++;
        return Savings_Account::withdraw(amount);
    }
}
std::ostream &operator<<(std::ostream &os, const Trust_Account &account)
{
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}
