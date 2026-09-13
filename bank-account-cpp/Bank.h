#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "Account.h"

class Bank {
private:
    std::vector<Account> accounts;
    int nextAccountNumber;

public:
    Bank();

    int createAccount(const std::string& ownerName, double initialBalance = 0.0); // номер рахунку генерується сам

    Account* findAccount(int accountNumber); // nullptr якщо такого рахунку нема

    bool deposit(int accountNumber, double amount); // true якщо вийшло

    void printAllAccounts() const;
};

#endif