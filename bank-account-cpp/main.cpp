#include <iostream>
#include <string>
#include "Bank.h"
#include <windows.h>

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
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cin.ignore();
            std::string name;
            double startBalance;
            std::cout << "Ім'я власника: ";
            std::getline(std::cin, name);
            std::cout << "Початковий баланс: ";
            std::cin >> startBalance;

            int newNumber = bank.createAccount(name, startBalance);
            std::cout << "Створено рахунок #" << newNumber << std::endl;
            break;
        }
        case 2:
            // TODO: реалізується в картці "Deposit"
            std::cout << "Ще не реалізовано (картка Deposit)." << std::endl;
            break;
        case 3:
            // TODO: реалізується в картці "Withdraw"
            std::cout << "Ще не реалізовано (картка Withdraw)." << std::endl;
            break;
        case 4:
            // TODO: реалізується в картці "Переказ між рахунками"
            std::cout << "Ще не реалізовано (картка Переказ)." << std::endl;
            break;
        case 5:
            // TODO: реалізується в картці "Виписка по рахунку"
            std::cout << "Ще не реалізовано (картка Виписка)." << std::endl;
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