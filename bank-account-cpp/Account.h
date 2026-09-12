#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    int accountNumber;
    std::string ownerName;
    double balance;

public:
    // Конструктор
    Account(int number, const std::string& owner, double initialBalance = 0.0);

    // Геттери
    int getAccountNumber() const;
    std::string getOwnerName() const;
    double getBalance() const;

    // Зміна балансу (використовується класом Bank при deposit/withdraw)
    void setBalance(double newBalance);

    // Вивід інформації про рахунок
    void printInfo() const;
};

#endif#pragma once
