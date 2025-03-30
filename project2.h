#ifndef PROJECT2_H
#define PROJECT2_H

#include "account.h"
#include <vector>


void displayMenu();
void openAccount(std::vector<Account>& accounts);
void depositToAccount(std::vector<Account>& accounts);
void withdrawFromAccount(std::vector<Account>& accounts);
void printAllAccounts(const std::vector<Account>& accounts);

#endif