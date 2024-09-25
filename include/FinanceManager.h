#ifndef FINANCE_MANAGER_H
#define FINANCE_MANAGER_H

#include "Transaction.h"
#include <vector>

class FinanceManager
{
private:
    std::vector<Transaction> transactions; // Store all transactions
    double budget;

public:
    FinanceManager(); // Constructor

    // Add a transaction to the list
    void addTransaction(double amount, std::string type, std::string category, std::string date);

    // Set the budget
    void setBudget(double b);

    // View all transactions
    void viewHistory() const;

    // Check if expenses exceed the budget
    void checkBudget() const;

    // Save transactions to a file
    void saveTransactions(const std::string &filename);

    // Load transactions from a file
    void loadTransactions(const std::string &filename);
};

#endif
