#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    int accountNumber;
    std::string ownerName;
    double balance;

public:
    Account(int number, const std::string& owner, double initialBalance = 0.0);

    // геттери
    int getAccountNumber() const;
    std::string getOwnerName() const;
    double getBalance() const;

    void setBalance(double newBalance); // баланс міняється тільки через Bank

    void printInfo() const; // вивести дані рахунку в консоль
};

#endif