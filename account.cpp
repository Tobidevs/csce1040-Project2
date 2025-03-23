#include "account.h"
#include <iostream>
#include <iomanip>

// Initialize static variable
int Account::nextAccountNumber = 1000;

// Default Constructor
Account::Account() : accountNumber(new int(nextAccountNumber++)), customerName(""), balance(0.0) {}

// Parameterized Constructor
Account::Account(const std::string& name, double initialDeposit)
    : accountNumber(new int(nextAccountNumber++)), customerName(name), balance(initialDeposit) {}

// Destructor
Account::~Account() {
    delete accountNumber;
}

// Copy Constructor
Account::Account(const Account& other)
    : accountNumber(new int(*other.accountNumber)), customerName(other.customerName), balance(other.balance) {}

// Copy Assignment Operator
Account& Account::operator=(const Account& other) {
    if (this != &other) {
        *accountNumber = *other.accountNumber;
        customerName = other.customerName;
        balance = other.balance;
    }
    return *this;
}

// Accessors
int Account::getAccountNumber() const {
    return *accountNumber;
}

std::string Account::getCustomerName() const {
    return customerName;
}

double Account::getBalance() const {
    return balance;
}

// Mutators
void Account::setCustomerName(const std::string& name) {
    customerName = name;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
}

// Overloaded Operator
bool Account::operator==(const Account& other) const {
    return *accountNumber == *other.accountNumber;
}

// Static function to get the next account number
int Account::getNextAccountNumber() {
    return nextAccountNumber;
}