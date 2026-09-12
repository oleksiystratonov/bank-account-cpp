#include "Bank.h"
#include <iostream>

Bank::Bank() : nextAccountNumber(1001) {
}

int Bank::createAccount(const std::string& ownerName, double initialBalance) {
    int newNumber = nextAccountNumber;
    accounts.push_back(Account(newNumber, ownerName, initialBalance));
    nextAccountNumber++;
    return newNumber;
}

Account* Bank::findAccount(int accountNumber) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            return &acc;
        }
    }
    return nullptr;
}

void Bank::printAllAccounts() const {
    if (accounts.empty()) {
        std::cout << "Рахунків ще немає." << std::endl;
        return;
    }
    for (const auto& acc : accounts) {
        acc.printInfo();
    }
}