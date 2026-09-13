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
        case 2: {
            int accNum;
            double amount;
            std::cout << "Номер рахунку: ";
            std::cin >> accNum;
            std::cout << "Сума поповнення: ";
            std::cin >> amount;

            bank.deposit(accNum, amount);
            break;
        }
        case 3:
            // withdraw ще не готовий, буде наступним спринтом
            std::cout << "Поки не готово, скоро буде." << std::endl;
            break;
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