#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Transaction.h"
#include <vector>
#include <string>

class FileManager
{
public:
    // Save transactions to a file
    static void saveToFile(const std::vector<Transaction> &transactions, const std::string &filename);

    // Load transactions from a file
    static std::vector<Transaction> loadFromFile(const std::string &filename);
};

#endif
