#include "project2.h"
#include <iostream>

int main() {
    std::vector<Account> accounts;
    int choice;

    std::cout << "Name: Tobi Akere\n";
    std::cout << "EUID: 11778197\n";
    std::cout << "Email: tobiakere@my.unt.edu\n";
    std::cout << "Department: Computer Science\n";
    std::cout << "Course: CSCE 1040\n";

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                openAccount(accounts);
                break;
            case 2:
                depositToAccount(accounts);
                break;
            case 3:
                withdrawFromAccount(accounts);
                break;
            case 4:
                printAllAccounts(accounts);
                break;
            case 5:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}