#include <iostream>
#include <string>
#include "Bank.h"
#include <windows.h>

// безпечне зчитування цілого числа - якщо ввели не число, консоль не зациклюється
int readInt(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Це не число, спробуй ще раз: ";
    }
    return value;
}

// те саме, тільки для дробових сум
double readDouble(const std::string& prompt) {
    double value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Це не число, спробуй ще раз: ";
    }
    return value;
}

void printMenu() {
    std::cout << "\n===== БАНКІВСЬКА СИСТЕМА =====" << std::endl;
    std::cout << "1. Створити рахунок" << std::endl;
    std::cout << "2. Поповнити баланс (deposit)" << std::endl;
    std::cout << "3. Зняти кошти (withdraw)" << std::endl;
    std::cout << "4. Переказ між рахунками" << std::endl;
    std::cout << "5. Виписка по рахунку" << std::endl;
    std::cout << "6. Показати всі рахунки" << std::endl;
    std::cout << "0. Вийти" << std::endl;
    std::cout << "Обери дію: ";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Bank bank;
    int choice;
    bool running = true;

    while (running) {
        printMenu();
        choice = readInt("");

        switch (choice) {
        case 1: {
            std::cin.ignore(10000, '\n'); // прибрати залишок Enter після readInt
            std::string name;
            std::cout << "Ім'я власника: ";
            std::getline(std::cin, name);

            if (name.empty()) {
                std::cout << "Ім'я не може бути порожнім." << std::endl;
                break;
            }

            double startBalance = readDouble("Початковий баланс: ");
            if (startBalance < 0) {
                std::cout << "Баланс не може бути від'ємним." << std::endl;
                break;
            }

            int newNumber = bank.createAccount(name, startBalance);
            std::cout << "Створено рахунок #" << newNumber << std::endl;
            break;
        }
        case 2: {
            int accNum = readInt("Номер рахунку: ");
            double amount = readDouble("Сума поповнення: ");

            bank.deposit(accNum, amount);
            break;
        }
        case 3: {
            int accNum = readInt("Номер рахунку: ");
            double amount = readDouble("Сума зняття: ");
            bank.withdraw(accNum, amount);
            break;
        }
        case 4:
            // переказ теж пізніше
            std::cout << "Поки не готово, скоро буде." << std::endl;
            break;
        case 5:
            // виписка теж пізніше
            std::cout << "Поки не готово, скоро буде." << std::endl;
            break;
        case 6:
            bank.printAllAccounts();
            break;
        case 0:
            std::cout << "До побачення!" << std::endl;
            running = false;
            break;
        default:
            std::cout << "Невірний вибір, спробуй ще раз." << std::endl;
            break;
        }
    }

    return 0;
}