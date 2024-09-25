#include "..\include\Transaction.h"
#include <iostream>

// Constructor implementation
Transaction::Transaction(double amt, std::string t, std::string cat, std::string d)
    : amount(amt), type(t), category(cat), date(d) {}

// Getter function implementations
double Transaction::getAmount() const { return amount; }
std::string Transaction::getType() const { return type; }
std::string Transaction::getCategory() const { return category; }
std::string Transaction::getDate() const { return date; }

// Function to display transaction details
void Transaction::displayTransaction() const
{
    std::cout << "Type: " << type << ", Amount: " << amount
              << ", Category: " << category << ", Date: " << date << std::endl;
}
