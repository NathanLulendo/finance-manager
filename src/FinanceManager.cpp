#include "..\include\FinanceManager.h"
#include "..\include\FileManager.h"
#include <iostream>

FinanceManager::FinanceManager() : budget(0) {}

// Add a new transaction
void FinanceManager::addTransaction(double amount, std::string type, std::string category, std::string date)
{
    Transaction newTransaction(amount, type, category, date);
    transactions.push_back(newTransaction);
}

// Set the budget
void FinanceManager::setBudget(double b)
{
    budget = b;
    std::cout << "Budget set to: $" << budget << std::endl;
}

// View all transactions
void FinanceManager::viewHistory() const
{
    std::cout << "Transaction History:\n";
    for (const auto &transaction : transactions)
    {
        transaction.displayTransaction();
    }
}

// Check if expenses exceed the budget
void FinanceManager::checkBudget() const
{
    double totalExpenses = 0;
    for (const auto &transaction : transactions)
    {
        if (transaction.getType() == "expense")
        {
            totalExpenses += transaction.getAmount();
        }
    }

    if (totalExpenses > budget)
    {
        std::cout << "Warning: You have exceeded your budget by $"
                  << totalExpenses - budget << std::endl;
    }
    else
    {
        std::cout << "You are within your budget.\n";
    }
}

// Save transactions to a file
void FinanceManager::saveTransactions(const std::string &filename)
{
    FileManager::saveToFile(transactions, filename);
}

// Load transactions from a file
void FinanceManager::loadTransactions(const std::string &filename)
{
    transactions = FileManager::loadFromFile(filename);
}
