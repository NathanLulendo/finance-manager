#include "..\include\FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Save transactions to a file (CSV format)
void FileManager::saveToFile(const std::vector<Transaction> &transactions, const std::string &filename)
{
    std::ofstream outFile(filename);

    if (!outFile)
    {
        std::cerr << "Error opening file for saving: " << filename << std::endl;
        return;
    }

    // Write header
    outFile << "amount,type,category,date\n";

    // Write each transaction
    for (const auto &transaction : transactions)
    {
        outFile << transaction.getAmount() << ","
                << transaction.getType() << ","
                << transaction.getCategory() << ","
                << transaction.getDate() << "\n";
    }

    outFile.close();
    std::cout << "Transactions saved to " << filename << std::endl;
}

// Load transactions from a file (CSV format)
std::vector<Transaction> FileManager::loadFromFile(const std::string &filename)
{
    std::ifstream inFile(filename);
    std::vector<Transaction> transactions;

    if (!inFile)
    {
        std::cerr << "Error opening file for loading: " << filename << std::endl;
        return transactions; // Return an empty list if the file doesn't exist
    }

    std::string line;
    // Skip the header
    std::getline(inFile, line);

    // Read each line (each transaction)
    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        std::string amountStr, type, category, date;

        // Parse CSV fields
        std::getline(ss, amountStr, ',');
        std::getline(ss, type, ',');
        std::getline(ss, category, ',');
        std::getline(ss, date, ',');

        // Convert amount string to double
        double amount = std::stod(amountStr);

        // Create a Transaction object and add it to the list
        transactions.push_back(Transaction(amount, type, category, date));
    }

    inFile.close();
    std::cout << "Transactions loaded from " << filename << std::endl;

    return transactions;
}
