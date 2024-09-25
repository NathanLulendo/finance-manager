#include "..\include\FinanceManager.h"
#include <iostream>

int main()
{
    FinanceManager fm;
    int choice;
    std::string filename = "data/transac.csv"; // File to save/load transactions

    // Load transactions from file at the start
    fm.loadTransactions(filename);

    do
    {
        std::cout << "\nPersonal Finance Manager\n";
        std::cout << "1. Add Income or Expense\n";
        std::cout << "2. View Transaction History\n";
        std::cout << "3. Set Budget\n";
        std::cout << "4. Check Budget Status\n";
        std::cout << "5. Save Transactions\n";
        std::cout << "6. Load Transactions\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            double amount;
            std::string type, category, date;
            std::cout << "Enter amount: ";
            std::cin >> amount;
            std::cout << "Enter type (income/expense): ";
            std::cin >> type;
            std::cout << "Enter category: ";
            std::cin >> category;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::cin >> date;
            fm.addTransaction(amount, type, category, date);
            break;
        }
        case 2:
            fm.viewHistory();
            break;
        case 3:
        {
            double budget;
            std::cout << "Enter budget: ";
            std::cin >> budget;
            fm.setBudget(budget);
            break;
        }
        case 4:
            fm.checkBudget();
            break;
        case 5:
            fm.saveTransactions(filename);
            break;
        case 6:
            fm.loadTransactions(filename);
            break;
        case 7:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
