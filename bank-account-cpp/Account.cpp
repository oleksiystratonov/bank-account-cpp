#include "Account.h"
#include <iostream>
#include <iomanip>

Account::Account(int number, const std::string& owner, double initialBalance)
    : accountNumber(number), ownerName(owner), balance(initialBalance) {
}

int Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getOwnerName() const {
    return ownerName;
}

double Account::getBalance() const {
    return balance;
}

void Account::setBalance(double newBalance) {
    balance = newBalance;
}

void Account::printInfo() const {
    std::cout << "Рахунок #" << accountNumber
        << " | Власник: " << ownerName
        << " | Баланс: " << std::fixed << std::setprecision(2)
        << balance << " грн" << std::endl;
}