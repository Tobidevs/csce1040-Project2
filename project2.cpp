#include "project2.h"
#include <iostream>
#include <iomanip>


void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Open new account\n";
    std::cout << "2. Deposit into account\n";
    std::cout << "3. Withdraw from account\n";
    std::cout << "4. Print a list of all accounts\n";
    std::cout << "5. End transaction (Exit)\n";
    std::cout << "Enter your choice: ";
}

// open a new account
void openAccount(std::vector<Account>& accounts) {
    std::string name;
    double initialDeposit;

    std::cout << "Enter customer name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter initial deposit amount: $";
    std::cin >> initialDeposit;

    Account newAccount(name, initialDeposit);
    accounts.push_back(newAccount);

    std::cout << "Account created successfully!\n";
    std::cout << "Account Number: " << newAccount.getAccountNumber() << "\n";
    std::cout << "Customer Name: " << newAccount.getCustomerName() << "\n";
    std::cout << "Initial Balance: $" << std::fixed << std::setprecision(2) << newAccount.getBalance() << "\n";
}

// deposit into an account
void depositToAccount(std::vector<Account>& accounts) {
    int accountNumber;
    double amount;

    std::cout << "Enter account number: ";
    std::cin >> accountNumber;

    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            std::cout << "Enter deposit amount: $";
            std::cin >> amount;
            account.deposit(amount);
            std::cout << "Deposit successful!\n";
            std::cout << "Updated Balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << "\n";
            return;
        }
    }
    std::cout << "Account not found!\n";
}

// withdraw from an account
void withdrawFromAccount(std::vector<Account>& accounts) {
    int accountNumber;
    double amount;

    std::cout << "Enter account number: ";
    std::cin >> accountNumber;

    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            std::cout << "Enter withdrawal amount: $";
            std::cin >> amount;
            if (amount > account.getBalance()) {
                std::cout << "Insufficient funds!\n";
            } else {
                account.withdraw(amount);
                std::cout << "Withdrawal successful!\n";
                std::cout << "Updated Balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << "\n";
            }
            return;
        }
    }
    std::cout << "Account not found!\n";
}

// print all accounts
void printAllAccounts(const std::vector<Account>& accounts) {
    if (accounts.empty()) {
        std::cout << "No accounts found!\n";
        return;
    }

    std::cout << "\nList of all accounts:\n";
    for (const auto& account : accounts) {
        std::cout << "Account Number: " << account.getAccountNumber() << "\n";
        std::cout << "Customer Name: " << account.getCustomerName() << "\n";
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << "\n\n";
    }
}