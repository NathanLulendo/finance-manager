#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
private:
    double amount;
    std::string type; // "income" or "expense"
    std::string category;
    std::string date;

public:
    // Constructor
    Transaction(double amt, std::string t, std::string cat, std::string d);

    // Getter functions
    double getAmount() const;
    std::string getType() const;
    std::string getCategory() const;
    std::string getDate() const;

    // Display function to print transaction details
    void displayTransaction() const;
};

#endif
