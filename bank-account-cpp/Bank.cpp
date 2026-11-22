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

bool Bank::deposit(int accountNumber, double amount) {
    if (amount <= 0) {
        std::cout << "Помилка: сума поповнення має бути більшою за 0." << std::endl;
        return false;
    }

    Account* acc = findAccount(accountNumber);
    if (acc == nullptr) {
        std::cout << "Помилка: рахунок #" << accountNumber << " не знайдено." << std::endl;
        return false;
    }

    acc->setBalance(acc->getBalance() + amount);
    std::cout << "Баланс поповнено. Новий баланс: " << acc->getBalance() << " грн" << std::endl;
    return true;
}
bool Bank::withdraw(int accountNumber, double amount) {
    if (amount <= 0) {
        std::cout << "Помилка: сума має бути більшою за 0." << std::endl;
        return false;
    }
    Account* acc = findAccount(accountNumber);
    if (acc == nullptr) {
        std::cout << "Помилка: рахунок #" << accountNumber << " не знайдено." << std::endl;
        return false;
    }
    if (acc->getBalance() < amount) {
        std::cout << "Помилка: недостатньо коштів." << std::endl;
        return false;
    }
    acc->setBalance(acc->getBalance() - amount);
    std::cout << "Кошти знято. Новий баланс: " << acc->getBalance() << " грн" << std::endl;
    return true;
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