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
    // Конструктор
    Bank();

    // Створення нового рахунку (номер генерується автоматично)
    // Повертає номер створеного рахунку
    int createAccount(const std::string& ownerName, double initialBalance = 0.0);

    // Пошук рахунку за номером. Повертає вказівник на Account або nullptr, якщо не знайдено
    Account* findAccount(int accountNumber);

    // Вивід усіх рахунків
    void printAllAccounts() const;
};

#endif